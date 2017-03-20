#ifndef Destroy_hxx
#define Destroy_hxx

#include "Decorator.hxx"

class Destroy : public Decorator{
	
	public:
		Destroy(AbstractItem * ai) : Decorator(ai) {}
		~Destroy(){}
		std::string use(Character * c, Location * l);
		std::string receiveMagic(unsigned int magic);
};

#endif
