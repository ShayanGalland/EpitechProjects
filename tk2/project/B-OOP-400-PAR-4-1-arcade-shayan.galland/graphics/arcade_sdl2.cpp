#include "arcade_sdl2.hpp"

ArcadeSDL2::ArcadeSDL2() : _window(nullptr), _renderer(nullptr), _font(nullptr) {}

ArcadeSDL2::~ArcadeSDL2() {
    close();
}


extern "C" IGraphics* create_arcade_sdl2() {
    return new ArcadeSDL2();
}

bool ArcadeSDL2::init() {
    _name = "Jenna_Ortega";

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    if (TTF_Init() < 0) {
        return false;
    }
    _window = SDL_CreateWindow("Arcade - SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (_window == nullptr) {
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_renderer == nullptr) {
        return false;
    }

    _colorMap["black"] = {0, 0, 0, 255};
    _colorMap["white"] = {255, 255, 255, 255};
    _colorMap["red"] = {255, 0, 0, 255};
    _colorMap["green"] = {0, 255, 0, 255};
    _colorMap["blue"] = {0, 0, 255, 255};
    _colorMap["brown"] = {150, 75, 0, 255};

    return true;
}

void ArcadeSDL2::close() {
    if (_renderer) {
        SDL_DestroyRenderer(_renderer);
        _renderer = nullptr;
    }

    if (_window) {
        SDL_DestroyWindow(_window);
        _window = nullptr;
    }

    if (_font) {
        TTF_CloseFont(_font);
        _font = nullptr;
    }

    TTF_Quit();
    SDL_Quit();
}


void ArcadeSDL2::drawRect(int x, int y, int width, int height, const std::string& color) {
    SDL_Rect rect = {x, y, width, height};
    SDL_SetRenderDrawColor(_renderer, _colorMap[color].r, _colorMap[color].g, _colorMap[color].b, _colorMap[color].a);
    SDL_RenderFillRect(_renderer, &rect);
}

void ArcadeSDL2::drawText(int x, int y, const std::string& text, const std::string& color, int size) {
    TTF_Font* font = TTF_OpenFont("extern/font/ARCADE_N.TTF", size);

    SDL_Color sdlColor = getColor(color);
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), sdlColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(_renderer, textSurface);
    SDL_Rect dstRect = { x, y, textSurface->w, textSurface->h };
    SDL_RenderCopy(_renderer, textTexture, nullptr, &dstRect);
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);
}


void ArcadeSDL2::updateDisplay() {
    SDL_RenderPresent(_renderer);
}

int ArcadeSDL2::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    return 1;
                case SDLK_DOWN:
                    return 2;
                case SDLK_RIGHT:
                    return 3;
                case SDLK_LEFT:
                    return 4;
                case SDLK_BACKSPACE:
                    return 5;
                case SDLK_RETURN:
                    return 6;
                case SDLK_z:
                    return 10;
                case SDLK_s:
                    return 11;
                case SDLK_q:
                    return 12;
                case SDLK_d:
                    return 13;
                case SDLK_SPACE:
                    return 20;
                case SDLK_ESCAPE:
                    return 21;
                default:
                    break;
            }
        }
    }
    return 0;
}

SDL_Color ArcadeSDL2::getColor(const std::string& colorName)
{
    if (_colorMap.find(colorName) != _colorMap.end()) {
        return _colorMap[colorName];
    }
    return {255, 255, 255, 255};
}

void ArcadeSDL2::drawImage(const std::string& imagePath, int x, int y, float scaleX, float scaleY) {
    SDL_Surface* imageSurface = IMG_Load(imagePath.c_str());

    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(_renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    SDL_QueryTexture(imageTexture, NULL, NULL, &destRect.w, &destRect.h);

    destRect.w *= scaleX;
    destRect.h *= scaleY;

    SDL_RenderCopy(_renderer, imageTexture, NULL, &destRect);
    SDL_DestroyTexture(imageTexture);
}



void ArcadeSDL2::clear() {
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}

int ArcadeSDL2::isLib() {
    return 2;
}


std::string ArcadeSDL2::getName() {
    return _name;
}


void ArcadeSDL2::setName(std::string name) {
    _name = name;
}


void ArcadeSDL2::initName() {
    SDL_Event event;
    bool done = false;
    while (!done) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = true;
                break;
            } else if (event.type == SDL_KEYDOWN) {
                char keyPressed = event.key.keysym.sym;
                if (keyPressed >= 'a' && keyPressed <= 'z') {
                    setName(getName() + keyPressed);
                } else if (keyPressed >= 'A' && keyPressed <= 'Z') {
                    setName(getName() + keyPressed);
                }
                done = true;
                break;
            }
        }
        SDL_Delay(100);
    }
}


int ArcadeSDL2::getWindowWidth() {
    int width;
    SDL_GetWindowSize(_window, &width, nullptr);
    return width;
}

int ArcadeSDL2::getWindowHeight() {
    int height;
    SDL_GetWindowSize(_window, nullptr, &height);
    return height;
}
