#include "../include/reception.hpp"
#include "../include/pizza.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <sys/msg.h>
#include <semaphore.h>

Reception::Reception(int cooksPerKitchen, int restockTime, int kitchenCount) 
    : cooksPerKitchen(cooksPerKitchen), restockTimer(restockTime), kitchenCount(kitchenCount)
{
    for (int i = 0; i < kitchenCount; i++) {
        kitchens.push_back(std::make_unique<Kitchen>(cooksPerKitchen, restockTime));

        int pid = fork();
        if (pid < 0) {
            perror("Failed to fork process");
            return;
        } else if (pid == 0) {
            kitchens.back()->start(2.0);
            exit(0);
        } else {
            kitchens.back()->setPid(pid);
        }
    }
}



Kitchen* Reception::getAvailableKitchen() {
    for (auto& kitchen : kitchens) {
        if (!kitchen->isBusy() && !kitchen->isFull()) {
            return kitchen.get();
        }
    }
    return nullptr;
}

Kitchen* Reception::waitForKitchen() {
    Kitchen* kitchen;
    while ((kitchen = getAvailableKitchen()) == nullptr)
        std::cout << "Wait for a Kitchen" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    return kitchen;
}

void Reception::orderPizza(Pizza::Type type, Pizza::Size size, int quantity, double cookingTimeMultiplier) {

    for (int i = 0; i < quantity; i++) {
        Kitchen* availableKitchen = waitForKitchen();
        Message msg;
        msg.mtype = 1;
        msg.type = type;
        msg.size = size;
        msg.quantity = 1;
        mq_send(availableKitchen->getMqd(), (const char*)&msg, sizeof(Message), 0);
    }
}

void Reception::start(double cookingTimeMultiplier) {
    std::string line;
    while (std::getline(std::cin, line)) {

        if (line != "status") {
            std::istringstream iss(line);
            std::string segment;
            while (std::getline(iss, segment, ';')) {
                std::istringstream iss2(segment);
                std::string typeStr, sizeStr, quantityStr;
                iss2 >> typeStr >> sizeStr >> quantityStr;
                Pizza::Type type = stringToType(typeStr);
                Pizza::Size size = stringToSize(sizeStr);
                std::regex pattern(R"(\b[xX](\d+)\b)");
                std::smatch matches;
                if (std::regex_search(quantityStr, matches, pattern)) {
                    quantityStr = matches[1].str();
                }
                int quantity = std::stoi(quantityStr);
                std::cout << "Ordering " << typeStr << " " << sizeStr << " " << quantity << " times." << std::endl;
                orderPizza(type, size, quantity, cookingTimeMultiplier);
            }
        } else
            displayStatus();
    }
    for (auto& kitchen : kitchens) {
        int status;
        waitpid(kitchen->getPid(), &status, 0);
    }
}

void Reception::displayStatus() {
    Message msg;
    ssize_t bytes_read;
    
    do {
        bytes_read = mq_receive(mqd, (char*)&msg, sizeof(Message), NULL);
    } while ((bytes_read < 0) && (errno == EINTR));
    if (bytes_read < 0) {
        perror("mq_receive");
        return;
    }
}



Pizza::Type Reception::stringToType(const std::string& typeStr) {
    if (typeStr == "Regina") return Pizza::Type::Regina;
    if (typeStr == "Margarita") return Pizza::Type::Margarita;
    if (typeStr == "Americana") return Pizza::Type::Americana;
    if (typeStr == "Fantasia") return Pizza::Type::Fantasia;
    throw std::invalid_argument("Invalid pizza type: " + typeStr);
}

Pizza::Size Reception::stringToSize(const std::string& sizeStr) {
    if (sizeStr == "S") return Pizza::Size::S;
    if (sizeStr == "M") return Pizza::Size::M;
    if (sizeStr == "L") return Pizza::Size::L;
    if (sizeStr == "XL") return Pizza::Size::XL;
    if (sizeStr == "XXL") return Pizza::Size::XXL;
    throw std::invalid_argument("Invalid pizza size: " + sizeStr);
}
