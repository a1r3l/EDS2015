#ifndef DCCreator_hxx
#define DCCreator_hxx

#include "DamageCharacter.hxx"
#include "DCCreator.hxx"

class DCCreator : public ACCreator{
	
	public:

	~DCCreator(){}
	
	Character * factoryMethod(std::string name, unsigned int level){
		Character * ch = new DamageCharacter();
		ch->name(name);
		ch->level(level);
		return ch;
	}
};

#endif