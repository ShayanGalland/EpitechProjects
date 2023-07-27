#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include<algorithm>
#include "nibbler.hpp"

extern "C" IGame* createNibblerGame() {
    return new NibblerGame();
}

NibblerGame::NibblerGame() {
    level = 1;

    srand(time(NULL));
}

void NibblerGame::init() {
    level = 1;


    boardSize = 30;
    cellSize = 20;
    offsetX = 0;
    offsetY = 0;
    levelDuration = std::chrono::seconds(30);
    startTime = std::chrono::steady_clock::now();

    gameOver = false;
    score = 0;
    snake.clear();
    snake.push_back({15, 15});
    snake.push_back({14, 15});
    snake.push_back({13, 15});
    snake.push_back({12, 15});
    direction = 3;
    buildMaze();
    spawnPresetFruits();
    lastUpdateTime = std::chrono::steady_clock::now();
    updateInterval = std::chrono::milliseconds(100);

    loadHighScores();
}

void NibblerGame::update(IGraphics& graphics) {
    if (gameOver) return;

    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastUpdateTime);

    if (elapsedTime >= updateInterval) {
        moveSnake();

        if (hasCollided()) {
            gameOver = true;
            level = 1;
            return;
        }

        checkFruitCollision();

        lastUpdateTime = currentTime;
    }

    auto timeElapsedSinceStart = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
    if (timeElapsedSinceStart >= levelDuration) {
        gameOver = true;
    }

    if (gameOver) {
            std::string playerName = graphics.getName(); // Replace with the player's name
            updateHighScores(playerName, score);
            saveHighScores(); // Save the high scores to the file
    }
}

void NibblerGame::render(IGraphics& graphics) {
    offsetX = (graphics.getWindowWidth() - (boardSize * cellSize)) / 2;
    offsetY = (graphics.getWindowHeight() - (boardSize * cellSize)) / 2;
    graphics.drawRect(offsetX, offsetY, boardSize * cellSize, boardSize * cellSize, "brown");

    for (const auto& part : snake) {
        graphics.drawRect(offsetX + part.first * cellSize, offsetY + part.second * cellSize, cellSize, cellSize, "blue");
    }

    for (const auto& fruit : fruits) {
        graphics.drawRect(offsetX + fruit.first * cellSize, offsetY + fruit.second * cellSize, cellSize, cellSize, "red");
    }

    for (int y = 0; y < boardSize; ++y) {
        for (int x = 0; x < boardSize; ++x) {
            if (maze[y][x]) {
                graphics.drawRect(offsetX + x * cellSize, offsetY + y * cellSize, cellSize, cellSize, "blue");
            }
        }
    }

    graphics.drawText(550, 20, "Score: " + std::to_string(score), "blue", 24);
    graphics.drawText(800, 20, "Level: " + std::to_string(level), "blue", 24);

    auto currentTime = std::chrono::steady_clock::now();
    auto timeElapsedSinceStart = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
    int remainingTime = std::max(0, static_cast<int>(levelDuration.count() - timeElapsedSinceStart.count()));
    graphics.drawText(1050, 20, "Time: " + std::to_string(remainingTime), "blue", 24);

    renderHighScores(graphics); // Add this line
}

bool NibblerGame::isGameOver() {
    return gameOver;
}

void NibblerGame::moveSnake() {
    std::pair<int, int> newHead = snake.front();
    switch (direction) {
    case 0:
        newHead.second--;
        break;
    case 1:
        newHead.second++;
        break;
    case 2:
        newHead.first--;
        break;
    case 3:
        newHead.first++;
        break;
    }

    if (isWall(newHead.first, newHead.second)) {
        int newDirection = (direction + 1) % 4;
        if (isWall(newHead.first + newDirection, newHead.second)) {
            newDirection = (direction + 3) % 4;
        }
        direction = newDirection;
    } else {
        snake.insert(snake.begin(), newHead);
        snake.pop_back();
    }
}


bool NibblerGame::hasCollided() {
    const auto& head = snake.front();
    for (size_t i = 1; i < snake.size(); ++i) {
        if (snake[i] == head) {
            return true;
        }
    }

    return false;
}

