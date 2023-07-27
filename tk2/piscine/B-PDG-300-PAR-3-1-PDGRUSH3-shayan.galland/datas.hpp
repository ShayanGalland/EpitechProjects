/*
** EPITECH PROJECT, 2023
** Datas
** File description:
** Datas for rush3
*/

#ifndef STATS_HPP
    #define STATS_HPP

#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <sstream>
#include "include/IMonitorDisplay.hpp"
#include "include/IMonitorModule.hpp"

class Stats : public IMonitorModule {
    typedef enum Mode {
            NCURSES,
            GRAPHIC
    } Mode;

    private:
        int cpu_usage;
        int total_ram;
        int cpu_min_frequency;
        int cpu_max_frequency;
    public:
        Stats();
        ~Stats();
        int get_cpu_usage();
        int get_total_ram();
        std::string get_cpu_name();
        int get_cpu_cores();
        int get_cpu_threads();
        std::string get_kernel();
        std::string get_os();
        std::string get_username();
        int get_cpu_frequency();
        int get_cpu_temperature();
        std::array <int, 4> get_cpu_usage_per_core();
        int get_ram_free();
        int ram_disponible();
        int get_up_time();

};

std::ostream operator<<(std::ostream &flux, Stats const &stats);

#endif