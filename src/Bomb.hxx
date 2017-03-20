#ifndef Bomb_hxx
#define Bomb_hxx
#include "Character.hxx"
#include "Decorator.hxx"

class Bomb : public Decorator{

	public:
	Bomb(AbstractItem * ai):Decorator(ai){ai->disable();}	
	std::string use(Character * c, Location * l);
		std::string receiveMagic(unsigned int magic);
};
#endif
