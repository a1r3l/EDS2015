#ifndef EmptyState_hxx
#define EmptyState_hxx

	class EmptyState : public AbstractState{

		public: 
			std::string hit(Character * c){		
				c->damage(1);
				if(c->life()>0)return  c->name() + " takes 1 damage\n";	

					else{
						std::string s = c->name() + " takes 1 damage\n" + c->name() + " is dead\n";
						c->getCharLoc()->unplaceCharacter(*c);
						return s;
					}
			}
	};
#endif
