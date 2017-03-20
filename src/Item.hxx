#ifndef Item_hxx
#define Item_hxx

#include "AbstractItem.hxx"

class Item : public AbstractItem
{
public:
	Item(){
		_name = "unknown";
		_level = 0u;
		_state = true;
	}
	~Item(){}
	
	std::string name() const{
		return _name;
	}

	void name(std::string s){
		_name = s;
	}

	unsigned int level() const{
		return _level;
	}
	
	void level(unsigned int i){
		_level = i;
	}
	
	bool itsEnable() const{
		return _state;
	}
	
	void enable(){
		_state = true;
	}
	
	void disable(){
		_state = false;
	}
	
	std::string description(){
		std::stringstream ss;
		ss << _name << " [" << _level <<"]";
		return ss.str();
	}

	std::string use(Character * c, Location * l);

	std::string receiveMagic(unsigned int magic){
		std::stringstream s;
		s << name() << " receives " << magic << " magic points\n";
		return s.str();
	}

private:
	std::string _name;
	unsigned int _level;
	bool _state;
};

#endif
