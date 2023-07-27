CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -fPIC -ldl `sdl2-config --cflags` 
LDFLAGS_SDL2 = -lSDL2 -lSDL2_image -lSDL2_ttf
LDFLAGS_NC = -lncurses
LDFLAGS_SFML = -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS = -shared

SRC_CORE = core/main.cpp
OBJ_CORE = $(SRC_CORE:.cpp=.o)
TARGET_CORE = arcade

SRC_GAMES = games/nibbler/nibbler.cpp games/snake/snake.cpp
OBJ_GAMES = $(SRC_GAMES:.cpp=.o)
TARGET_GAMES = lib/arcade_nibbler.so lib/arcade_snake.so

SRC_GRAPHICS = graphics/arcade_ncurses.cpp graphics/arcade_sdl2.cpp graphics/arcade_SFML.cpp
OBJ_GRAPHICS = $(SRC_GRAPHICS:.cpp=.o)
TARGET_GRAPHICS = lib/arcade_ncurses.so lib/arcade_sdl2.so lib/arcade_SFML.so

all: core games graphicals

core: $(TARGET_CORE)

games: $(TARGET_GAMES)

graphicals: $(TARGET_GRAPHICS)

$(TARGET_CORE): $(OBJ_CORE) $(OBJ_GRAPHICS)
	$(CXX) $(CXXFLAGS) -o $@ $^ -ldl $(LDFLAGS_NC) $(LDFLAGS_SDL2) $(LDFLAGS_SFML)


lib/arcade_snake.so: games/snake/snake.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

lib/arcade_nibbler.so: games/nibbler/nibbler.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

lib/arcade_ncurses.so: graphics/arcade_ncurses.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS_NC) $(LDFLAGS) -o $@ $^

lib/arcade_sdl2.so: graphics/arcade_sdl2.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS_SDL2) $(LDFLAGS) -o $@ $^

lib/arcade_SFML.so: graphics/arcade_SFML.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS_SFML) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CORE) $(OBJ_GAMES) $(OBJ_GRAPHICS)

fclean: clean
	rm -f $(TARGET_CORE) $(TARGET_GAMES) $(TARGET_GRAPHICS)

re: fclean all