void NibblerGame::checkFruitCollision() {
    const auto& head = snake.front();
    for (size_t i = 0; i < fruits.size(); ++i) {
        if (fruits[i] == head) {
            fruits.erase(fruits.begin() + i);
            growSnake();
            score++;
            if (fruits.empty()) {
                nextLevel();
            }
            return;
        }
    }
}


void NibblerGame::growSnake() {
    snake.push_back(snake.back());
}

void NibblerGame::spawnPresetFruits() {
    if (level == 1) {
        fruits = {
            {10, 10},
            {20, 10},
            {10, 20},
            {20, 20},
            {15, 15}
        };
    }
    if (level == 2) {
        fruits = {
            {8, 8},
            {22, 8},
            {8, 22},
            {22, 22},
            {15, 15}
        };
    }
    if (level == 3) {
        fruits = {
            {5, 5},
            {25, 5},
            {5, 25},
            {25, 25},
        };
    }
}

bool NibblerGame::isWall(int x, int y) {
    return x < 0 || x >= boardSize || y < 0 || y >= boardSize || maze[y][x];
}


void NibblerGame::buildMaze() {
    maze = std::vector<std::vector<bool>>(boardSize, std::vector<bool>(boardSize, false));
    // Add outer walls
    for (int i = 0; i < boardSize; ++i) {
        maze[0][i] = true;
        maze[boardSize - 1][i] = true;
        maze[i][0] = true;
        maze[i][boardSize - 1] = true;
    }

    if (level == 1) {
        // Add simple inner walls
        for (int i = 5; i < boardSize - 5; ++i) {
            maze[i][5] = true;
            maze[i][boardSize - 6] = true;
        }
    }
    if (level == 2) {
        // Add walls for level 2
        for (int i = 5; i < boardSize - 5; ++i) {
            maze[i][10] = true;
            maze[10][i] = true;
        }
    }
    if (level == 3) {
        // Add walls for level 3
        for (int i = 0; i < boardSize; ++i) {
            if (i % 2 == 0) {
                maze[i][boardSize / 2] = true;
            } else {
                maze[boardSize / 2][i] = true;
            }
        }
    }
}

void NibblerGame::handleEvent(int event) {
    if (event == 10) {
        direction = 0;
    } else if (event == 11) {
        direction = 1;
    } else if (event == 12) {
        direction = 2;
    } else if (event == 13) {
        direction = 3;
    } 
}


void NibblerGame::nextLevel() {
    // Check if there are no fruits left on the board
    if (fruits.empty()) {
        level++;
        if (level > 3) {
            gameOver = true;
        } else {
            startTime = std::chrono::steady_clock::now();
            updateInterval -= std::chrono::milliseconds(30);
            // Clear fruits from previous level and spawn new ones
            fruits.clear();
            spawnPresetFruits();
            buildMaze();
            offsetX = 0;
            offsetY = 0;
            snake.clear();
            snake.push_back({15, 15});
            snake.push_back({14, 15});
            snake.push_back({13, 15});
            snake.push_back({12, 15});
        }
    }
}


void NibblerGame::loadHighScores() {
    std::ifstream file("games/highscore");
    std::string line;
    highScores.clear();

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name;
        int score;
        iss >> name >> score;
        highScores.push_back({name, score});
    }
}

void NibblerGame::saveHighScores() {
    std::ofstream file("games/highscore");

    for (const auto& entry : highScores) {
        file << entry.first << " " << entry.second << std::endl;
    }
}


void NibblerGame::updateHighScores(const std::string& playerName, int playerScore) {
    // Insert the player's score into the high scores vector
    auto it = std::lower_bound(highScores.begin(), highScores.end(), playerScore, [](const auto& a, const auto& b) { return a.second > b; });
    highScores.insert(it, {playerName, playerScore});

    // Remove the lowest score if there are more than 5 entries
    if (highScores.size() > 5) {
        highScores.pop_back();
    }
}

void NibblerGame::renderHighScores(IGraphics& graphics) {
    int x = 20;
    int y = 350;

    graphics.drawText(x, y, "HIGHSCORES:", "red", 25);
    y += 40;

    for (const auto& entry : highScores) {
        y += 30;
        graphics.drawText(x, y, entry.first + " " + std::to_string(entry.second), "green", 25);
    }
}

int NibblerGame::getScore() {
    return score;
}
