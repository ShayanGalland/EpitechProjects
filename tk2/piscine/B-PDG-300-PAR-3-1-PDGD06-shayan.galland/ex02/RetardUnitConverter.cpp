/*
** EPITECH PROJECT, 2023
** project
** File description:
** in cpp
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

int main() {
    std::string input;
    std::string scale;
    float temp;

    while (std::getline(std::cin, input)) {
        std::stringstream str(input);
        str >> temp >> scale;

        if (scale == "Celsius") {
            temp = (9.0 / 5.0) * temp + 32;
            std::cout << std::setw(16) << std::fixed << std::setprecision(3) << temp  << std::setw(16) << " Fahrenheit" << std::endl;
        } else if (scale == "Fahrenheit") {
            temp = (5.0 / 9.0) * (temp - 32);
            std::cout << std::setw(16) << std::fixed << std::setprecision(3) << temp  << std::setw(16) << " Celsius" << std::endl;
        }
        temp = 0.0;
        scale = "";
    }
    return 0;
}
