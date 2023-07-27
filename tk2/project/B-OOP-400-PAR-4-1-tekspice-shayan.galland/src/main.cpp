#include "../include/Circuit.hpp"
#include "../include/IComponent.hpp"
#include "../include/Command.hpp"
#include "../include/Configuration.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Need to pass configuration in argv" << std::endl;
        return 84;
    }

    std::string config_file(argv[1]);
    
    nts::Configuration config(config_file);
    config.parse_configuration();                               //add all links and chipset to the class Configuration

    nts::Circuit circuit(config);
    circuit.init_circuit();

    nts::Command prompt(circuit);
    prompt.Prompt();

    return 0;
}