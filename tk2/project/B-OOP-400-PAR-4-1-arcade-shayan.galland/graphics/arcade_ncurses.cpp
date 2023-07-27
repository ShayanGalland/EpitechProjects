#include "arcade_ncurses.hpp"
#include <stdexcept>
#include <iostream>

ArcadeNcurses::ArcadeNcurses() : _window(nullptr)
{

}

ArcadeNcurses::~ArcadeNcurses() {
    close();
}


extern "C" IGraphics* create_arcade_ncurses() {
    return new ArcadeNcurses();
}



bool ArcadeNcurses::init() {
    _name = "Jenna_Ortega";
    _window = initscr();
    if (!_window) {
        return false;
    }


    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    init_pair(8, COLOR_WHITE, COLOR_BLACK);
    init_pair(9, COLOR_YELLOW, COLOR_BLACK);
    init_pair(10, COLOR_BLACK, COLOR_BLACK);

    raw();
    keypad(_window, TRUE);
    noecho();
    curs_set(0);
    timeout(0); // Set a higher input delay
    nodelay(_window, TRUE);
    return true;
}


void ArcadeNcurses::close() {
    if (_window) {
        endwin();
        _window = nullptr;
    }
}


void ArcadeNcurses::drawRect(int x, int y, int width, int height, const std::string& color) {
    int pairNumber = 1;

    if (color == "red") {
        pairNumber = 2;
    } else if (color == "green") {
        pairNumber = 3;
    } else if (color == "yellow") {
        pairNumber = 4;
    } else if (color == "blue") {
        pairNumber = 5;
    } else if (color == "magenta") {
        pairNumber = 6;
    } else if (color == "cyan") {
        pairNumber = 7;
    } else if (color == "white") {
        pairNumber = 8;
    } else if (color == "brown") {
        pairNumber = 9;
    } else if (color == "black") {
        pairNumber = 10;
    }

    attron(COLOR_PAIR(pairNumber));


    x *= 0.05f;
    y *= 0.05f;
    x += 30;
    y += 20;

    width *= 0.05f;
    height *= 0.05f;

    for (int i = y; i < y + height; i++) {
        for (int j = x; j < x + width; j++) {
            mvaddch(i, j, ACS_CKBOARD);//

        }
    }

    attroff(COLOR_PAIR(pairNumber));
}





void ArcadeNcurses::drawText(int x, int y, const std::string& text, const std::string& color, int size) {
    int pairNumber = 1;

    if (color == "red") {
        pairNumber = 2;
    } else if (color == "green") {
        pairNumber = 3;
    } else if (color == "yellow") {
        pairNumber = 4;
    } else if (color == "blue") {
        pairNumber = 5;
    } else if (color == "magenta") {
        pairNumber = 6;
    } else if (color == "cyan") {
        pairNumber = 7;
    } else if (color == "white") {
        pairNumber = 8;
    } else if (color == "brown") {
        pairNumber = 9;
    }

    attron(COLOR_PAIR(pairNumber));

    mvprintw(y * 0.05f, x * 0.05f, text.c_str());

    attroff(COLOR_PAIR(pairNumber));
}


void ArcadeNcurses::updateDisplay() {
    refresh();
}

int ArcadeNcurses::handleEvents() {
    int ch = wgetch(_window);

    switch (ch) {
        case KEY_UP:
            return 1;
        case KEY_DOWN:
            return 2;
        case KEY_RIGHT:
            return 3;
        case KEY_LEFT:
            return 4;
        case KEY_BACKSPACE:
            return 5;
        case '\n':
            return 6;
        case 'z':
            return 10;
        case 's':
            return 11;
        case 'q':
            return 12;
        case 'd':
            return 13;
        case 32: // space
            return 20;
        case 27:  //escape
            return 21;
        default:
            return 0;
    }
}

void ArcadeNcurses::clear() {
    ::clear();
}

void ArcadeNcurses::drawImage(const std::string& imagePath, int x, int y, float scaleX, float scaleY) {
    // Ncurses does not support image drawing
}


int ArcadeNcurses::isLib() {
    return 1;
}

std::string ArcadeNcurses::getName() {
    return _name;
}


void ArcadeNcurses::setName(std::string name) {
    _name = name;
}


void ArcadeNcurses::initName()
{
    int ch = getch();

    if (ch != ERR)
    {
        for (char letter = 'A'; letter <= 'Z'; ++letter)
        {
            if (toupper(ch) == letter)
            {
                setName(getName() + static_cast<char>(letter));
                break;
            }
        }
    }
    refresh();
}


int ArcadeNcurses::getWindowWidth() {
    int width, temp;
    getmaxyx(stdscr, temp, width);
    return width;
}

int ArcadeNcurses::getWindowHeight() {
    int height, temp;
    getmaxyx(stdscr, height, temp);
    return height;
}