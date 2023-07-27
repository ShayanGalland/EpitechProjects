#ifndef _COMMAND_HPP
#define _COMMAND_HPP
#include "Configuration.hpp"
#include "Circuit.hpp"

namespace nts
{
    enum Functions {
            UNDEFINED,
            EXIT,
            DISPLAY,
            INPUT_EQUAL_VALUE,
            SIMULATE,
            LOOP
    };
    class Command {
        public:
            Command(Circuit &circuit);
            ~Command() = default;
            void Prompt();
            void Parse_line(std::string line, Circuit &circuit);
            void ApplyMode(Circuit& circuit, std::string line);

            Circuit &getCircuit() {return _circuit;}
            size_t getMode() {return Mode;}
            void setMode(size_t mode) {Mode = mode;}
        private:
            size_t Mode;
            Circuit &_circuit;
    };
}
#endif