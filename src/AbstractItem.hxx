#ifndef AbstractItem_hxx
#define AbstractItem_hxx

class Location;
class Character;

class AbstractItem{

	public:

	virtual ~AbstractItem(){}

	virtual std::string name() const = 0;

	virtual void name(std::string s) = 0; 

	virtual unsigned int level() const = 0;
	
	virtual void level(unsigned int i) = 0;
	
	virtual bool itsEnable() const = 0;
	
	virtual void enable() = 0;

	virtual void disable() = 0;

	virtual std::string description() = 0;
	
	virtual std::string receiveMagic(unsigned int magic) = 0;

	virtual std::string use(Character * c, Location * l) = 0;
};

#endif
