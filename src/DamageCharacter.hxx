#ifndef DamageCharacter_hxx
#define DamageCharacter_hxx

#include "Character.hxx"

class DamageCharacter : public Character{
	
	public:
		~DamageCharacter(){}
	std::string receiveMagic(unsigned int magic){
		std::stringstream s;
		damage(magic);
		s << Character::receiveMagic(magic) << name() << " takes " << magic << " damage\n";
		return s.str();
	}
};
#endif
