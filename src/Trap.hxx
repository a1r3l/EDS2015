#ifndef Trap_hxx
#define Trap_hxx

#include "Decorator.hxx"

class Trap : public Decorator{
	public:
		Trap(AbstractItem * ai) : Decorator(ai) {ai->enable();}
		~Trap(){}
		std::string use (Character * c, Location * l);
		std::string receiveMagic(unsigned int magic);
};
#endif
