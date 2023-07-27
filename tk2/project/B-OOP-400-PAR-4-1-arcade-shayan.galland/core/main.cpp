#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <dlfcn.h>
#include <thread>

#include "../graphics/IGraphics.hpp"
#include "../games/IGame.hpp"




typedef IGraphics* (*CreateGraphicsFunc)(const std::string&);


void switchToNextLibrary(IGraphics*& currentGraphics, size_t& currentLibraryIndex, const std::vector<std::string>& availableLibraries, CreateGraphicsFunc createGraphics, std::string name) {    // Unload the current library
    currentGraphics->close();
    delete currentGraphics;

    // Load the next library in the list
    currentLibraryIndex = (currentLibraryIndex + 1) % availableLibraries.size();
    currentGraphics = createGraphics(availableLibraries[currentLibraryIndex]);

    // Initialize the new library
    currentGraphics->init();


    currentGraphics->setName(name);
}

void switchToPreviousLibrary(IGraphics*& currentGraphics, size_t& currentLibraryIndex, const std::vector<std::string>& availableLibraries, CreateGraphicsFunc createGraphics, std::string name) {    // Unload the current library
    currentGraphics->close();
    delete currentGraphics;

    // Load the previous library in the list
    currentLibraryIndex = (currentLibraryIndex + availableLibraries.size() - 1) % availableLibraries.size();
    currentGraphics = createGraphics(availableLibraries[currentLibraryIndex]);
    // Initialize the new library
    currentGraphics->init();

    currentGraphics->setName(name);

}


// Function to load available graphics libraries
std::vector<std::string> loadAvailableLibraries() {
    std::vector<std::string> libraries = {
        "./lib/arcade_ncurses.so",
        "./lib/arcade_sdl2.so",
        "./lib/arcade_SFML.so" // Change this to match the actual file name
    };
    return libraries;
}

// Function to create a graphics object from a library
IGraphics* createGraphics(const std::string& libraryPath) {
    void* graphics_handle = dlopen(libraryPath.c_str(), RTLD_NOW);

    if (!graphics_handle) {
        std::cerr << "Error loading graphics library: " << dlerror() << std::endl;
        exit(1);
    }

    IGraphics* (*create)();

    std::string createFunctionName = "create_" + libraryPath.substr(libraryPath.find_last_of('/') + 1);
    createFunctionName = createFunctionName.substr(0, createFunctionName.find_last_of('.'));
    create = (IGraphics* (*)())dlsym(graphics_handle, createFunctionName.c_str());

    if (!create) {
        std::cerr << "Error loading " << createFunctionName << " function: " << dlerror() << std::endl;
        exit(1);
    }

    return create();
}


