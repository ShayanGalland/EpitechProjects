#include <ncurses.h>
#include "include/My.hpp"
#include "datas.hpp"
#include <string>

void display_box(int pos_x, int pos_y, int len_x, int len_y)
{
    for (int i = 0; i <= len_x; i+=1) {
        for (int j = 0; j <= len_y; j+=1) {
            mvprintw((LINES / 2) + pos_x + i, (COLS / 2) + pos_y + j, " ");
            if (i == 0 || i == len_x)
                mvprintw((LINES / 2) + pos_x + i, (COLS / 2) + pos_y + j, "-");
            if (j == 0 || j == len_y)
                mvprintw((LINES / 2) + pos_x + i, (COLS / 2) + pos_y + j, "|");
            if ((i == 0 && j == 0) || (i == len_x && j == len_y))
                mvprintw((LINES / 2) + pos_x + i, (COLS / 2) + pos_y + j, "0");
             if ((i == 0 && j == len_y) || (i == len_x && j == 0))
                mvprintw((LINES / 2) + pos_x + i, (COLS / 2) + pos_y + j, "0");
        }
    }
}

void display_module(std::string module_name, std::string module_value, int pos_x, int pos_y)
{
    long unsigned int len_y = std::strlen(module_name.c_str());

    if (std::strlen(module_value.c_str()) > len_y)
        len_y = std::strlen(module_value.c_str());

    display_box(pos_x - 1, pos_y - 1, 4, len_y + 2);
    mvprintw((LINES / 2) + pos_x, (COLS / 2) + pos_y, module_name.c_str());
    mvprintw((LINES / 2) + pos_x + 1, (COLS / 2) + pos_y, module_value.c_str());

}

void ncurse(char **env)
{
    env = env;
    Stats stats;
    int SPACE = 32;

    std::array<int, 4UL> cpuUsagePerCore = stats.get_cpu_usage_per_core();
    std::string cpu_usage_per_core;
    std::string uptime;

    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);
    while (getch() != SPACE) {
        cpu_usage_per_core = "";
        for (long unsigned int i = 0; i < cpuUsagePerCore.size(); i++) {
                cpu_usage_per_core += std::to_string(cpuUsagePerCore[i]);
                if (i < cpuUsagePerCore.size() - 1)
                    cpu_usage_per_core += ", ";
        }
        int uptime_hour = stats.get_up_time() / 3600;
        int uptime_min = (stats.get_up_time() - (uptime_hour * 3600)) / 60;
        int uptime_sec = stats.get_up_time() - (uptime_hour * 3600) - (uptime_min * 60);
        uptime = std::to_string(uptime_hour) + "H, " + std::to_string(uptime_min) + "M, " + std::to_string(uptime_sec)+ "S";
        clear();
        display_module("Kernel:", stats.get_kernel(), -12, -18);
        display_module("CPU Name:", stats.get_cpu_name(), -8, -18);
        display_module("CPU Usage:", std::to_string(stats.get_cpu_usage()), -4, -18);
        display_module("CPU Cores:", std::to_string(stats.get_cpu_cores()), -4, -6);
        display_module("CPU Threads:", std::to_string(stats.get_cpu_threads()), -4, 6);
        display_module("CPU Frequency:", std::to_string(stats.get_cpu_frequency()), 0, -18);
        display_module("CPU Heat:", std::to_string(stats.get_cpu_temperature()), 0, -2);
        display_module("CPU Usage per Core:", cpu_usage_per_core.c_str(), 4, -18);
        display_module("Total RAM:", std::to_string(stats.get_total_ram()), 8, -18);
        display_module("Available RAM:", std::to_string(stats.get_ram_free()), 8, -6);
        display_module("Uptime:", uptime, 12, -18);
        refresh();
    }
    endwin();
}