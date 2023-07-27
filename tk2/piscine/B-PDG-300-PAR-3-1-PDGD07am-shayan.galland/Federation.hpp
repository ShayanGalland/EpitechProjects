#ifndef _FEDERATION_HPP
#define _FEDERATION_HPP

#include "Destination.hpp"
#include "WarpSystem.hpp"

#include <string>
namespace Borg {
    class Ship;
}
namespace Federation
{
    namespace Starfleet
    {
        class Captain;
        class Ensign;
        class Ship
        {
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core* _core;
                Captain* _captain;

                Destination _location;
                Destination _home;

                int _shield;
                int _photonTorpedo;

            public:
                Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
                Ship();

                void fire(Borg::Ship *target);
                void fire(int torpedoes , Borg::Ship *target);
                int getShield ();
                void setShield(int shield);
                int getTorpedo ();
                void setTorpedo(int torpedo);

                void setupCore(WarpSystem::Core* core);
                void checkCore();
                void promote(Captain* captain);
                bool move(int warp, Destination d); // set _location to d
                bool move(int warp); // set _location to _home
                bool move(Destination d); // set _location to d
                bool move(); // set _location to _home

        };

        class Captain
        {
            private:
                std::string _name;
                int _age;

            public:
                Captain(std::string name);
                std::string getName();
                int getAge();
                void setAge(int age);
        };

        class Ensign
        {
            private:
                std::string _name ;

            public:
                Ensign(std::string name);
        };
    }

    class Ship
    {
        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core* _core;
            Destination _location;
            Destination _home;

        public:
            WarpSystem::Core* getCore();
            Ship(int length, int width, std::string name);
            void setupCore(WarpSystem::Core* core);
            void checkCore();

            bool move(int warp, Destination d); // set _location to d
            bool move(int warp); // set _location to _home
            bool move(Destination d); // set _location to d
            bool move(); // set _location to _home

    };
}

#endif