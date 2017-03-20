#ifndef CureCharacter_hxx
#define CureCharacter_hxx

#include "Character.hxx"

class CureCharacter : public Character{
	
	public:
		~CureCharacter(){}
	std::string receiveMagic(unsigned int magic){
		std::stringstream s;
		cure(magic);
		s << Character::receiveMagic(magic) << name() << " gains " << magic << " life\n";
		return s.str();
	}
};
	
#endif
