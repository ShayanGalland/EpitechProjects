#ifndef DROID_HPP
#define DROID_HPP
#include <iostream>
#include <string>

#include "DroidMemory.hpp"

class Droid {
    const size_t _attack;
    const size_t _toughness;
    std::string _id;
    size_t _energy;
    std::string *_status;
    DroidMemory * _battleData;

    public :
        Droid(std::string Id);
        Droid(Droid const &droid);
        ~Droid();
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string getId() const;
        std::string *getStatus() const;
        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);
        DroidMemory* GetBattleData();
        void SetBattleData(DroidMemory * battleData);

        bool operator==(Droid const &droid) const;
        bool operator!=(Droid const &droid) const;
        Droid& operator=(Droid const &droid);
        Droid& operator<<(size_t &reload);
    };

    std::ostream& operator << (std::ostream& out, Droid const &droid);

#endif
