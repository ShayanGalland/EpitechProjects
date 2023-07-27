#ifndef ARCADE_SFML_HPP
#define ARCADE_SFML_HPP

#include "IGraphics.hpp"
#include <SFML/Graphics.hpp>

class ArcadeSFML : public IGraphics {
public:
    ArcadeSFML();
    virtual ~ArcadeSFML();

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
    sf::Color getColor(const std::string& colorName);
    std::map<std::string, sf::Texture> _textureMap;
    sf::RenderWindow _window;

    std::string _name;
};

#endif // ARCADE_SFML_HPP
