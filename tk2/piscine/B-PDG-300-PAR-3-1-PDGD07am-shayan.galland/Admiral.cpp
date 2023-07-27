#include "Admiral.hpp"
#include <iostream>

namespace Federation {
    namespace Starfleet {

        Admiral::Admiral(std::string name)
        {
            _name = name;
            std::cout << "Admiral " << _name << " ready for action." << std::endl;
        }

        void Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship* ship, Borg::Ship* target)
        {
            std::cout << "On order from Admiral " << _name << ":" << std::endl;
            (ship->*firePtr)(target);
        }

        bool Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship* ship, Destination dest)
        {
            return (ship->*movePtr)(dest);
        }

    }
}