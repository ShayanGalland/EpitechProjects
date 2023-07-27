#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include "snake.hpp"

extern "C" IGame* createSnakeGame() {
    return new SnakeGame();
}

SnakeGame::SnakeGame() {
    srand(time(NULL));
}

void SnakeGame::init() {

    gameOver = false;
    score = 0;
    snake.clear();
    snake.push_back({15, 15});
    snake.push_back({14, 15});
    snake.push_back({13, 15});
    snake.push_back({12, 15});
    frameCounter = 0;
    direction = RIGHT;

    lastUpdateTime = std::chrono::steady_clock::now();
    updateInterval = std::chrono::milliseconds(100);

    spawnFruit();
    loadHighScores();
}

void SnakeGame::update(IGraphics& graphics) {
    if (gameOver) return;

    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastUpdateTime);

    if (elapsedTime >= updateInterval) {
        moveSnake();

        if (hasCollided()) {
            gameOver = true;
            return;
        }

        if (hasEatenFruit()) {
            growSnake();
            spawnFruit();
            score++;
        }

        lastUpdateTime = currentTime;
    }
}



void SnakeGame::render(IGraphics& graphics) {
    offsetX = (graphics.getWindowWidth() - (boardSize * cellSize)) / 2;
    offsetY = (graphics.getWindowHeight() - (boardSize * cellSize)) / 2;
    graphics.drawRect(offsetX, offsetY, boardSize * cellSize, boardSize * cellSize, "brown");

    for (const auto& part : snake) {
        graphics.drawRect(offsetX + part.first * cellSize, offsetY + part.second * cellSize, cellSize, cellSize, "green");
    }

    graphics.drawRect(offsetX + fruit.first * cellSize, offsetY + fruit.second * cellSize, cellSize, cellSize, "red");

    graphics.drawText(600, 20, "Score: " + std::to_string(score), "blue", 24);
    renderHighScores(graphics); // Add this line
}


bool SnakeGame::isGameOver() {
    return gameOver;
}

void SnakeGame::moveSnake() {
    std::pair<int, int> newHead = snake.front();

    switch (direction) {
        case UP:
            newHead.second--;
            break;
        case DOWN:
            newHead.second++;
            break;
        case LEFT:
            newHead.first--;
            break;
        case RIGHT:
            newHead.first++;
            break;
    }

    snake.insert(snake.begin(), newHead);
    snake.pop_back();
}

bool SnakeGame::hasCollided() {
    const auto& head = snake.front();

    if (head.first < 0 || head.first >= boardSize || head.second < 0 || head.second >= boardSize) {
        return true;
    }

    for (size_t i = 1; i < snake.size(); ++i) {
        if (snake[i] == head) {
            return true;
        }
    }

    return false;
}

bool SnakeGame::hasEatenFruit() {
    return snake.front() == fruit;
}

void SnakeGame::growSnake() {
    snake.push_back(snake.back());
}

void SnakeGame::spawnFruit() {
    fruit.first = rand() % boardSize;
    fruit.second = rand() % boardSize;
}


void SnakeGame::handleEvent(int event) {
    if (event == 10 && direction != DOWN) {
        direction = UP;
    } else if (event == 11 && direction != UP) {
        direction = DOWN;
    } else if (event == 13 && direction != LEFT) {
        direction = RIGHT;
    } else if (event == 12 && direction != RIGHT) {
        direction = LEFT;
    }
}




void SnakeGame::loadHighScores() {
    std::ifstream file("games/highscore_");
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

void SnakeGame::saveHighScores() {
    std::ofstream file("games/highscore_");

    for (const auto& entry : highScores) {
        file << entry.first << " " << entry.second << std::endl;
    }
}

void SnakeGame::updateHighScores(const std::string& playerName, int playerScore) {
    auto it = std::lower_bound(highScores.begin(), highScores.end(), playerScore, [](const auto& a, const auto& b) { return a.second > b; });
    highScores.insert(it, {playerName, playerScore});

    if (highScores.size() > 5) {
        highScores.pop_back();
    }
}

void SnakeGame::renderHighScores(IGraphics& graphics) {
    int x = 20;
    int y = 350;

    graphics.drawText(x, y, "HIGHSCORES:", "red", 25);
    y += 40;

    for (const auto& entry : highScores) {
        y += 30;
        graphics.drawText(x, y, entry.first + " " + std::to_string(entry.second), "green", 25);
    }
}


int SnakeGame::getScore() {
    return score;
}
