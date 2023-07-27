#ifndef COOK_HPP_
#define COOK_HPP_
#include "pizza.hpp"
#include <thread>
#include <chrono>
#include <atomic>
#include <list>
#include <mutex>
#include <condition_variable>

class Kitchen;

class Cook {
    std::atomic<bool> is_busy{false};
    std::atomic<bool> should_stop{false};
    std::mutex stop_mtx;
    std::condition_variable cv;
public:
    void stop(std::list<Pizza>& pizzas);
    bool isStopping();
    bool isBusy();
    void setBusy(bool busy);
    void cook(std::list<Pizza>& pizzas, Kitchen& kitchen, double cookingTimeMultiplier);
    std::condition_variable& getConditionVariable();
    Cook() = default;
};


#endif
