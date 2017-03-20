#ifndef AICreator_hxx
#define AICreator_hxx

class AICreator {

	public:
		
		virtual	~AICreator(){}

		virtual AbstractItem * factoryMethod(std::string name, unsigned int level) = 0;
};
#endif
