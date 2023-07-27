#include "Algorithm.hpp"
#include <iostream>
#include <string>

int main(void)
{
    int a = 42;
int b = 21;
::swap(a, b);
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
std::cout << "clamp(0, a, b) = " << :: clamp(0, a, b) << std::endl;
std:: string c = "ghi";
std:: string d = "abc";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
std::cout << "clamp (\"def\", c, d) = " << :: clamp(std:: string("def"), c, d) <<
std::endl;
    std::cout << clamp(33, 33, 66);
return 0;

}