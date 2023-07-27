#include "arcade_SFML.hpp"
#include <map>
#include <cmath>
#include <iostream>

ArcadeSFML::ArcadeSFML() {}

ArcadeSFML::~ArcadeSFML() {
    close();
}


extern "C" IGraphics* create_arcade_SFML() {
    return new ArcadeSFML();
}



bool ArcadeSFML::init() {
    _name = "Jenna_Ortega";
    _window.create(sf::VideoMode::getDesktopMode(), "Arcade - SFML", sf::Style::Fullscreen);
    return _window.isOpen();
}

void ArcadeSFML::close() {
    _window.close();
}

sf::Color ArcadeSFML::getColor(const std::string& colorName) {
    sf::Color brown(150, 75, 0, 255);

    static std::map<std::string, sf::Color> colorMap = {
        {"red", sf::Color::Red},
        {"green", sf::Color::Green},
        {"blue", sf::Color::Blue},
        {"yellow", sf::Color::Yellow},
        {"white", sf::Color::White},
        {"black", sf::Color::Black},
        {"brown", brown}
    };

    return colorMap[colorName];
}



void ArcadeSFML::drawRect(int x, int y, int width, int height, const std::string& color) {
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setPosition(x, y);
    rect.setFillColor(getColor(color));
    _window.draw(rect);
}

void ArcadeSFML::drawText(int x, int y, const std::string& text, const std::string& color, int size) {
    sf::Text sfText;
    sf::Font font;
    font.loadFromFile("extern/font/ARCADE_N.TTF");
    sfText.setFont(font);
    sfText.setString(text);
    sfText.setCharacterSize(size);
    sfText.setFillColor(getColor(color));
    sfText.setPosition(x, y);
    _window.draw(sfText);
}

void ArcadeSFML::updateDisplay() {
    _window.display();
}

int ArcadeSFML::handleEvents() {
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Up:
                    return 1;
                case sf::Keyboard::Down:
                    return 2;
                case sf::Keyboard::Right:
                    return 3;
                case sf::Keyboard::Left:
                    return 4;
                case sf::Keyboard::BackSpace:
                    return 5;
                case sf::Keyboard::Enter:
                    return 6;
                case sf::Keyboard::Z:
                    return 10;
                case sf::Keyboard::S:
                    return 11;
                case sf::Keyboard::Q:
                    return 12;
                case sf::Keyboard::D:
                    return 13;
                case sf::Keyboard::Space:
                    return 20;
                case sf::Keyboard::Escape:
                    return 21;
                default:
                    break;
            }
        }
    }
    return 0;
}


void ArcadeSFML::drawImage(const std::string& imagePath, int x, int y, float scaleX, float scaleY) {
    if (_textureMap.find(imagePath) == _textureMap.end()) {
        if (!_textureMap[imagePath].loadFromFile(imagePath)) {
            std::cerr << "Error loading image: " << imagePath << std::endl;
            return;
        }
    }
    sf::Sprite sprite(_textureMap[imagePath]);
    sprite.setPosition(x, y);
    sprite.setScale(scaleX, scaleY);
    _window.draw(sprite);
}




void ArcadeSFML::clear() {
    _window.clear();
}


int ArcadeSFML::isLib() {
    return 3;
}

std::string ArcadeSFML::getName() {
    return _name;
}

void ArcadeSFML::setName(std::string name) {
    _name = name;
}

void ArcadeSFML::initName()
{
    bool keyPressed = false;

    for (char letter = 'A'; letter <= 'Z'; ++letter)
    {
        if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(sf::Keyboard::A + (letter - 'A'))))
        {
            setName(getName() + static_cast<char>(tolower(letter)));
            keyPressed = true;
            break;
        }
    }

    if (keyPressed)
    {
        sf::sleep(sf::milliseconds(200));
    }
}

int ArcadeSFML::getWindowWidth() {
    return _window.getSize().x;
}

int ArcadeSFML::getWindowHeight() {
    return _window.getSize().y;
}
