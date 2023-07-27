#ifndef _ACOMPONENT_HPP
#define _ACOMPONENT_HPP
#include "../include/IComponent.hpp"
#include <unordered_map>

namespace nts
{
    class AComponent : public IComponent
    {
    public:
        AComponent() = default;
        virtual ~AComponent() = default;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void simulate(std::size_t tick) { (void)tick; };
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        nts::Tristate getLink(std::size_t pin) const;

    private:
        std::unordered_map<std::size_t, std::pair<nts::IComponent*, std::size_t >> _linkedComponents;
    };
}

#endif