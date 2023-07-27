#include "SafeDirectoryLister.hpp"

SafeDirectoryLister::SafeDirectoryLister() : dir(nullptr), _hidden(false)
{
}

SafeDirectoryLister::SafeDirectoryLister(const std::string &path, bool hidden) : dir(nullptr), _hidden(hidden)
{
    open(path, hidden);
}

SafeDirectoryLister::~SafeDirectoryLister()
{
    if (dir)
        closedir(dir);
}

bool SafeDirectoryLister::open(const std::string &path, bool hidden)
{
    _hidden = hidden;
    if (dir)
        closedir(dir);
    dir = opendir(path.c_str());
    if (!dir)
    {
        throw OpenFailureException();
    }

    return true;
}

std::string SafeDirectoryLister::get()
{
    if (!dir)
        throw OpenFailureException();

    struct dirent *ent;
    while ((ent = readdir(dir)) != nullptr)
    {
        if (ent->d_name[0] == '.' && !_hidden)
            continue;
        return ent->d_name;
    }

    throw NoMoreFileException();
}