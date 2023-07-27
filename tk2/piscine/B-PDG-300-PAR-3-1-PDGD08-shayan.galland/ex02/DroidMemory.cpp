#include "DroidMemory.hpp"
#include <random>

DroidMemory::DroidMemory()
{
    _exp = 0;
    _fingerprint = random();
}
DroidMemory::DroidMemory(const DroidMemory& d)
{
    _exp = d._exp;
    _fingerprint = d._fingerprint;
}

const DroidMemory& DroidMemory::operator=(const DroidMemory& d)
{
    _exp = d._exp;
    _fingerprint = d._fingerprint;
    return (*this);
}
const DroidMemory& DroidMemory::operator<<(DroidMemory& d1)
{
    _exp += d1.getExp();
    _fingerprint = _fingerprint ^ d1.getFingerprint();
    return (*this);
}
const DroidMemory& DroidMemory::operator>>(DroidMemory& d1)
{
    d1.setExp(d1.getExp() + _exp);
    d1.setFingerPrint(d1.getFingerprint() ^ _fingerprint);
    return (*this);
}
const DroidMemory& DroidMemory::operator+=(DroidMemory& d1)
{
    return DroidMemory::operator<<(d1);
}
DroidMemory DroidMemory::operator+(DroidMemory& d1)
{
    DroidMemory d;
    d.setExp(_exp + d1.getExp());
    d.setFingerPrint(_fingerprint ^ d1.getFingerprint());
    return d;
}
const DroidMemory& DroidMemory::operator+=(size_t exp)
{
    _exp += exp;
    _fingerprint = _fingerprint ^ exp;
    return (*this);
}
size_t DroidMemory::getFingerprint() const
{
    return _fingerprint;
}
void DroidMemory::setFingerPrint(size_t fingerprint)
{
    _fingerprint = fingerprint;
}
size_t DroidMemory::getExp() const
{
    return _exp;
}
void DroidMemory::setExp(size_t exp)
{
    _exp = exp;
}

bool DroidMemory::operator==(DroidMemory const &droidMemory) const
{
    if(_exp == droidMemory._exp && _fingerprint == droidMemory._fingerprint)
        return true;
    else
        return false;
}
bool DroidMemory::operator!=(DroidMemory const &droidMemory) const
{
    if(_exp == droidMemory._exp && _fingerprint == droidMemory._fingerprint)
        return false;
    else
        return true;
}

bool DroidMemory::operator>(DroidMemory const &droidMemory) const
{
    if(_exp > droidMemory._exp)
        return true;
    else
        return false;
}
bool DroidMemory::operator<(DroidMemory const &droidMemory) const
{
    if(_exp < droidMemory._exp)
        return true;
    else
        return false;
}
bool DroidMemory::operator<=(DroidMemory const &droidMemory) const
{
    if(_exp <= droidMemory._exp)
        return true;
    else
        return false;
}
bool DroidMemory::operator>=(DroidMemory const &droidMemory) const
{
    if(_exp >= droidMemory._exp)
        return true;
    else
        return false;
}

bool DroidMemory::operator>(const size_t& exp) const
{
    if(_exp > exp)
        return true;
    else
        return false;
}
bool DroidMemory::operator<(const size_t& exp) const
{
    if(_exp < exp)
        return true;
    else
        return false;
}
bool DroidMemory::operator<=(const size_t& exp) const
{
    if(_exp <= exp)
        return true;
    else
        return false;
}
bool DroidMemory::operator>=(const size_t& exp) const
{
    if(_exp >= exp)
        return true;
    else
        return false;
}

std::ostream& operator << (std::ostream& out, DroidMemory const &droidMemory)
{
    out << "DroidMemory '"<< droidMemory.getFingerprint() << "', "<<droidMemory.getExp();
    return (out);
}