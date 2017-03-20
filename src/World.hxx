#ifndef	World_hxx
#define	World_hxx

#include "Model.hxx"
#include <fstream>
#include <sstream>

#include "Location.hxx"
#include "Character.hxx"
#include "AbstractItem.hxx"
#include "CureCharacter.hxx"
#include "DamageCharacter.hxx"
#include "Decorator.hxx"

#include <map>
#include "ACCreator.hxx"
#include "CCreator.hxx"
#include "CCCreator.hxx"
#include "DCCreator.hxx"

typedef std::list<Location*> Locations;
typedef std::list<Character*> Characters;


class World : public Model{
	public:
		Character * _player;

		World(){
			_myCharacterMap["Basic"] = new CCreator();
			_myCharacterMap["Cure"] = new CCCreator();
			_myCharacterMap["Damage"] = new DCCreator();
		}
		
		~World(){

			for(Locations::iterator it=_locations.begin(); it!=_locations.end(); it++){
				delete (*it);
			}

			for(Characters::iterator it=_characters.begin(); it!=_characters.end(); it++){
				delete (*it);
			}
			
			for(std::map<std::string,ACCreator*>::iterator it = _myCharacterMap.begin(); it!=_myCharacterMap.end();it++ ){
				delete (it->second);
			}
		}	
		void addLocation(const std::string &s){
			
			Location * l= new Location();
			l->name(s);
			_locations.push_back(l);
			
		}
			
		const std::string locations(){
			std::string s;

			for(Locations::iterator it=_locations.begin(); it!=_locations.end(); it++){
				s += (*it)->name() + "\n";
			}

			return s;
		}
		
		std::string locationDetails (std::string s) const{
			for(Locations::const_iterator it=_locations.begin(); it!=_locations.end(); it++){
				if((*it)->name() == s) return (*it)->description();
			}

			throw LocationNotFound();
		}
		

		
		Location * findLocation(std::string s){
			
			for(Locations::iterator it=_locations.begin();it!=_locations.end();it++){
				if((*it)->name() == s) return (*it);
			}

			throw LocationNotFound();
		}
		
		void addItemAtLocation(std::string l, std::string item, unsigned int lev){			
			findLocation(l)->addItem(item,lev);					
		}		
		
		void connectNorthToSouth(std::string lS, std::string lN){
			Location *locS = findLocation(lS);
			Location *locN = findLocation(lN);
				
				if(locS->getSouth() != NULL){
					 Location * l = locS->getSouth();
					 l->connectNorth(NULL);
				}

				if(locN->getNorth() != NULL){
					 Location * l = locN->getNorth();
					 l->connectSouth(NULL);
				}

			locS->connectSouth(locN);
			locN->connectNorth(locS);
		}
		
		void connectWestToEast(const std::string &lW, const std::string &lE){
			Location *locW = findLocation(lW);
			Location *locE = findLocation(lE);
				if(locE->getWest() != NULL){
					Location * loc = locE->getWest();
					loc->connectEast(NULL);
				}
				
				if(locW->getEast() != NULL){
					Location * loc = locW->getEast();
					loc->connectWest(NULL);
				}
			
			locW->connectEast(locE);
			locE->connectWest(locW);
		}

		const std::string characters(){
			std::string ret;
			
			for(Characters::iterator it=_characters.begin() ; it!=_characters.end() ; it++){
				ret += (*it)->name() +  "\n";
			}

			return ret;
		}
		
		void addCharacter ( const std::string &na, unsigned int lev){
			Character * ch = new Character();
			ch->name(na);
			ch->level(lev);
			
			_characters.push_back(ch);
		}
		void addCureCharacter (const std::string &na, unsigned int lev){
			CureCharacter * ch = new CureCharacter();
			ch->name(na);
			ch->level(lev);
			
			_characters.push_back(ch);
		}
		void addDamageCharacter ( const std::string &na, unsigned int lev){
			DamageCharacter * ch = new DamageCharacter();
			ch->name(na);
			ch->level(lev);
			
			_characters.push_back(ch);
		}
		
