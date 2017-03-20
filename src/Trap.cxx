
#include <list>
#include <sstream>

#include "Character.hxx"
#include "Location.hxx"


std::string Trap::use(Character * c , Location * l){
	c->damage(5);
return Decorator::use(c,l) + c->name() + " takes 5 damage\n" ;
}

		std::string Trap::receiveMagic(unsigned int magic){
			return Decorator::receiveMagic(magic);						
		}
