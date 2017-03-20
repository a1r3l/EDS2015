#ifndef grup_hxx
#define grup_hxx

#include <iostream>
#include <list>
#include "animals.hxx"
using namespace std;


class Grup{
public:
	virtual void mostrarGrup(){ //mostra els animals que hi ha dins aquest grup
		cout << "En el grup " << _nom << " estan els animals: " << endl;
		for (list<Animal*>::iterator it=animals.begin(); it!=animals.end(); it++){
			cout << (*it)->nom() << " de l'especie ";
			 (*it)->escriuEspecie();
		}
		cout << endl;
	}

	void nom(string Nom){ //assigna a l'atribut _nom el string que ens passen per parametre
		_nom = Nom;
	}

	void insertarAnimal(Animal* a){ //inserta el animal a la llista de animals del grup
		animals.push_back(a);
	}

private:

	string _nom; //variable que li dona nom al grup

	list<Animal*> animals; //llista de animals del grup 

};

#endif
