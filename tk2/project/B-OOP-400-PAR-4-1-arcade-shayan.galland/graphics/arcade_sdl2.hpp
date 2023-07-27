#ifndef ARCADE_SDL2_HPP
#define ARCADE_SDL2_HPP

#include "IGraphics.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <map>
#include <string>

class ArcadeSDL2 : public IGraphics {
public:
    ArcadeSDL2();
    virtual ~ArcadeSDL2();

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
    SDL_Color getColor(const std::string& colorName);

    SDL_Window* _window;
    SDL_Renderer* _renderer;
    std::map<std::string, SDL_Color> _colorMap;
    TTF_Font* _font;


    std::string _name;
};

#endif // ARCADE_SDL2_HPP
