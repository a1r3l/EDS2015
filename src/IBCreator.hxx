#ifndef IBCreator_hxx
#define IBCreator_hxx

#include "AbstractItem.hxx"

class IBCreator : public AICreator{
	
	public:
		
	~IBCreator(){}

	AbstractItem * factoryMethod(std::string name, unsigned int level){
		AbstractItem * it = new Magic( new Destroy( new Bomb( new Item() ) ));
		it->name(name);
		it->level(level);
		return it;
	}
};

#endif