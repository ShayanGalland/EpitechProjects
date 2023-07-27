#ifndef IDIRECTORY_HPP
#define IDIRECTORY_HPP
#include <string>

class IDirectoryLister
{
public:
    virtual ~IDirectoryLister() {}
    virtual bool open(const std::string &path, bool hidden) = 0;
    virtual std::string get() = 0;

    class OpenFailureException : public std::exception
    {
    public:
        virtual const char *what() const noexcept;
    };

    class NoMoreFileException : public std::exception
    {
    public:
        virtual const char *what() const noexcept;
    };
};

#endif