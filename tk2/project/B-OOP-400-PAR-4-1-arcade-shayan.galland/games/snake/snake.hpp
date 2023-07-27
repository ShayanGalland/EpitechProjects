#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include <chrono>

#include "../IGame.hpp"


enum Direction { UP, DOWN, LEFT, RIGHT };

class SnakeGame : public IGame {
public:
    SnakeGame();
    void init() override;
    void update(IGraphics& graphics) override;
    void render(IGraphics& graphics) override;
    bool isGameOver() override;
    Direction getDirection() const { return direction; }
    void setDirection(Direction newDirection) { direction = newDirection; }
    void handleEvent(int event) override;
    void saveHighScores() override;
    int getScore() override;
    void updateHighScores(const std::string& playerName, int playerScore) override;
private:


    std::chrono::steady_clock::time_point lastUpdateTime;
    std::chrono::milliseconds updateInterval;

    static constexpr int cellSize = 20;
    static constexpr int boardSize = 30;
    std::vector<std::pair<int, int>> snake;
    std::pair<int, int> fruit;
    Direction direction;
    bool gameOver;
    int score;

    int frameCounter;
    int offsetX;
    int offsetY;
    void moveSnake();
    bool hasCollided();
    bool hasEatenFruit();
    void growSnake();
    void spawnFruit();

    void loadHighScores();
    void renderHighScores(IGraphics& graphics);

    std::vector<std::pair<std::string, int>> highScores;
};

#endif // SNAKE_GAME_HPP

