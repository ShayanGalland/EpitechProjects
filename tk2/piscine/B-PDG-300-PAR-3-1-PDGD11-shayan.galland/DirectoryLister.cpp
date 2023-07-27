#include "DirectoryLister.hpp"
#include <iostream>
#include <cstring>

DirectoryLister::DirectoryLister() : dir(nullptr), _hidden(false)
{

}

DirectoryLister::DirectoryLister(const std::string& path, bool hidden) : dir(nullptr), _hidden(hidden)
{
    open(path, hidden);
}

DirectoryLister::~DirectoryLister()
{
    if (dir)
        closedir(dir);
}

bool DirectoryLister::open(const std::string& path, bool hidden)
{
    _hidden = hidden;
    if (dir)
        closedir(dir);
    dir = opendir(path.c_str());
    if (!dir) {
        std::perror(path.c_str());
        return false;
    }
    return true;
}

std::string DirectoryLister::get()
{
    if (!dir)
        return "";
    struct dirent* ent;
    while ((ent = readdir(dir)) != nullptr) {
        if (ent->d_name[0] == '.' && !_hidden)
            continue;
        return ent->d_name;
    }
    return "";
}