#ifndef _BORG_HPP
#define _BORG_HPP

#include "WarpSystem.hpp"
#include "Federation.hpp"
#include "Destination.hpp"

namespace Borg 
{
    class Ship 
    {
        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core* _core;
            Destination _location;
            Destination _home;

            int _shield; // set to 100 upon construction
            int _weaponFrequency; // provided upon construction
            short _repair; // can be provided. if not , set to 3 upon construction

        public:
            Ship(int weaponFrequency = 20, short repair = 3);
            int getShield ();
            void setShield(int shield);
            int getWeaponFrequency ();
            void setWeaponFrequency(int frequency);
            short getRepair ();
            void setRepair(short repair);

            void setupCore(WarpSystem::Core* core);
            void checkCore();
            bool move(int warp, Destination d); // set _location to d
            bool move(int warp); // set _location to _home
            bool move(Destination d); // set _location to d
            bool move(); // set _location to _home

            void fire(Federation::Starfleet::Ship *target);
            void fire(Federation::Ship *target);
            void repair();

    };
}


#endif