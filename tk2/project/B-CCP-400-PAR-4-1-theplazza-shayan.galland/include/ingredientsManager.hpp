#ifndef INGREDIENTSMANAGER_HPP_
#define INGREDIENTSMANAGER_HPP_
#include <chrono>
#include <atomic>
#include <thread>
#include <mutex>
#include "pizza.hpp"

class IngredientsManager {
private:
    std::atomic<int> cheese{10};
    std::atomic<int> tomato{10};
    std::atomic<int> dough{10};
    std::atomic<int> gruyere{10};
    std::atomic<int> ham{10};
    std::atomic<int> mushrooms{10};
    std::atomic<int> steak{10};
    std::atomic<int> eggplant{10};
    std::atomic<int> goat_cheese{10};
    std::atomic<int> chief_love{10};
    std::atomic<bool> should_stop{false};
    std::thread restock_thread;
    std::mutex mtx;

    void restock();
public:

    int _restock_time;

    bool getIngredientsForPizza(Pizza::Type type);

    IngredientsManager(int restock_time);
    ~IngredientsManager();
};

#endif
