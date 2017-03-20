#ifndef potion_hxx
#define Potion_hxx
#include "Character.hxx"

class Potion : public Decorator{
	
public:
	Potion(AbstractItem * ai) : Decorator(ai) {}
	std::string use(Character * c, Location * l){
		c->cure(5);
	return Decorator::use(c,l) + c->name() + " gains 5 life\n";
	}
};
#endif
