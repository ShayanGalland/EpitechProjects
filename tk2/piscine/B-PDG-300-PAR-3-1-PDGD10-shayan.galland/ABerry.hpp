#ifndef ABERRY_HPP
#define ABERRY_HPP

#include "AFruit.hpp"

class ABerry : public AFruit {
    public:
        ABerry():_peeled(true) {}
        ~ABerry() {}
        bool isPeeled() const override {
            return _peeled;
        }
    protected:
        bool _peeled;
};

#endif