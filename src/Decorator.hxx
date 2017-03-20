#ifndef Decorator_hxx
#define Decorator_hxx
#include "Character.hxx"

class Decorator : public AbstractItem {
	
	protected:
	AbstractItem * _ai;
	
	public:
	
	Decorator(AbstractItem * ai){
			_ai=ai;
	}
	
	~Decorator(){
			if(_ai) delete _ai;
	}	
	
	std::string name() const{
		return _ai->name();
	}

	void name(std::string s){
		_ai->name(s);
	}

	unsigned int level() const{
		return _ai->level();
	}
	
	void level(unsigned int i){
		_ai->level(i);
	}
	
	bool itsEnable() const{
		return _ai->itsEnable();
	}
	
	void enable(){
		_ai->enable();
	}
	
	void disable(){
		_ai->disable();
	}
	
	std::string description(){
		return _ai->description();
	}

	std::string use(Character * c, Location * l){
		return _ai->use(c,l);
	}	

	std::string receiveMagic(unsigned int magic){
		return _ai->receiveMagic(magic);
	}
};

#endif
