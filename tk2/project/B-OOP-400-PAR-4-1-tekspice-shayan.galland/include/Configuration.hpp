#ifndef _CONFIGURATION_HPP
#define _CONFIGURATION_HPP

#include <string>
#include <vector>

namespace nts {
    // just so that i dont need to type std::vector<std::pair<std::string, std::string>>, i can only type ChipsetsConfig
    // Pair Name, Type
    typedef std::vector<std::pair<std::string, std::string>> ChipsetsConfig;
    // Pair (NomDeComponent1, Pin1) (NomDeComponent2, Pin2)
    typedef std::vector<std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>>> LinksConfig;

    class Configuration {
    public:
        Configuration(const std::string& config_file);
        ~Configuration();
        void parse_links_part(std::string& line, std::string& name, size_t& pin);
        void parse_configuration();
        void findChipset();
        //get set
        const ChipsetsConfig& GetChipsetsConfig() { return _chipsets; }
        const LinksConfig& GetLinksConfig() { return _links; }
        std::string getConfigfile() { return _config_file; }
        void setChipset(std::string Name) { _chipset_name = Name; }
        const std::string getChipset() { return _chipset_name; }
    private:
        std::string _config_file;
        std::string _chipset_name;
        ChipsetsConfig _chipsets;
        LinksConfig _links;
    };
}

#endif