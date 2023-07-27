#include "../include/AComponent.hpp"

namespace nts
{
    void AComponent::setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin)
    {
        _linkedComponents[pin] = std::make_pair(&other, otherPin);
    }
    nts::Tristate AComponent::getLink(std::size_t pin) const
    {
        auto value = _linkedComponents.at(pin);
        return value.first->compute(value.second);
    }
}