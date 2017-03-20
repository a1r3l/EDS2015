#ifndef ICreator_hxx
#define ICreator_hxx

#include "AbstractItem.hxx"
#include "AICreator.hxx"

class ICreator : public AICreator{

	public:

	~ICreator(){}

	AbstractItem * factoryMethod(std::string name, unsigned int level){
		AbstractItem * it = new Item();
		it->name(name);
		it->level(level);
		return it;
	}
};

#endif