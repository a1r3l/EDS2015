#ifndef ITCreator_hxx
#define ITCreator_hxx

#include "AbstractItem.hxx"

class ITCreator : public AICreator {
	
	public:

	~ITCreator(){}

	AbstractItem * factoryMethod(std::string name, unsigned int level){
		AbstractItem * it = new Trap( new Destroy( new Item() ) );
		it->name(name);
		it->level(level);
		return it;
	}
};

#endif