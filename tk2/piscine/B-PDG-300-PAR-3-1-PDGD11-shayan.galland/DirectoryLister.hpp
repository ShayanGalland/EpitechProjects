#ifndef DIRECTORYLISTER_HPP
#define DIRECTORYLISTER_HPP

#include "IDirectoryLister.hpp"
#include <dirent.h>
#include <string>

class DirectoryLister : public IDirectoryLister
{
public:
    DirectoryLister();
    explicit DirectoryLister(const std::string &path, bool hidden);
    ~DirectoryLister();
    bool open(const std::string &path, bool hidden) override;
    std::string get() override;

private:
    DIR *dir;
    bool _hidden;
    DirectoryLister(const DirectoryLister &) = delete;
    DirectoryLister &operator=(const DirectoryLister &) = delete;
    DirectoryLister(DirectoryLister &&) = delete;
    DirectoryLister &operator=(DirectoryLister &&) = delete;
};

#endif