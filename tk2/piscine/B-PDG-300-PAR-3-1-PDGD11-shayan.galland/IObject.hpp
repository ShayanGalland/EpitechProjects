#pragma once

class IObject
{
public:
    virtual ~IObject() = default;

    virtual void touch() = 0;
};
