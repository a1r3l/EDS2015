#ifndef StaffState_hxx
#define StaffState_hxx


	class StaffState : public AbstractState{

		public:
			std::string hit(Character * c){
				
				if(c->life()>0) return c->receiveMagic(5);

				else{
					std::string s = c->receiveMagic(5) + c->name()+" is dead\n";
					c->getCharLoc()->unplaceCharacter(*c);
					return s;
				}
			}
	};
#endif