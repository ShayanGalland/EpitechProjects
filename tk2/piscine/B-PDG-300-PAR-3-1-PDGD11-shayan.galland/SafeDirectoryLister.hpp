#ifndef SAFEDIRECTORYLISTER_HPP
#define SAFEDIRECTORYLISTER_HPP

#include <exception>
#include <string>
#include <iostream>
#include <dirent.h>

#include "IDirectoryLister.hpp"

class SafeDirectoryLister : public IDirectoryLister
{
public:
    SafeDirectoryLister();
    explicit SafeDirectoryLister(const std::string &path, bool hidden);
    ~SafeDirectoryLister();
    bool open(const std::string &path, bool hidden) override;
    std::string get() override;

private:
    DIR *dir;
    bool _hidden;
    SafeDirectoryLister(const SafeDirectoryLister &) = delete;
    SafeDirectoryLister &operator=(const SafeDirectoryLister &) = delete;
    SafeDirectoryLister(SafeDirectoryLister &&) = delete;
    SafeDirectoryLister &operator=(SafeDirectoryLister &&) = delete;
};

#endif
