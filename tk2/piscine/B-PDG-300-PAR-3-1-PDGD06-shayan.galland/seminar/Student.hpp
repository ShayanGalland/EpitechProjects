#include <string>

class Student {
    public:
        Student(std::string name);
        ~Student();
        bool Learn(std::string text);
        void Drink(std::string drink);
        std::string get_student_name();
    private:
        std::string name_;
        int energy_;
};
