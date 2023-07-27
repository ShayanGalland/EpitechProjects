#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_
#include <stdexcept>
#include "pizza.hpp"
#include "kitchen.hpp"
#include <vector>

class Reception {
    std::vector<std::unique_ptr<Kitchen>> kitchens;
    int restockTimer;
    int cooksPerKitchen;
    int kitchenCount;
public:
    std::mutex mtx_cmdlck;
    Reception(int cooksPerKitchen, int restockTime, int kitchenCount);
    void start(double cookingTimeMultiplier);
    void orderPizza(Pizza::Type type, Pizza::Size size, int quantity, double cookingTimeMultiplier);
    void displayStatus();
    Kitchen* getAvailableKitchen();
    Kitchen* waitForKitchen();

    Pizza::Type stringToType(const std::string& typeStr);
    Pizza::Size stringToSize(const std::string& sizeStr);
};

#endif
