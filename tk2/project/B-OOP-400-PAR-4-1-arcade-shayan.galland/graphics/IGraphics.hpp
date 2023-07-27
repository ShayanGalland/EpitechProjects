#ifndef IGRAPHICS_HPP
#define IGRAPHICS_HPP

#include <string>

class IGraphics {
public:
    virtual ~IGraphics() {}

    // Initialize the graphics library
    virtual bool init() = 0;

    // Clean up and close the graphics library
    virtual void close() = 0;

    // Draw an image with his path, and set up the coordinate (x, y) and he's size (scaleX, sclaeY)
    virtual void drawImage(const std::string& imagePath, int x, int y, float scaleX, float scaleY) = 0;

    // Draw a rectangle with the top-left corner at (x, y), with the given width, height, and color
    virtual void drawRect(int x, int y, int width, int height, const std::string& color) = 0;

    // Draw text at the given position (x, y) with the specified color and size
    virtual void drawText(int x, int y, const std::string& text, const std::string& color, int size) = 0;

    // Update the display to show the drawn elements
    virtual void updateDisplay() = 0;

    // Check and process input events, such as keyboard and mouse events
    virtual int handleEvents() = 0;

    // Clear function in the lib implemented for screen clearing
    virtual void clear() = 0;

    // Find the lib being implemented
    virtual int isLib() = 0;

    // Get name of the player
    virtual std::string getName() = 0;

    // Set Name of the player
    virtual void setName(std::string name) = 0;

    // Init name of the player, make so that the user can chose his name by typing it
    virtual void initName() = 0;

    // getWindowWidth
    virtual int getWindowWidth() = 0;

    // getWindowHeight
    virtual int getWindowHeight() = 0;
};


#endif // IGRAPHICS_HPP
