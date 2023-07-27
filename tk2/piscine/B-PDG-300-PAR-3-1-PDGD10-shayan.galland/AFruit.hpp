#ifndef AFRUIT_HPP
#define AFRUIT_HPP

#include "IFruit.hpp"

class AFruit : public IFruit {
    public:
        AFruit();
        ~AFruit() {}
        unsigned int getVitamins() const override;
        std::string getName() const override;
        bool isPeeled() const override;
        void peel() override;
    protected:
        bool _peeled;
        unsigned int _vitamins;
};



#endif