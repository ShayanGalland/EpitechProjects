#include "Borg.hpp"


#include <iostream>

namespace Borg
{

    Ship::Ship(int weaponFrequency, short repair)
    {
        _side = 300;
        _maxWarp = 9;
        _home = UNICOMPLEX;
        _location = _home;
        _shield = 100;
        _weaponFrequency = weaponFrequency;
        _repair = repair;

        std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
        std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
        std::cout << "Resistance is futile." << std::endl;
    }

    void Ship::setupCore(WarpSystem::Core* core)
    {
        _core = core;
    }

    void Ship::checkCore()
    {
        if(_core->checkReactor()->isStable())
            std::cout << "Everything is in order." << std::endl;
        else
            std::cout << "Critical failure imminent." << std::endl;
    }

    bool Ship::move(int warp, Destination d)
    {
        if(warp <= _maxWarp && d != _location && _core->checkReactor()->isStable())
        {
            _location = d;
            return true;
        }
        else
            return false;
    }
    bool Ship::move(int warp)
    {
        if(warp <= _maxWarp && _core->checkReactor()->isStable())
        {
            _location = _home;
            return true;
        }
        else
            return false;
    }
    bool Ship::move(Destination d)
    {
        if(d != _location && _core->checkReactor()->isStable())
        {
            _location = d;
            return true;
        }
        else
            return false;
    }
    bool Ship::move()
    {
        if(_core->checkReactor()->isStable())
        {
            _location = _home;
            return true;
        }
        else
            return false;
    }

    int Ship::getShield ()
    {
        return _shield;
    }
    void Ship::setShield(int shield)
    {
        _shield = shield;
    }

    int Ship::getWeaponFrequency ()
    {
        return _weaponFrequency;
    }

    void Ship::setWeaponFrequency(int frequency)
    {
        _weaponFrequency = frequency;
    }

    short Ship::getRepair ()
    {
        return _repair;
    }

    void Ship::setRepair(short repair)
    {
        _repair = repair;
    }

    void Ship::fire(Federation :: Starfleet ::Ship *target)
    {
        target->setShield(target->getShield() - _weaponFrequency);
        std::cout << "Firing on target with " <<  _weaponFrequency << "GW frequency." << std::endl;
    }


    void Ship::fire(Federation ::Ship *target)
    {
        target->getCore()->checkReactor()->setStability(false);
        std::cout << "Firing on target with " <<  _weaponFrequency << "GW frequency." << std::endl;
    }

    void Ship::repair ()
    {
        _repair = _repair - 1;
        if (_repair > 0) {
            _shield = 100;
            std::cout << "Begin shield re-initialisation ... Done. Awaiting further instructions." << std::endl;
        }
        else
            std::cout << "Energy cells depleted , shield weakening.";
    }
}