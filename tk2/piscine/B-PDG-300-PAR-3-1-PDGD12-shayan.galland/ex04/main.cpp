#include <iostream>
#include "Toy.hpp"

int main()
{
Toy a(Toy::BASIC_TOY , "REX", "rex.txt");
std::cout << a;
a << "\\o/";
std::cout << a;

a << "test1" << "test2";
}
