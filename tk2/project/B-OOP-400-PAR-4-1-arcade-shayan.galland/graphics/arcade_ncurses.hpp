#ifndef ARCADE_NCURSES_HPP
#define ARCADE_NCURSES_HPP

#include "IGraphics.hpp"
#include <ncurses.h>
#include <ctype.h>
#include <unistd.h>

class ArcadeNcurses : public IGraphics {
public:
    ArcadeNcurses();
    virtual ~ArcadeNcurses();

    bool init() override;
    void close() override;


    void drawRect(int x, int y, int width, int height, const std::string& color) override;
    void drawText(int x, int y, const std::string& text, const std::string& color, int size) override;
    void drawImage(const std::string& imagePath, int x, int y, float scaleX, float scaleY) override;

    void updateDisplay() override;
    int handleEvents() override;
    void clear() override;
    int isLib() override;
    std::string getName() override;
    void setName(std::string name) override;
    void initName() override;

    int getWindowWidth() override;
    int getWindowHeight() override;

private:
    void initColorPairs();

    WINDOW* _window;

    std::string _name;

};

#endif // ARCADE_NCURSES_HPP
