#ifndef MESSAGE_HPP
#define MESSAGE_HPP
#include "pizza.hpp"

struct Message {
    enum class Status {
        IDLE,
        BUSY
    };
    
    long mtype;
    Pizza::Type type;
    Pizza::Size size;
    int quantity;
    Status status;  // new status field
};

#endif
