#include "../include/reception.hpp"
#include "../include/kitchen.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    try {
        if (argc != 4) {
            std::cerr << "Usage: " << argv[0] << " <cooking_time_multiplier> <cooks_per_kitchen> <ingredient_restock_time>\n";
            return 84;
        }
        double cookingTimeMultiplier = std::stod(argv[1]);
        int cooksPerKitchen = std::stoi(argv[2]);
        int ingredientRestockTime = std::stoi(argv[3]);

        Reception reception(cooksPerKitchen, ingredientRestockTime, 7);
        reception.start(cookingTimeMultiplier);
        return 0;
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 84;
    }
}
