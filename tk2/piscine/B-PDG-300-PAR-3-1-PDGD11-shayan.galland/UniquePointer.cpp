#include "UniquePointer.hpp"

UniquePointer::UniquePointer() : _ptr(nullptr)
{

}

UniquePointer::UniquePointer(IObject* ptr)
{
     _ptr = ptr;
}

UniquePointer::~UniquePointer()
{
    if(_ptr != nullptr)
        delete _ptr;
}

void UniquePointer::reset()
{
    if(_ptr != nullptr)
        delete _ptr;
    _ptr = nullptr;
}

void UniquePointer::reset(IObject* ptr)
{
    if(_ptr != nullptr)
        delete _ptr;
    _ptr = ptr;
}

void UniquePointer::swap(UniquePointer& unq_ptr)
{
    IObject* tmp = _ptr;
    _ptr = unq_ptr._ptr;
    unq_ptr._ptr = tmp;
}

IObject* UniquePointer::operator->()
{
    return _ptr;
}

IObject& UniquePointer::operator*()
{
    return *_ptr;
}

UniquePointer& UniquePointer::operator=(IObject* ptr)
{
    reset(ptr);
    return (*this);
}
