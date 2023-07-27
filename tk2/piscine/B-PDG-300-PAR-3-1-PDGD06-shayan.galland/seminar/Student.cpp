#include <iostream>
#include "Student.hpp"

Student::Student(std::string name)
{
    name_ = name;
    energy_ = 100;
    std::cout << "Student " << name_ << ": I'm ready to learn C++." << std::endl;
}

Student::~Student()
{
    std::cout << "Student " << name_ << ": Wow, much learning today, very smart, such C++." << std::endl;
}

bool Student::Learn(std::string text)
{
    if (energy_ < 42) {
        std::size_t pos = text.find("C++"); //trouver la position de C++ dans le les textes
        while (pos != std::string::npos) { //n pos est un peu comme strlen
            text.replace(pos, 3, "shit");
            pos = text.find("C++");
        }
        std::cout << "Student " << name_ << ": " << text << std::endl;
        return false;
    }
    energy_ -= 42;
    std::cout << "Student " << name_ << ": " << text << std::endl;
    return true;
}

void Student::Drink(std::string drink)
{
    if (drink == "Red Bull") {
        std::cout << "Student " << name_ << ": Red Bull gives you wings!" << std::endl;
        energy_ += 32;
    } else if (drink == "Monster") {
        std::cout << "Student " << name_ << ": Unleash The Beast!" << std::endl;
        energy_ += 64;
    } else {
        std::cout << "Student " << name_ << ": ah, yes... enslaved moisture." << std::endl;
        energy_ += 1;
    }
    if (energy_ > 100) {
        energy_ = 100;
    }
}

std::string Student::get_student_name()
{
    return name_;
}


int main() {
  Student student("John");
  student.Learn("I'm learning C++!");
  student.Drink("Red Bull");
  student.Learn("I'm still learning C++!");
  student.Drink("Monster");
  student.Learn("I'm almost done learning C++!");
  student.Drink("Water");
  student.Learn("I'm done with C++!");
  return 0;
}
