#include "WarpSystem.hpp"

namespace WarpSystem
{
    QuantumReactor::QuantumReactor()
    {
        _stability = true;
    }
    void QuantumReactor::setStability(bool stability)
    {
        _stability = stability;
    }
    bool QuantumReactor::isStable()
    {
        return _stability;
    }

    Core::Core(QuantumReactor* quantumReactor)
    {
        _coreReactor = quantumReactor;
    }
    QuantumReactor* Core::checkReactor()
    {
        return _coreReactor;
    }
}