		Character * findCharacter(const std::string &s){
			
			for(Characters::iterator it=_characters.begin();it!=_characters.end();it++){
				if((*it)->name() == s) return (*it);
			}

			throw CharacterNotFound();	
		}
		
		void placeCharacter(const std::string &ch, const std::string &loc){
			Location * l = findLocation(loc);
			Character * c= findCharacter(ch);

			c->locateAt(*l);
		}
		
		const std::string useItem(const std::string &loc,const std::string &ch,const std::string &it){
			Location * l = findLocation(loc);
			return l->useItem(ch,it);
		}
		
		const std::string distributeMagic(const std::string &loc, unsigned int magic){
			Location * l= findLocation(loc);
			return l->distributeMagic(magic);
		}

		void addTrapAtLocation(const std::string &loc,const std::string &item,unsigned int lev ){
			Location * l = findLocation(loc);
			l->addTrap(item,lev);
		}
		
		void addPotionAtLocation(const std::string &loc,const std::string &item,unsigned int lev ){
			Location * l = findLocation(loc);
			l->addPotion(item,lev);
		}	
		void addBombAtLocation(const std::string &loc,const std::string &item,unsigned int lev ){
			Location * l = findLocation(loc);
			l->addBomb(item,lev);
		} 
				
		void connection(const std::string &type,const std::string &location1,const std::string &location2){
       		if(type == "North") connectNorthToSouth(location1,location2);
       			else connectWestToEast(location1,location2);
        }

        void newTypeCharacter(const std::string &name,const std::string &type,unsigned int level){      
            _characters.push_back(_myCharacterMap[type]->factoryMethod(name,level));   
        }

        void newTypeItem(const std::string &name,const std::string &type,unsigned int level,const std::string &location){
        	findLocation(location)->placeItem(name,level,type);
        }

void loadMap(const std::string &url){
        
        std::ifstream file(url.c_str());
        
        std::string line;
      
        while(getline( file, line )){
                std::string token;
                std::istringstream is( line );
                is  >> token;
                if(token == "Location"){
                        std::string name;
                        is >> name;
                        addLocation(name);
                }
                if(token == "Character"){
                        std::string type,name;
                        unsigned int level;
                        is >> type >> name >> level;
                        if(type!="Basic" && type!="Cure" && type!="Damage") throw InvalidType();
                        newTypeCharacter(name,type,level);
                }
                if(token == "Item"){
                        std::string type,name,location;
                        unsigned int level;
                        is >> type >> name >> level >> location;
                        if(type == "" || name == "" || location == "") throw IncorrectMap();
                        if(type!="Bomb" && type!="Trap" && type!="Potion" && type!="Basic") throw InvalidType();                                
                        newTypeItem(name,type,level,location);
                }
                if(token == "Connection"){
                        std::string type,location1,location2;
                        is >> type >> location1 >> location2;
                        connection(type,location1,location2);
                }
                if(token == "LocateAt"){
                        std::string character,location;
                        is >> character >> location;
                        placeCharacter(character,location);
                }
        }
        file.close();
    }
    std::string pickup(std::string ch, std::string it){
    	Character * c = findCharacter(ch);
    	return c->pickup(it);
    }

    std::string setMainWeapon (std::string ch, std::string item){
    	return findCharacter(ch)->setMainWeapon(item);
    }

    std::string hit(std::string ch1,std::string ch2){
    	return findCharacter(ch1)->hit(findCharacter(ch2)); 
    }

    void move (std::string ch, std::string dir){
    	Character * c = findCharacter(ch);
    	c->move(dir);
    } 

    void registerPlayer (const std::string & name){
    	_player = findCharacter(name);
    } 

    std::string locationDetails() const{
    	return  locationDetails(_player->getCharLoc()->name());
    }

    void move (const std::string & dir){
    	_player->move(dir);
    }

    std::string useItem(const std::string & itname){
    	return _player->getCharLoc()->useItem(_player->name() , itname);
    }

	private:

		Locations _locations;
		Characters _characters;
		std::map<std::string,ACCreator*> _myCharacterMap;
};

#endif
