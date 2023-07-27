#include "../include/Configuration.hpp"
#include <fstream>
#include <exception>
#include <iostream>
#include <sstream>
#include <vector>

namespace nts
{
    Configuration::Configuration(const std::string &config_file) : _config_file(config_file) {}
    Configuration::~Configuration() {}

    void Configuration::parse_configuration()
    {
        std::fstream fs(_config_file, std::ios_base::in);

        if (!fs.is_open())
            exit (84);

        bool comment_section = false;
        bool chipset_section = false;
        bool links_section = false;
        bool first_parsed = false;
        bool seek_comment = false;

        std::string chipset_type;
        std::string chipset_name;
        std::string component_name_1;
        std::size_t component_pin_1;
        std::string component_name_2;
        std::size_t component_pin_2;

        while (!fs.eof())
        {
            std::string line;
            fs >> line;

            if (line.find('#') != line.npos) {
                comment_section = true;
                //if the # is joint to the line
                if (line.find("#") != 0) {
                    comment_section = false;
                    seek_comment = true;
                    line = line.substr(0, line.find("#"));
                    if (line.find(".chipsets:") != line.npos) {
                        links_section = false;
                        chipset_section = true;
                    }
                    if (line.find(".links:") != line.npos) {
                        chipset_section = false;
                        links_section = true;
                    }
                }
                //continue
            }
            else if (line.find(".chipsets:") != line.npos) {
                links_section = false;
                chipset_section = true;
            }
            else if (line.find(".links:") != line.npos) {
                chipset_section = false;
                links_section = true;
            }
            if (!comment_section) {
                if (chipset_section) {
                    if (!first_parsed) {
                        chipset_type = line;
                        first_parsed = true;
                    }
                    else {
                        chipset_name = line;
                        first_parsed = false;
                        _chipsets.push_back(std::make_pair(chipset_name, chipset_type));
                    }
                }
                else if (links_section) {
                    if (!first_parsed) {
                        parse_links_part(line, component_name_1, component_pin_1);
                        first_parsed = true;
                    }
                    else {
                        parse_links_part(line, component_name_2, component_pin_2);
                        first_parsed = false;

                        _links.push_back(std::make_pair(std::make_pair(component_name_1, component_pin_1), std::make_pair(component_name_2, component_pin_2)));
                    }
                }
            }


            //seek new lines
            if (fs.peek() == '\n' || seek_comment) {
                comment_section = false;
                first_parsed = false;
                seek_comment = false;
            }
        }
        fs.close();
    }

    bool isInteger(const std::string & s)
    {
        if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
            return false;
        char * p;
        strtol(s.c_str(), &p, 10);
        return (*p == 0);
    }

    void Configuration::parse_links_part(std::string& line, std::string& name, size_t& pin)
    {
        std::size_t pos = line.find(":");
        name = line.substr(0, pos);
        if (line.substr(pos+1) == "" && line != ".links:" && line != "")
            exit(84);
        if (!isInteger(line.substr(pos+1)) && line != ".links:" && line != "")
            exit(84);

        std::stringstream s(line.substr(pos+1));
        s >> pin;
    }

    void Configuration::findChipset()
    {
        auto linkConfig = GetLinksConfig();
        auto chipsetConfig = GetChipsetsConfig();

        Configuration config(getConfigfile());

        std::vector<std::string> Chipsets =
        {
            "input",
            "output",
            "true",
            "false",
            "clock",
            "and",
            "or",
            "xor",
            "not",
            "4001",
            "4011",
            "4030",
            "4069",
            "4071",
            "4081",
            "4008",
            "4013",
            "4017",
            "4040",
            "4094",
            "4512",
            "4514",
            "4801",
            "2716"
        };
        for (const auto& chipset : chipsetConfig)
        {
            for(int i = 0; i < Chipsets.size(); i++) {
                if (Chipsets[i] == chipset.second)
                    setChipset(chipset.second);
            }
        }
    }
}
