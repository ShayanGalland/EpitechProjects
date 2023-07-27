#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Borg.hpp"
#include "Admiral.hpp"
#include "Destination.hpp"
#include "BorgQueen.hpp"
#include <iostream>


int main ()
{
/*
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
    Federation::Ship Independent(150, 230, "Greok");
    WarpSystem::QuantumReactor QR;
    WarpSystem::QuantumReactor QR2;
    WarpSystem::Core core(&QR);
    WarpSystem::Core core2(&QR2);
    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    Independent.setupCore(&core2);
    Independent.checkCore();
    QR.setStability(false);
    QR2.setStability(false);
    UssKreog.checkCore();
    Independent.checkCore();
*/




Federation :: Starfleet ::Ship UssKreog (289, 132, "Kreog", 6);
Federation :: Starfleet :: Captain James("James T. Kirk");
Federation :: Starfleet :: Ensign Ensign("Pavel Chekov");
WarpSystem :: QuantumReactor QR;
WarpSystem :: QuantumReactor QR2;
WarpSystem ::Core core(&QR);
WarpSystem ::Core core2 (&QR2);
UssKreog.setupCore (&core);
UssKreog.checkCore ();
UssKreog.promote (&James);
Borg::Ship Cube;
Cube.setupCore (& core2);
Cube.checkCore ();

    Borg::Ship Bube(20, 5);

    Federation::Starfleet::Ship Lambda;
    Cube.fire(&UssKreog);
    std::cout << Bube.getRepair() << std::endl;
    UssKreog.fire(2, &Bube);


    std::cout << Bube.getRepair() << std::endl;
    std::cout << Bube.getShield();*/





    //Federation::Starfleet::Admiral admiral("test");
    //Federation :: Starfleet ::Ship UssKreog (289, 132, "Kreog", 6);

//Exam e = Exam(&Exam:: cheat);
//e.kobayashiMaru = &Exam::start;
//(e.*e.kobayashiMaru)(3);
//Exam::cheat = true;
//if (e.isCheating ())
//(e.*e.kobayashiMaru)(4);
//    return 0;
}