void display_mods(IGraphics *currentGraphics)
{
    if (currentGraphics->isLib() == 1) {
        currentGraphics->drawText(20, 100, "Ncurse", "green", 34);
        currentGraphics->drawText(20, 170, "SDL2", "red", 34);
        currentGraphics->drawText(20, 240, "SFML", "red", 34);
    }
    if (currentGraphics->isLib() == 2) {
        currentGraphics->drawText(20, 100, "Ncurse", "red", 34);
        currentGraphics->drawText(20, 170, "SDL2", "green", 34);
        currentGraphics->drawText(20, 240, "SFML", "red", 34);
    }
    if (currentGraphics->isLib() == 3) {
        currentGraphics->drawText(20, 100, "Ncurse", "red", 34);
        currentGraphics->drawText(20, 170, "SDL2", "red", 34);
        currentGraphics->drawText(20, 240, "SFML", "green", 34);
    }
    currentGraphics->drawText(1270, 20, "Controls :", "red", 40);
    currentGraphics->drawText(1270, 100, "Press Escape to quit", "red", 20);
    currentGraphics->drawText(1270, 170, "Press right arrow to go to the", "red", 20);
    currentGraphics->drawText(1270, 240, "next lib and left to go to the", "red", 20);
    currentGraphics->drawText(1270, 310, "previous one", "red", 20);
    currentGraphics->drawText(1270, 380, "Press BackSpace to change your", "red", 20);
    currentGraphics->drawText(1270, 450, "name and Enter to confirm it", "red", 20);
    currentGraphics->drawText(1270, 520, "Press the z key to go up, s to", "red", 20);
    currentGraphics->drawText(1270, 590, "go down, q to go left and d to", "red", 20);
    currentGraphics->drawText(1270, 660, "go right and Space to restart the", "red", 20);
    currentGraphics->drawText(1270, 730, "game and down arrow to pause", "red", 20);
    currentGraphics->drawText(1270, 790, "Press up to play the next game", "red", 20);


}

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Usage: ./arcade <path_to_graphics_library>" << std::endl;
        return 84;
    }

    std::string initialLibraryPath(argv[1]);
    std::vector<std::string> availableLibraries = loadAvailableLibraries();
    size_t currentLibraryIndex = std::find(availableLibraries.begin(), availableLibraries.end(), initialLibraryPath) - availableLibraries.begin();

    if (currentLibraryIndex >= availableLibraries.size()) {
        std::cerr << "Invalid graphics library specified." << std::endl;
        return 84;
    }

    IGraphics* currentGraphics = createGraphics(availableLibraries[currentLibraryIndex]);




    //load game libs
    void* game_handle_snake = dlopen("./lib/arcade_snake.so", RTLD_NOW | RTLD_GLOBAL);
    auto createSnakeGame = reinterpret_cast<IGame*(*)()>(dlsym(game_handle_snake, "createSnakeGame"));
    if (createSnakeGame == nullptr) {
        std::cerr << "Failed to get createGame function: " << dlerror() << std::endl;
        return 84;
    }
    IGame* game = createSnakeGame();

    void* game_handle_nibbler = dlopen("./lib/arcade_nibbler.so", RTLD_NOW | RTLD_GLOBAL);
    auto createNibblerGame = reinterpret_cast<IGame*(*)()>(dlsym(game_handle_nibbler, "createNibblerGame"));
    if (createNibblerGame == nullptr) {
        std::cerr << "Failed to get createGame function: " << dlerror() << std::endl;
        return 84;
    }
    IGame* game0 = createNibblerGame();

    
    //init game loop
    std::string imagePath = "extern/background/background.jpeg";
    currentGraphics->init();
    game->init(); //snake game
    game0->init(); //nibbler game

    auto currentGame = game;

    bool snakeGame = true;
    bool enterName = false;
    bool running = true;

    constexpr std::chrono::milliseconds frameDuration(10); // curently 100 FPS

    while (running) {
        auto frameStart = std::chrono::steady_clock::now();
        
        int event = currentGraphics->handleEvents();




        if (event == 1) { // Up arrow key is pressed change games
            snakeGame = !snakeGame;
            if (snakeGame) {
                currentGame = game;
                currentGame->init();
            }
            else {
                currentGame = game0;
                currentGame->init();
            }
        } else if (event == 21) { // escape quit
            running = false;
        } else if (event == 3) { // Right arrow key is pressed
            switchToNextLibrary(currentGraphics, currentLibraryIndex, availableLibraries, createGraphics, currentGraphics->getName());
        } else if (event == 4) { // Left arrow key is pressed
            switchToPreviousLibrary(currentGraphics, currentLibraryIndex, availableLibraries, createGraphics, currentGraphics->getName());
        } else if (event == 5) { // delete is pressed reset name
            currentGraphics->setName("");
            enterName = true;
        } else if (event == 6) { // enter is pressed end of reset name
            enterName = false; //finished to enter name
        } else if (event == 20) { //space is pressed restart game
            if (currentGame->isGameOver()) {
                std::string playerName = currentGraphics->getName(); // Replace with the player's name
                currentGame->updateHighScores(playerName, currentGame->getScore());
                currentGame->saveHighScores(); // Save the high scores to the file
            }
            currentGame->init();

        }


        currentGame->handleEvent(event);

        if (enterName == true) {
            currentGraphics->initName();
        }

        currentGraphics->clear(); // contain ::clear();


        currentGraphics->drawImage(imagePath, 0, 0, 1.0f, 1.0f);


        currentGame->update(*currentGraphics);
        currentGame->render(*currentGraphics);


        display_mods(currentGraphics);




        currentGraphics->drawText(20, 20, "Player: " + currentGraphics->getName(), "blue", 24);
        currentGraphics->updateDisplay(); // contain refrech()


        //frame rate options
        auto frameEnd = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart);
        if (elapsed < frameDuration) {
            std::this_thread::sleep_for(frameDuration - elapsed);
        }
    }

    
    dlclose(game_handle_snake);
    dlclose(game_handle_nibbler);
    delete currentGame;
    delete game;
    delete game0;
    delete currentGraphics;

    return 0;
}
