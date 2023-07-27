/*
** EPITECH PROJECT, 2023
** Proc
** File description:
** Parsing proc for rush3
*/

#include "datas.hpp"

Stats::Stats()
{
    this->cpu_usage = 0;
    this->total_ram = 0;
    this->cpu_min_frequency = 2000;
    this->cpu_max_frequency = 3000;
}

Stats::~Stats()
{
}

int Stats::get_cpu_usage()
{
    std::ifstream fileStream("/proc/stat");
    if (!fileStream.is_open()) {
        std::cerr << "No such files or directory for stat" << std::endl;
        return -1;
    } else {
        std::string line;
        while (std::getline(fileStream, line)) {
            if (line.find("cpu") != std::string::npos) {
                return std::stoi(line.substr(5, 6));
                break;
            }
        }
    }
    return 0;
}

int Stats::get_total_ram()
{
    std::ifstream fileStream("/proc/meminfo");
    if (!fileStream.is_open()) {
        std::cerr << "No such files or directory for meminfo" << std::endl;
        return -1;
    } else {
        std::string line;
        while (std::getline(fileStream, line)) {
            if (line.find("MemTotal") != std::string::npos) {
                return std::stoi(line.substr(10, 11));
                break;
            }
        }
    }
    return 0;
}

std::string Stats::get_cpu_name()
{
    std::ifstream fileStream("/proc/cpuinfo");
    if (!fileStream.is_open()) {
        std::cerr << "No such files or directory for cpuinfo" << std::endl;
    } else {
        std::string line;
        while (std::getline(fileStream, line)) {
            if (line.find("model name") != std::string::npos) {
                return line.substr(13, 27);
                break;
            }
        }
    }
    return "No such informations";
}

int Stats::get_cpu_cores()
{
    std::ifstream fileStream("/proc/cpuinfo");
    if (!fileStream.is_open()) {
        std::cerr << "No such files or directory for cpuinfo" << std::endl;
    } else {
        std::string line;
        while (std::getline(fileStream, line)) {
            if (line.find("cpu cores") != std::string::npos) {
                return std::stoi(line.substr(11, 12));
                break;
            }
        }
    }
    return 0;
}

int Stats::get_cpu_threads()
{
    std::ifstream fileStream("/proc/cpuinfo");
    if (!fileStream.is_open()) {
        std::cerr << "No such files or directory for cpuinfo" << std::endl;
    } else {
        std::string line;
        while (std::getline(fileStream, line)) {
            if (line.find("cpu cores") != std::string::npos) {
                return std::stoi(line.substr(11, 12));
                break;
            }
        }
    }
    return 0;
}

std::string Stats::get_kernel()
{
    std::ifstream fileStream("/proc/version");
    if (!fileStream.is_open()) {
        std::cerr << "No such files or directory for version" << std::endl;
    } else {
        std::string line;
        while (std::getline(fileStream, line)) {
            if (line.find("Linux version") != std::string::npos) {
                return line.substr(0, 37);
                break;
            }
        }
    }
    return "No such informations";
}

int Stats::get_cpu_frequency()
{
    std::ifstream fileStream("/proc/cpuinfo");
    if (!fileStream.is_open()) {
        std::cerr << "No such files or directory for cpuinfo" << std::endl;
    } else {
        std::string line;
        while (std::getline(fileStream, line)) {
            if (line.find("cpu MHz") != std::string::npos) {
                return std::stoi(line.substr(11, 12));
                break;
            }
        }
    }
    return 0;
}

int Stats::get_cpu_temperature()
{
    std::ifstream fileStream("/sys/class/thermal/thermal_zone1/temp");
    if (!fileStream.is_open()) {
        std::cerr << "No such files or directory for temp" << std::endl;
    } else {
        std::string line;
        while (std::getline(fileStream, line)) {
                return std::stoi(line) / 1000;
        }
    }
    return 0;
}

std::array <int, 4> Stats::get_cpu_usage_per_core()
{
    std::ifstream fileStream("/proc/stat");
    if (!fileStream.is_open()) {
        std::cerr << "No such files or directory for stat" << std::endl;
    } else {
        std::string line;
        while (std::getline(fileStream, line)) {
            if (line.find("cpu") != std::string::npos) {
                std::array <int, 4> cpu_usage;
                cpu_usage[0] = std::stoi(line.substr(5, 6));
                cpu_usage[1] = std::stoi(line.substr(13, 14));
                cpu_usage[2] = std::stoi(line.substr(21, 22));
                cpu_usage[3] = std::stoi(line.substr(29, 30));
                return cpu_usage;
                break;
            }
        }
    }
    return {0, 0, 0, 0};
}

int Stats::get_ram_free()
{
    std::ifstream fileStream("/proc/meminfo");
    if (!fileStream.is_open()) {
        std::cerr << "No such files or directory for meminfo" << std::endl;
    } else {
        std::string line;
        while (std::getline(fileStream, line)) {
            if (line.find("MemFree") != std::string::npos) {
                return std::stoi(line.substr(10, 11));
                break;
            }
        }
    }
    return 0;
}

int Stats::ram_disponible()
{
    Stats stats;
    stats.get_total_ram();
    stats.get_ram_free();
    return get_ram_free() - get_total_ram();
}

int Stats::get_up_time()
{
    std::ifstream fileStream("/proc/uptime");
    if (!fileStream.is_open()) {
        std::cerr << "No such files or directory for uptime" << std::endl;
    } else {
        std::string line;
        while (std::getline(fileStream, line)) {
            return std::stoi(line);
            break;
        }
    }
    return 0;
}

/*
int main()
{
    Stats stats;
    stats.get_cpu_usage();
    stats.get_total_ram();
    stats.get_cpu_name();
    stats.get_cpu_cores();
    stats.get_cpu_threads();
    stats.get_kernel();
    stats.get_cpu_frequency();
    stats.get_cpu_temperature();
    stats.get_cpu_usage_per_core();
    stats.get_ram_free();
    stats.get_up_time();
    std::cout << stats.get_cpu_usage() << std::endl;
    std::cout << stats.get_total_ram() << std::endl;
    std::cout << stats.get_cpu_name() << std::endl;
    std::cout << stats.get_cpu_cores() << std::endl;
    std::cout << stats.get_cpu_threads() << std::endl;
    std::cout << stats.get_kernel() << std::endl;
    std::cout << stats.get_cpu_frequency() << std::endl;
    std::cout << stats.get_cpu_temperature() << std::endl;
    std::cout << stats.get_cpu_usage_per_core()[0] << std::endl;
    std::cout << stats.get_cpu_usage_per_core()[1] << std::endl;
    std::cout << stats.get_cpu_usage_per_core()[2] << std::endl;
    std::cout << stats.get_cpu_usage_per_core()[3] << std::endl;
    std::cout << stats.get_total_ram() << std::endl;
    std::cout << stats.get_up_time() << std::endl;
    return 0;
}*/