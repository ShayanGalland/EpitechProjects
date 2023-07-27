#include <string>

class Skat {
    public:
        Skat(const std::string &name = "bob", int stimPaks = 15);
        ~Skat();
        int stimPaks() const;
        const std::string &name() const;
        void shareStimPaks(int number, Skat &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status() const;

    private:
        std::string _name;
        int _stimPaks;
};
