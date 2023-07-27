#ifndef I_GAME_HPP
#define I_GAME_HPP

#include <string>
#include "../graphics/IGraphics.hpp"

class IGame {
public:
    virtual ~IGame() = default;

    virtual void init() = 0;
    virtual void update(IGraphics& graphics) = 0; // Modify this line
    virtual void render(IGraphics& graphics) = 0;
    virtual bool isGameOver() = 0;
    virtual void handleEvent(int event) = 0;

    virtual void updateHighScores(const std::string& playerName, int playerScore) = 0; // Add this line
    virtual void saveHighScores() = 0; // Add this line

    virtual int getScore() = 0; 
};


#endif // I_GAME_HPP
