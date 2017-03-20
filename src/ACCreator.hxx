#ifndef ACCreator_hxx
#define ACCreator_hxx


class ACCreator {

	public:
		
		virtual ~ACCreator(){}

		virtual Character * factoryMethod(std::string name, unsigned int level) = 0;

};
#endif
