#ifndef CCreator_hxx
#define CCreator_hxx

#include "Character.hxx"

class CCreator : public ACCreator{
	
	public:

	~CCreator(){}
	
	Character * factoryMethod(std::string name, unsigned int level){
		Character * ch = new Character();
		ch->name(name);
		ch->level(level);
		return ch;
	}
};

#endif