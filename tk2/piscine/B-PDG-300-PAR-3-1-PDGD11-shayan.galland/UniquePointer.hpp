#ifndef _UNIQUE_POINTER_HPP
#define _UNIQUE_POINTER_HPP

#include "IObject.hpp"

class UniquePointer{
public:
    UniquePointer();
    UniquePointer(IObject* ptr);
    ~UniquePointer();

    void reset();
    void reset(IObject* ptr);
    void swap(UniquePointer& unq_ptr);

    IObject* operator->();
    IObject& operator*();
    UniquePointer& operator=(IObject* ptr);

private:
    UniquePointer(UniquePointer& ref) = delete;
    UniquePointer operator=(UniquePointer& ref) = delete;
    IObject* _ptr;
};

#endif