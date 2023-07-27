#include "../include/ingredientsManager.hpp"
#include <iostream>

void IngredientsManager::restock() {
    while (!should_stop) {
        std::this_thread::sleep_for(std::chrono::milliseconds(_restock_time));
        std::lock_guard<std::mutex> lock(mtx);
        tomato += 10;
        dough += 10;
        gruyere += 10;
        ham += 10;
        mushrooms += 10;
        steak += 10;
        eggplant += 10;
        goat_cheese += 10;
        chief_love += 10;

    }
}

IngredientsManager::IngredientsManager(int restock_time) : _restock_time(restock_time) {
    restock_thread = std::thread(&IngredientsManager::restock, this);
}

IngredientsManager::~IngredientsManager() {
    should_stop = true;
    if (restock_thread.joinable()) {
        restock_thread.join();
    }
}

bool IngredientsManager::getIngredientsForPizza(Pizza::Type type) {
    std::lock_guard<std::mutex> lock(mtx);
    if (type == Pizza::Type::Margarita) {
        if (dough > 0 && tomato > 0 && gruyere > 0) {
            --dough;
            --tomato;
            --gruyere;
            return true;
        }
    } else if (type == Pizza::Type::Regina) {
        if (dough > 0 && tomato > 0 && gruyere > 0 && ham > 0 && mushrooms > 0) {
            --dough;
            --tomato;
            --gruyere;
            --ham;
            --mushrooms;
            return true;
        }
    } else if (type == Pizza::Type::Americana) {
        if (dough > 0 && tomato > 0 && gruyere > 0 && steak > 0) {
            --dough;
            --tomato;
            --gruyere;
            --steak;
            return true;

        }
    } else if (type == Pizza::Type::Fantasia) {
        if (dough > 0 && tomato > 0 && eggplant > 0 && goat_cheese > 0 && chief_love > 0) {
            --dough;
            --tomato;
            --eggplant;
            --goat_cheese;
            --chief_love;
            return true;

        }
    }
    return false;
}
