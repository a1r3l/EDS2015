
#include <list>
#include <sstream>

#include "Location.hxx" 
#include "Character.hxx"

std::string Destroy::use (Character * c, Location * l){
	
	std::string s= Decorator::use(c,l);
	l->removeItem(this->name());
	return s;
}

		std::string Destroy::receiveMagic(unsigned int magic){
			return "";			
		}
