#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <string>

class IMonitorModule {
    public:
        IMonitorModule() {};
        virtual ~IMonitorModule() {};
        std::string content;
        std::string name;
        bool enable = true;
};

#endif