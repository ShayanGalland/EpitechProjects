#include "../include/kitchen.hpp"
#include "../include/cook.hpp"
#include <iostream>
#include <algorithm>
#include <semaphore.h>
#include <fcntl.h>

void Kitchen::removePizza(const Pizza& pizza) {
    std::lock_guard<std::mutex> lock(mtx);
    auto it = std::find(pizzas.begin(), pizzas.end(), pizza);
    if (it != pizzas.end()) {
        pizzas.erase(it);
    }

}

Kitchen::~Kitchen() {
    mq_close(mqd);
    for (auto& cook : cooks) {
        cook->stop(pizzas);
    }
    for (auto& thread : cookThreads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

Kitchen::Kitchen(int numCooks, int _restockTime) : restockTime(_restockTime), ingredientsManager(std::make_unique<IngredientsManager>(_restockTime)) {
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = sizeof(Message);
    attr.mq_curmsgs = 0;


    std::string queue_name = "/pizza_queue" + std::to_string(getpid());


    mqd = mq_open(queue_name.c_str(), O_CREAT | O_RDWR, S_IRWXU, &attr);

    for (int i = 0; i < numCooks; ++i) {
        cooks.push_back(std::make_unique<Cook>());
    }
}


void Kitchen::addOrder(Pizza& pizza, double cookingTimeMultiplier) {
    std::lock_guard<std::mutex> lock(mtx);
    pizzas.push_back(pizza);
    for (auto& cook : cooks) {
        if (!cook->isBusy()) {
            cook->setBusy(true);
            cookThreads.emplace_back(&Cook::cook, cook.get(), std::ref(pizzas), std::ref(*this), cookingTimeMultiplier);
            cook->getConditionVariable().notify_one();
            break;
        }
    }
}


void Kitchen::setPid(int pid) {
    _pid = pid;
}

pid_t Kitchen::getPid() const
{
    return _pid;
}

mqd_t Kitchen::getMqd() const {
    return this->mqd;
}

size_t Kitchen::getNumberOfPizzas() const {
    return pizzas.size();
}

const std::vector<std::unique_ptr<Cook>>& Kitchen::getCooks() const {
    return cooks;
}

bool Kitchen::isFull() {
    return pizzas.size() >= 2 * cooks.size();
}

IngredientsManager& Kitchen::getIngredientsManager() const {
    return *ingredientsManager;
}



void Kitchen::start(double cookingTimeMultiplier) {
    while (true) {
        Message msg;
        ssize_t bytes_read;

        do {
            bytes_read = mq_receive(mqd, (char*)&msg, sizeof(Message), NULL);
        } while ((bytes_read < 0) && (errno == EINTR));

        if (bytes_read < 0) {
            perror("mq_receive");
            return;
        }

        for (int i = 0; i < msg.quantity; i++) {
            Pizza pizza(msg.type, msg.size);
            if(ingredientsManager->getIngredientsForPizza(msg.type)) {
                addOrder(pizza, cookingTimeMultiplier);
            } else {
                std::cout << "Ingredients for Pizza " << static_cast<int>(msg.type) << " not available\n";
            }
        }
    }
}



bool Kitchen::isBusy() const {
    return busy;
}
void Kitchen::setBusy(bool b) {
    busy = b;
}

