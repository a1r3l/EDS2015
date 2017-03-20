#ifndef SwordState_hxx
#define SwordState_hxx


	class SwordState : public AbstractState{

		public:
			std::string hit(Character * c){
				c->damage(4);
				if(c->life()>0) return c->name() + " takes 4 damage\n";
				else{
					std::string s = c->name() + " takes 4 damage\n" + c->name() +" is dead\n";
					c->getCharLoc()->unplaceCharacter(*c);
					return s;
				}
			}
	};
	
#endif