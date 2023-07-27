#include <iostream>
#include <memory>
#include "Toy.hpp"
#include "Picture.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"

int main()
{
Toy toto;
    Toy ET(Toy::ALIEN , "green", "./ alien.txt");
    toto.setName("TOTO !");
    if (toto.getType () == Toy:: BASIC_TOY)
        std::cout << "basic toy: " << toto.getName () << std::endl
                  << toto.getAscii () << std::endl;
    if (ET.getType () == Toy:: ALIEN)
        std::cout << "this alien is: " << ET.getName () << std::endl
                  << ET.getAscii () << std::endl;
    
    Buzz b("buzz");
    std::cout << "Buzz name: " << b.getName() << std::endl;
    std::cout << "Buzz type: " << b.getType() << std::endl;
    std::cout << "Buzz ascii: " << b.getAscii() << std::endl;
    
    Woody w("woody", "./woody.txt");
    std::cout << "Woody name: " << w.getName() << std::endl;

}