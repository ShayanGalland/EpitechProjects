/*
** EPITECH PROJECT, 2023
** IMonitorModule
** File description:
** IMonitorModule for rush3
*/

#ifndef IMONITORMODULE_HPP
    #define IMONITORMODULE_HPP

class IMonitorModule {
    public:
        virtual ~IMonitorModule() = default;
        virtual void refresh() = 0;
};

#endif