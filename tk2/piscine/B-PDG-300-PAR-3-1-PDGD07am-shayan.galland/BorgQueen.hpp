#ifndef BORGQUEEN_HPP
#define BORGQUEEN_HPP
#include <string>
#include "Federation.hpp"
#include "Borg.hpp"

namespace Borg {
    class Ship;
    class BorgQueen {
        typedef bool (Borg::Ship::*MoveMethod)(Destination);
        typedef void (Borg::Ship::*FireMethod)(Federation::Starfleet::Ship*);
        typedef void (Borg::Ship::*DestroyMethod)(Federation::Ship*);

        public:
            bool move(Borg::Ship *ship , Destination dest);
            void fire(Borg::Ship *ship , Federation :: Starfleet ::Ship *target);
            void destroy(Borg::Ship *ship , Federation ::Ship *target);
            MoveMethod movePtr;
            FireMethod firePtr;
            DestroyMethod destroyPtr;

  };
}

#endif