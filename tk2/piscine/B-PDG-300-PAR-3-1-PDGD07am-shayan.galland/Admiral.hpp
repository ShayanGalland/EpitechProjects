#ifndef ADMIRAL_HPP
#define ADMIRAL_HPP
#include <string>
#include "Federation.hpp"
#include "Borg.hpp"

namespace Federation {
    namespace Starfleet {
        class Admiral {

            typedef bool (Federation::Starfleet::Ship::*MoveMethod)(Destination);
            typedef void (Federation::Starfleet::Ship::*FireMethod)(Borg::Ship*);
            std:: string _name;

            public:
                Admiral(std::string name);
                MoveMethod movePtr;
                FireMethod firePtr;
                
                void fire(Federation :: Starfleet ::Ship *ship , Borg::Ship *target);
                bool move(Federation :: Starfleet ::Ship *ship , Destination dest);
        };
    }
}

#endif
