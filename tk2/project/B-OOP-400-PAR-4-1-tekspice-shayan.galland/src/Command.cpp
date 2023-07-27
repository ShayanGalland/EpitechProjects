#include "../include/Command.hpp"
#include <iostream>
#include <limits>

namespace nts {
    Command::Command(Circuit &circuit) : _circuit(circuit)
    {

    }
    void Command::Prompt()
    {
        std::string line;
        std::string previousLine;

        while (true) {
            std::cout << "> ";
            std::getline(std::cin, line);


            if (!line.empty()) {
                Parse_line(line, getCircuit());
            }
            if (std::cin.eof())
                exit(0);
        }
    }

    void Command::Parse_line(std::string line, Circuit& circuit)
    {
        //auto linkConfig = circuit.getConfig().GetLinksConfig();
        auto chipsetConfig = _circuit.getConfig().GetChipsetsConfig();
        bool NoBug = true;

        if (line.find("=") != std::string::npos)
        {
            NoBug = false;
            auto pos = line.find("=");
            std::string input_name = line.substr(0, pos);
            std::string input_value = line.substr(pos + 1);
            for (const auto& chipset : chipsetConfig)
            {
                if (input_name == chipset.first && chipset.second == "input" && (input_value == "1" || input_value == "0" || input_value == "U"))
                    NoBug = true;
            }
            if (NoBug)
                setMode(INPUT_EQUAL_VALUE);
            else
                setMode(UNDEFINED);

        }
        else if (line == "loop")
        {
            if (NoBug)
                setMode(LOOP);
        }
        else if (line == "simulate")
        {
            if (NoBug)
                setMode(SIMULATE);
        }
        else if (line == "display")
        {
            if (NoBug)
                setMode(DISPLAY);
        }
        else if (line == "exit")
        {
            if (NoBug)
                setMode(EXIT);
        }
        else
            setMode(UNDEFINED);
        ApplyMode(circuit, line);
    }
    void Command::ApplyMode(Circuit& circuit, std::string line)
    {
        if (getMode() == EXIT)
            exit(0);
        else if (getMode() == DISPLAY)
            circuit.Display();
        else if (getMode() == SIMULATE)
            circuit.setTick(circuit.getTick() + 1);
        else if (getMode() == INPUT_EQUAL_VALUE) {
            std::string input_name = line.substr(0, line.find("="));
            std::string input_value = line.substr(line.find("=") + 1);
            if (input_value == "1")
                circuit.SetInput(input_name, nts::Tristate::True);
            if (input_value == "0")
                circuit.SetInput(input_name, nts::Tristate::False);
            if (input_value == "U")
                circuit.SetInput(input_name, nts::Tristate::Undefined);

        }
    }
}