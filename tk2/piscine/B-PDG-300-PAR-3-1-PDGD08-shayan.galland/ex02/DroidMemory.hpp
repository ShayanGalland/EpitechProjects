#ifndef _DROID_MEMORY_HPP
#define _DROID_MEMORY_HPP
#include <ostream>

class DroidMemory {
    size_t _fingerprint;
    size_t _exp;

public:
    DroidMemory();
    DroidMemory(const DroidMemory& d);
    const DroidMemory& operator=(const DroidMemory& d);
    size_t getFingerprint() const;
    void setFingerPrint(size_t fingerprint);
    size_t getExp() const;
    void setExp(size_t exp);
    const DroidMemory& operator<<(DroidMemory& d1);
    const DroidMemory& operator>>(DroidMemory& d1);
    const DroidMemory& operator+=(DroidMemory& d1);
    const DroidMemory& operator+=(size_t exp);
    DroidMemory operator+(DroidMemory& d1);
    bool operator==(DroidMemory const &droidMemory) const;
    bool operator!=(DroidMemory const &droidMemory) const;
    bool operator>(DroidMemory const &droidMemory) const;
    bool operator<(DroidMemory const &droidMemory) const;
    bool operator<=(DroidMemory const &droidMemory) const;
    bool operator>=(DroidMemory const &droidMemory) const;
    bool operator>(const size_t& exp) const;
    bool operator<(const size_t& exp) const;
    bool operator<=(const size_t& exp) const;
    bool operator>=(const size_t& exp) const;
};

std::ostream& operator << (std::ostream& out, DroidMemory const &droidMemory);

#endif