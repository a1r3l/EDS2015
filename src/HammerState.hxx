#ifndef HammerState_hxx
#define hammerState_hxx


	class HammerState : public AbstractState{

		public:

			std::string hit(Character * c){
				std::string s;
				c->damage(2);
				s += c->drop();
				if(c->life() > 0) return s + c->name() + " takes 2 damage\n";
					else{
						s=c->name() + " takes 2 damage\n"+ c->name() + " is dead\n";
						c->getCharLoc()->unplaceCharacter(*c);
						return s;
					}	
			}
	};

#endif