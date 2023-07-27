#include "IDirectoryLister.hpp"

#include <string.h>

const char *IDirectoryLister::OpenFailureException::what() const noexcept
{
    return strerror(errno);
}

const char *IDirectoryLister::NoMoreFileException::what() const noexcept
{
    return "End of stream";
}