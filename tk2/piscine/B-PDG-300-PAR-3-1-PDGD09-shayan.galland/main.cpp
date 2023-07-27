#include "Peasant.hpp"
#include "Knight.hpp"
#include "Enchanter.hpp"
#include "Priest.hpp"
#include "Paladin.hpp"
#include "ICharacter.hpp"
#include "HealthPotion.hpp"
#include "PoisonPotion.hpp"
#include "PowerPotion.hpp"
#include "IPotion.hpp"


int main(void)
{/*
Peasant peasant("Gildas", 42);
std::cout << peasant.getHp() << std::endl;
peasant.damage (12);
std::cout << peasant.getHp() << std::endl;
std::cout << peasant.getPower() << std::endl;
peasant.attack();
std::cout << peasant.getPower() << std::endl;

peasant.rest();
peasant.rest();
peasant.rest();
std::cout << peasant.getPower() << std::endl;

peasant.attack();*/

/*
Knight knight("Arthur", 20);
knight.attack ();
knight.special ();
knight.rest();
//std::cout << knight.getPower() << std::endl;
knight.special ();
//std::cout << knight.getPower() << std::endl;
knight.damage (50);
*/

/*
Enchanter enchanter("Merlin", 20);
enchanter.attack ();
enchanter.special ();
enchanter.rest();
enchanter.special ();
enchanter.damage (50);*/

/*
Priest priest("Trichelieu", 20);
priest.attack ();
priest.special ();
priest.rest();
priest.damage (50);*/



//Paladin paladin("Uther", 99);
//paladin.attack ();
//paladin.special ();
//paladin.rest();
//paladin.damage(50);
//Paladin *paladin = new Paladin("Uther", 99);




/*
ICharacter *peasant = new Peasant("Gildas", 42);
ICharacter *knight = new Knight("Arthur", 20);
ICharacter *enchanter = new Enchanter("Merlin", 20);
ICharacter *priest = new Priest("Trichelieu", 20);
ICharacter *paladin = new Paladin("Uther", 99);
peasant ->attack ();
knight ->special ();
enchanter ->rest();
priest ->damage (21);
std::cout << paladin ->getName () << ": "
<< paladin ->getHp() << " health points , "
<< paladin ->getPower () << " power points."
<< std::endl;
delete peasant;
delete knight;
delete enchanter;
delete priest;
delete paladin;*/

ICharacter *peasant = new Peasant("Gildas", 42);
PoisonPotion poison_potion;
HealthPotion health_potion;
IPotion& potion = health_potion;
std::cout << peasant ->getName () << ": " << peasant ->getHp () << "HP, "
<< peasant ->getPower () << " PP." << std::endl;
peasant ->drink(poison_potion);
std::cout << peasant ->getName () << ": " << peasant ->getHp () << "HP, "
<< peasant ->getPower () << " PP." << std::endl;
peasant ->drink(potion);
std::cout << peasant ->getName () << ": " << peasant ->getHp () << "HP, "
<< peasant ->getPower () << " PP." << std::endl;
delete peasant;
}