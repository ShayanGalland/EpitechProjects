#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_
#include "pizza.hpp"
#include "cook.hpp"
#include "ingredientsManager.hpp"
#include "message.hpp"
#include <queue>
#include <vector>
#include <list>
#include <iostream>
#include <stack>
#include <mutex>
#include <thread>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

class Cook;
class Kitchen {
private:
    std::vector<std::unique_ptr<Cook>> cooks;
    std::list<Pizza> pizzas;
    std::vector<std::thread> cookThreads;
    std::unique_ptr<IngredientsManager> ingredientsManager;
    pid_t _pid;
    bool busy;

public:

    mqd_t mqd;
    int restockTime;
    std::mutex mtx;

    bool isBusy() const;
    void setBusy(bool b);
    void setPid(int pid);
    pid_t getPid() const;
    size_t getNumberOfPizzas() const;
    const std::vector<std::unique_ptr<Cook>>& getCooks() const;
    bool isFull();
    IngredientsManager& getIngredientsManager() const;
    void start(double cookingTimeMultiplier);
    mqd_t getMqd() const;
    void addOrder(Pizza& pizza, double cookingTimeMultiplier);
    void removePizza(const Pizza& pizza);

    Kitchen(int numCooks, int _restockTime);
    ~Kitchen();
    Kitchen(const Kitchen& other) = delete;
    Kitchen(Kitchen&& other) = delete;


};

#endif
