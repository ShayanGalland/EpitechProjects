#include "../include/cook.hpp"
#include "../include/kitchen.hpp"
#include "../include/ingredientsManager.hpp"

void Cook::cook(std::list<Pizza>& pizzas, Kitchen& kitchen, double cookingTimeMultiplier) {
    while (!should_stop) {
        Pizza* pizza = nullptr;
        {
            std::unique_lock<std::mutex> lock(kitchen.mtx);
            if (pizzas.empty()) {
                cv.wait(lock, [&]{ return !pizzas.empty() || should_stop; });
                if (should_stop) {
                    return;
                }
            }
            pizza = &pizzas.front();
        }
        if (pizza != nullptr) {
            if (kitchen.getIngredientsManager().getIngredientsForPizza(pizza->type)) {
                int baseTime = 1000;
                switch(pizza->type) {
                    case Pizza::Type::Margarita:
                        baseTime = 1000;
                        break;
                    case Pizza::Type::Regina:
                        baseTime = 2000;
                        break;
                    case Pizza::Type::Americana:
                        baseTime = 2000;
                        break;
                    case Pizza::Type::Fantasia:
                        baseTime = 3000;
                        break;
                    default:
                        std::cout << "Unknown pizza type!" << std::endl;
                        return;
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(baseTime * cookingTimeMultiplier)));
                kitchen.removePizza(*pizza);
                std::cout << "Pizza " << static_cast<int>(pizza->type) << " is ready!" << std::endl;
                pizza = nullptr;
            } else {
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
    is_busy = false;
}




bool Cook::isStopping() {
    std::lock_guard<std::mutex> lock(stop_mtx);
    return should_stop;
}

void Cook::stop(std::list<Pizza>& pizzas) {
    std::lock_guard<std::mutex> lock(stop_mtx);
    should_stop = true;

}

bool Cook::isBusy(){
    return is_busy;
}

void Cook::setBusy(bool busy) {
    is_busy = busy;
}

std::condition_variable& Cook::getConditionVariable() {
    return cv;
}