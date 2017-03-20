#ifndef IPCreator_hxx
#define IPCreator_hxx

#include "AbstractItem.hxx"

class IPCreator : public AICreator{
	
	public:
	
	~IPCreator(){}

	AbstractItem * factoryMethod(std::string name, unsigned int level){
		AbstractItem * it = new Potion( new Destroy( new Item() ) );
		it->name(name);
		it->level(level);
		return it;
	}
};

#endif