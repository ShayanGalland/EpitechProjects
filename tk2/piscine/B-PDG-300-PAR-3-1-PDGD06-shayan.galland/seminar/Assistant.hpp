#include <string>
#include <iostream>
#include <iostream>
#include <fstream>
#include "Student.hpp"
#include "Student.cpp"

class Assistant {
    public:
        Assistant(int id);
        ~Assistant();
        void giveDrink(std::string str, Student *student);
        std::string get_student(Student *student);
        std::string readDrink(std::string name);
    private:
        int id_;
};

std::string Assistant::get_student(Student *student)
{
    return student->get_student_name();
}


Assistant::Assistant(int id)
{
    id_ = id;
    std::cout << "Assistant " << id_ << ": 'morning everyone *sip coffee*" << std::endl;
}

Assistant::~Assistant()
{
    std::cout << "Assistant " << id_ << " see you tomorrow at 9.00 *sip coffee*" << std::endl;
}

void Assistant::giveDrink(std::string str, Student *student)
{
    std::cout << "Assistant " << id_ << ": drink this ," << get_student(student) << "*sip coffee*" << std::endl;
    student->Drink(str);
}

std::string Assistant::readDrink(std::string name)
{
    std::string fileName = name + ".drink";
    std::string content;
    std::ifstream file;

    file.open(fileName);
    if (file.good()) {
        file >> content;
        std::cout << "Assistant " << id_ << ": " << name << " needs a " << content << " sip coffee" << std::endl;
        remove(fileName.c_str());
        return content;
    } else
        return "";
}

