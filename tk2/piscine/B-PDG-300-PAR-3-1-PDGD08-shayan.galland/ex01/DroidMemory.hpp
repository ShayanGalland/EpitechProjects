#ifndef _DROID_MEMORY_HPP
#define _DROID_MEMORY_HPP

#include <ostream>

class DroidMemory {
private:
    size_t _fingerprint;
    size_t _exp;

public:
    DroidMemory();
    DroidMemory(const DroidMemory& d);

    size_t getFingerprint() const;
    void setFingerPrint(size_t fingerprint);
    size_t getExp() const;
    void setExp(size_t exp);
    const DroidMemory& operator<<(DroidMemory& d1);
    const DroidMemory& operator>>(DroidMemory& d1);
    const DroidMemory& operator+=(DroidMemory& d1);
    const DroidMemory& operator+=(size_t exp);
    DroidMemory operator+(DroidMemory& d1);
};

std::ostream& operator << (std::ostream& out, DroidMemory const &droidMemory);

#endif