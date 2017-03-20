#ifndef Location_hxx
#define Location_hxx

#include "Exception.hxx"
#include "Character.hxx"
#include "AbstractItem.hxx"
#include "Item.hxx"
#include "Trap.hxx"
#include "Destroy.hxx"
#include "Potion.hxx"
#include "Bomb.hxx"
#include "Magic.hxx"
#include <iostream>
#include <map>
#include "ICreator.hxx"
#include "IBCreator.hxx"
#include "IPCreator.hxx"
#include "ITCreator.hxx"

typedef std::list<AbstractItem*> Items;
typedef std::list<Character*> Characters;

class Location
{
public:
	Location(){
		_name = "unknown";
		north = NULL;
		south = NULL;
		east = NULL;
		west = NULL;

			_myItemMap["Basic"]= new ICreator();
			_myItemMap["Bomb"]= new IBCreator();
			_myItemMap["Potion"]= new IPCreator();
			_myItemMap["Trap"]= new ITCreator();
	}
	~Location(){
		for(Items::iterator it=_items.begin(); it!=_items.end(); it++){
			delete (*it);
		}
		for(std::map<std::string,AICreator*>::iterator it=_myItemMap.begin();it!=_myItemMap.end();it++){
			delete(it->second);
		}
	}
		
	std::string name() const{
		return _name;
	}

	void name(std::string s){
		_name = s;
	}

	const std::string items() {
		
		std::string s;
			for(Items::iterator it=_items.begin(); it!=_items.end(); it++){	
				s += "\tItem: " +  (*it)->description() + "\n";
			}
			return s;
	}
	
	std::string description(){
		
		return "Location: " + _name + "\n" + connections()+items()+ characters();
	}
	
	void addItem(std::string s, unsigned int i){
		AbstractItem * item = new Item();
		item->name(s);
		item->level(i);
		_items.push_back(item);
	}
	
	AbstractItem * findItem (std::string n){
		for(Items::iterator it=_items.begin(); it!=_items.end(); it++){
				if( n == (*it)->name()){
					return (*it);
				}
			}
		throw ItemNotFound();
		}
	
	void placeCharacter(Character &c){
			_chars.push_back(&c);
		}
	
	const std::string characters(){
		
		std::string s;
			for(Characters::iterator it=_chars.begin(); it!=_chars.end(); it++){	
				s += "- " + (*it)->name() + " is here.\n";
			}
			return s;
		}
		
	Character * findCharacter(std::string c){
		for(Characters::iterator it=_chars.begin(); it!=_chars.end(); it++){
			if(c == (*it)->name()) return (*it);
			}
		throw CharacterNotFound();	
		}
		
	void unplaceCharacter (Character &c){
		_chars.remove(findCharacter(c.name()));
	}

	const std::string connections(){

		std::string conectedTo;

				if(north != NULL)	conectedTo += "\tNorth: " + north->name() + "\n";
				if(south != NULL)	conectedTo += "\tSouth: " + south->name() + "\n";
				if(east != NULL)	conectedTo += "\tEast: " + east->name() + "\n";
				if(west != NULL)	conectedTo += "\tWest: " + west->name() + "\n";
		
		return conectedTo;
	}
	
	void connectSouth(Location * city){
		south = city;
	}

	void connectNorth(Location * city){
		north = city;
	}
	
	void connectEast(Location * city){
		east = city;
	}

	void connectWest(Location * city){
		west = city;
	}
	
	Location * getNorth(){
		return north;
	}

	Location * getSouth(){
		return south;
	}
	Location * getWest(){
		return west;
	}
	Location * getEast(){
		return east;
	}

	std::string distributeMagic(unsigned int magic){
		std::string s;

		for(Characters::iterator it=_chars.begin(); it!=_chars.end(); it++){
				s += (*it)->receiveMagic(magic);
			}	

		for(Items::iterator it=_items.begin(); it!=_items.end(); it++){
			s += (*it)->receiveMagic(magic);
			}

		return s;
	}

	std::string useItem(std::string ch, std::string item){
			Character * c = findCharacter(ch);
			AbstractItem * i = findItem(item);

		if(c->level() < i->level()) return "The level of " + c->name() + " is too low\n";
			else{
				return i->use(c,this) ;
			}
	}

	void removeItem(std::string item){
		AbstractItem * i;
		for(Items::iterator it=_items.begin(); it!=_items.end(); it++){
			if(item == (*it)->name()){
			i = (*it);
			_items.erase(it);
			delete(i);
			return;	
			}
		}
	}

	void addTrap(std::string s, unsigned int lev){
		
		AbstractItem * item = new Trap( new Destroy( new Item() ) );
		item->name(s);
		item->level(lev);
		_items.push_back(item);
	}

	void addPotion(std::string s, unsigned int lev){
		AbstractItem *item = new Potion(new Destroy(new Item()));
		item->name(s);
		item->level(lev);
		_items.push_back(item);
	}

	void addBomb(std::string s, unsigned int lev){
		AbstractItem *item = new Magic(new Destroy(new Bomb (new Item())));
		item->name(s);
		item->level(lev);
		_items.push_back(item);
	}
	void placeItem(std::string name, unsigned int level, std::string type){
		_items.push_back(_myItemMap[type]->factoryMethod(name,level));
	}
	
	void deleteItem(std::string item){		
		_items.remove(findItem(item));	
	}
	void dropItem(AbstractItem * i){
		_items.push_back(i);
	}
private:

	std::string _name;
	Items _items;
	
	std::map<std::string,AICreator*> _myItemMap;
	
	Characters _chars;
	Location *north;
	Location *south;
	Location *east;
	Location *west;	
};
#endif
