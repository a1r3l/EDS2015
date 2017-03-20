
#include <list>
#include <sstream>
#include "Character.hxx"
#include "Location.hxx"
#include "AbstractItem.hxx"
#include "EmptyState.hxx"
#include "HammerState.hxx"
#include "StaffState.hxx"
#include "SwordState.hxx"

Character::Character(){
		_name = "unknown";
		_level = 0u;
		_life = 10u;
		_location = 0;
		_state = new EmptyState();
	}

Character::~Character(){

		for(std::vector<AbstractItem*>::iterator it=_items.begin(); it!=_items.end(); it++){
				delete (*it);
			}
		
		if(_state) delete _state;
	}

void Character::locateAt(Location & location){
	
	if(_location){	
		_location->unplaceCharacter(*this);
		_location= &location;
		_location->placeCharacter(*this);
	}
	else{	
		_location = &location;
		_location->placeCharacter(*this);
	}
}

std::string Character::pickup(std::string it){
	
		if(_location){
			_items.push_back(_location->findItem(it));
			_location->deleteItem(it);
		}

		else throw ItemNotFound();

	return this->name() + " picks up " + it + "\n";
}

AbstractItem * Character::findCharItem(std::string c){
		
		for(std::vector<AbstractItem*>::iterator it=_items.begin(); it!=_items.end(); it++){
			if(c == (*it)->name()) return (*it);
			}
	
	throw ItemNotFound();;	
}

std::string Character::hit(Character * ch2){
		if(_location == ch2->_location) return _state->hit(ch2);
			else throw CharacterNotFound();
		
}

std::string Character::setMainWeapon(std::string item){
		
		AbstractItem * i = findCharItem(item);
		
		if( i->name() == "Hammer") {
			delete this->_state;
			this->_state = new HammerState();
			return this->name() + " set " + i->name() + " as main weapon\n";
		}

		if( i->name() == "Staff") {
			delete this->_state;
			this->_state = new StaffState();
			return this->name() + " set " + i->name() + " as main weapon\n";
		}

		if( i->name() == "Sword") {
			delete this->_state;
			this->_state = new SwordState();
			return this->name() + " set " + i->name() + " as main weapon\n";
		}

		return "You dont carry this weapon";
	}

	std::string Character::drop(){

		std::string s;

		for(std::vector<AbstractItem*>::iterator it=this->_items.begin(); it!=this->_items.end(); it++){	
			
			this->_location->dropItem(this->_items.back());
			s+= this->name() +" drops " +(*it)->name()+"\n";
		}
		_items.erase(_items.begin(),_items.end());

		delete this->_state;
		this->_state = new EmptyState();
		
		return s;
	}

	void Character::move(std::string dir){

		if(dir == "North" and _location->getNorth()) {
			Location * aux = _location;
			_location->unplaceCharacter(*this);
			_location = aux->getNorth();
			_location->placeCharacter(*this);
		}
		
			else if(dir == "South" and _location->getSouth()){
				Location * aux = _location;
				_location->unplaceCharacter(*this);
				_location = aux->getSouth();
				_location->placeCharacter(*this);
			}
				else if(dir == "East" and _location->getEast()){
					Location * aux = _location;
					_location->unplaceCharacter(*this);
					_location = aux->getEast();
					_location->placeCharacter(*this);
				}

					else if(dir == "West" and _location->getWest()){
						Location * aux = _location;
						_location->unplaceCharacter(*this);
						_location = aux->getWest();
						_location->placeCharacter(*this);
					}
						else throw LocationNotFound();
	}
