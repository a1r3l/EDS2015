#ifndef AbstractState_hxx
#define AbstractState_hxx

class AbstractState{
	public:
		virtual ~AbstractState(){}
		virtual std::string hit(Character * c)=0;
};

#endif