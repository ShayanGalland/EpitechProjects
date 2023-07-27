#ifndef MY_HPP
#define MY_HPP

#include <iostream>
#include <ios>
#include <sys/utsname.h>
#include <chrono>
#include <regex>
#include <vector>
#include <iomanip>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <thread>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <ctime>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "Window.hpp"



void ncurse(char **env);
void graphical();

#endif