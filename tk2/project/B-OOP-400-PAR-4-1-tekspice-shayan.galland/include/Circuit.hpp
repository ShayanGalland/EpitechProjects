#ifndef _CIRCUIT_HPP
#define _CIRCUIT_HPP

#include "IComponent.hpp"
#include "Configuration.hpp"
#include <memory>
#include <unordered_map>

namespace nts
{
    class Circuit
    {
        public:
            Circuit(Configuration &configuration) : _config(configuration), _tick(0) {}
            ~Circuit() = default;

            void init_circuit();

            std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
            void Display();
            void SetInput(std::string input_name, nts::Tristate value);

            Configuration &getConfig() {return _config;}
            void setTick(int tick) {_tick = tick;}
            int getTick() {return _tick;}
        private:
            Configuration &_config;
            std::size_t _tick;

            std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> _components;
    };
}

#endif