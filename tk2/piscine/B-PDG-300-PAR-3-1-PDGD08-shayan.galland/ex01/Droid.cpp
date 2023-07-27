#include "Droid.hpp"

std::ostream& operator << (std::ostream& out, Droid const &droid)
{
    out << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
    return (out);
}

Droid::Droid(std::string id) : _attack(25), _toughness(15)
{
    _energy = 50;
    _status = new std::string("Standing by");
    _id = id;
    _battleData = new DroidMemory();
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &droid) : _attack(25), _toughness(15)
{
    _id = droid.getId();
    _energy = droid.getEnergy();
    _status = new std::string(*droid.getStatus());
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
    delete _status;
}

bool Droid::operator==(Droid const &droid) const
{
    if (_status->compare(*droid.getStatus()) == 0)
        return (true);
    else
        return (false);
}

bool Droid::operator!=(Droid const &droid) const
{
    if (_status->compare(*droid.getStatus()) == 0)
        return (false);
    else
        return (true);
}

Droid& Droid::operator<<(size_t &reload)
{
    size_t temp;

    if (_energy >= 100) {
        _energy = 100;
        return (*this);
    }
    if ((_energy + reload) > 100)
        temp = 100 - _energy;
    else
        temp = reload;
    _energy += temp;
    reload -= temp;
    return (*this);
}

Droid &Droid::operator=(Droid const &droid)
{
    if (this != &droid) {
        _id = droid.getId();
        _energy = droid.getEnergy();
        if (_status) {
            delete _status;
        }
        _status = new std::string(*droid.getStatus());
    }
    return (*this);
}

std::string Droid::getId() const
{
    return (_id);
}

void Droid::setId(std::string id)
{
     _id = id;
}

size_t Droid::getEnergy() const
{
    return (_energy);
}

void Droid::setEnergy(size_t energy)
{
    if (energy <= 100)
        _energy = energy;
}

std::string *Droid::getStatus() const
{
    return (_status);
}

void Droid::setStatus(std::string *status)
{
    if (_status != nullptr)
        delete _status;
    _status = status;
}

size_t Droid::getAttack() const
{
    return (_attack);
}

size_t Droid::getToughness() const
{
    return (_toughness);
}

DroidMemory* Droid::GetBattleData() 
{ 
    return _battleData; 
}
void Droid::SetBattleData(DroidMemory * battleData) 
{ 
    _battleData = battleData; 
}