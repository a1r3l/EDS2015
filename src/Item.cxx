
#include <list>
#include <sstream>

#include "Character.hxx"
#include "Location.hxx"

std::string Item::use(Character * c, Location * l){
	std::string s="";
		if(this->itsEnable()) s=c->name() + " uses " +this->name() + " at " + l->name()+ "\n";
	return s;
}