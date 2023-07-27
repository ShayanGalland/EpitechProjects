#ifndef NIBBLER_HPP
#define NIBBLER_HPP

#include "../IGame.hpp"

#include <vector>
#include <utility>
#include <chrono>

class NibblerGame : public IGame {
public:
    NibblerGame();
    void init() override;
    void update(IGraphics& graphics) override;
    void render(IGraphics& graphics) override;
    void handleEvent(int event) override;
    bool isGameOver() override;
    int getScore() override;
    void saveHighScores() override;
    void updateHighScores(const std::string& playerName, int playerScore) override;

private:
    void moveSnake();
    bool hasCollided();
    void checkFruitCollision();
    void growSnake();
    void spawnPresetFruits();
    bool isWall(int x, int y);
    void buildMaze();
    void nextLevel();

    // Add the new functions here
    void loadHighScores();

    void renderHighScores(IGraphics& graphics);

    int boardSize;
    int direction;
    std::vector<std::pair<int, int>> snake;
    std::vector<std::vector<bool>> maze;
    std::vector<std::pair<int, int>> fruits;
    int score;
    int level;
    bool gameOver;
    std::chrono::steady_clock::time_point startTime;
    std::chrono::seconds levelDuration;

    // Add these member variables
    int cellSize;
    int offsetX;
    int offsetY;
    std::chrono::steady_clock::time_point lastUpdateTime;
    std::chrono::milliseconds updateInterval;

    // Add the highScores vector
    std::vector<std::pair<std::string, int>> highScores;
};

#endif // NIBBLER_HPP
