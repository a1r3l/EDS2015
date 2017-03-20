#ifndef Character_hxx
#define Character_hxx


#include "AbstractItem.hxx"
#include "AbstractState.hxx"
#include <vector>

class Location;

class Character{
public:
	Character();

	virtual ~Character();

	unsigned int life() const{
		return _life;
	}

	void damage(unsigned int i){
		if(i > _life) _life = 0u;
		else _life -= i;
	}

	void cure(unsigned int i){
		if(i + _life > 10) _life = 10;
		else _life += i;
	}

	unsigned int level() const{ 
		return _level;
	}

	void level(unsigned int i){
		_level = i;
	}

	std::string name() const{
		return _name;
	}

	void name(std::string s){
		_name = s;
	}

	void locateAt(Location & location);

	virtual std::string receiveMagic(unsigned int magic){
		std::stringstream s;
		s << name() << " receives " << magic << " magic points\n";
		return s.str();
	}

	Location * getCharLoc(){
		return _location;
	}
	
	std::string pickup(std::string it);

	std::string drop();

	AbstractItem * findCharItem(std::string c);
	
	std::string setMainWeapon(std::string item);

	std::string hit(Character * ch2);
	
	void move(std::string dir);

private:
	std::string _name;
	unsigned int _level;
	unsigned int _life;
	Location * _location;
	AbstractState * _state;
	std::vector<AbstractItem*> _items;
};

#endif
