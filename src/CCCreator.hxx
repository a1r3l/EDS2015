#ifndef CCCreator_hxx
#define CCCreator_hxx

#include "CureCharacter.hxx"

class CCCreator : public ACCreator{

	public:

	~CCCreator(){}
	
	Character * factoryMethod(std::string name, unsigned int level){
		Character * ch = new CureCharacter();
		ch->name(name);
		ch->level(level);
		return ch;
	}
};

#endif