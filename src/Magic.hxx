#ifndef Magic_hxx
#define Magic_hxx
#include "Character.hxx"

class Magic : public Decorator{
	public:
		Magic(AbstractItem * ai):Decorator(ai){}	
		std::string use(Character * c, Location * l){
			return Decorator::use(c,l);
		}
		
		std::string receiveMagic(unsigned int magic){
			if(magic >= 0)this->enable();
			return Decorator::receiveMagic(magic);
		}
};

#endif

