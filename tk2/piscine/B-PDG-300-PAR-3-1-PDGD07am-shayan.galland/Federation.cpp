#include "Federation.hpp"
#include "Borg.hpp"
#include <iostream>

namespace Federation
{
    namespace Starfleet
    {

        void Ship::fire(Borg::Ship *target)
        {
            if (_photonTorpedo != 0) {
                _photonTorpedo -= 1;
                std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
                target->setShield(target->getShield() - 50);
            }
            else
                std::cout << _name << ": No more torpedo to fire , " << _captain->getName() << "!" << std::endl;

        }

        void Ship::fire(int torpedoes , Borg::Ship *target)
        {
            if ((_photonTorpedo - torpedoes) >= 0) {
                _photonTorpedo = _photonTorpedo - torpedoes;
                std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
                target->setShield(target->getShield() - (50 * torpedoes));
            }
            else if (_photonTorpedo != 0)
                std::cout << _name << ": No enough torpedoes to fire , " << _captain->getName() << "!" << std::endl;
            else
                std::cout << _name << ": No more torpedo to fire , " << _captain->getName() << "!" << std::endl;
        }



        Ship::Ship()
        {
            _shield = 100;
            _home = EARTH;
            _location = _home;
            std::cout << "The ship USS Entreprise has been finished." << std::endl;
            std::cout << "It is 289 m in length and 132 m in width.." << std::endl;
            std::cout << "It can go to Warp 6!" << std::endl;
        }

        Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
        {
            _length = length;
            _width = width;
            _name = name;
            _maxWarp = maxWarp;
            _photonTorpedo = torpedo;
            _shield = 100;
            std::cout << "The ship USS "<< _name << " has been finished." << std::endl;
            std::cout << "It is "<< _length << " m in length and "<< _width <<" m in width." << std::endl;
            std::cout << "It can go to Warp "<< _maxWarp <<"!" << std::endl;
            if (torpedo > 0)
                std::cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
        }

        int Ship::getShield ()
        {
            return _shield;
        }

        void Ship::setShield(int shield)
        {
            _shield = shield;
        }

        int Ship::getTorpedo ()
        {
            return _photonTorpedo;
        }

        void Ship::setTorpedo(int torpedo)
        {
            _photonTorpedo = torpedo;
        }

        void Ship::setupCore(WarpSystem::Core* core)
        {
            _core = core;
            std::cout << "USS "<< _name << ": The core is set." << std::endl;
        }

        void Ship::checkCore()
        {
            const char* stableValue = nullptr;
            if(_core->checkReactor()->isStable())
                stableValue = "stable";
            else
                stableValue = "unstable";

            std::cout << "USS "<< _name <<": The core is "<< stableValue <<" at the time." << std::endl;
        }

        void Ship::promote(Captain* captain)
        {
            _captain = captain;
            std::cout << _captain->getName() << ": I'm glad to be the captain of the USS "<< _name << "." << std::endl;
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

        Captain::Captain(std::string name)
        {
            _name = name;
        }
        std::string Captain::getName()
        {
            return _name;
        }
        int Captain::getAge()
        {
            return _age;
        }
        void Captain::setAge(int age)
        {
            _age = age;
        }

        Ensign::Ensign(std::string name)
        {
            _name = name;
            std::cout << "Ensign "<< _name << ", awaiting orders." << std::endl;
        }
    }

    Ship::Ship(int length, int width, std::string name)
    {
        _length = length;
        _width = width;
        _name = name;
        _maxWarp = 1;
        _home = VULCAN;
        _location = _home;

        std::cout << "The independent ship " << _name << " just finished its construction." << std::endl;
        std::cout << "It is "<< _length << " m in length and "<< _width <<" m in width." << std::endl;
    }

    void Ship::setupCore(WarpSystem::Core* core)
    {
        _core = core;
        std::cout << _name << ": The core is set." << std::endl;
    }

    void Ship::checkCore()
    {
        const char* stableValue = nullptr;
        if(_core->checkReactor()->isStable())
            stableValue = "stable";
        else
            stableValue = "unstable";

        std::cout << _name <<": The core is "<< stableValue <<" at the time." << std::endl;
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

    WarpSystem::Core* Ship::getCore()
    {
        return _core;
    }
}
