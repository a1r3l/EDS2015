
#include <list>
#include <sstream>

#include "Character.hxx"
#include "Location.hxx"

std::string Bomb::use(Character *c, Location * l){

			if(this->itsEnable()) return Decorator::use(c,l) + "Bomb explodes\n" + l->distributeMagic(5u);
				else return Decorator::use(c,l) + "Bomb not enabled\n";
}

		std::string Bomb::receiveMagic(unsigned int magic){
			return "";
		}
