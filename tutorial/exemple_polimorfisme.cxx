#include <list>
#include "animals.hxx"
#include "grup.hxx"

typedef std::list<Animal*> Animals;
typedef std::list<Grup*> Grups;

int main(void)
{
	Animals animals;
	Grups grups;

	Animal unAnimal;
	unAnimal.nom("Pikatxu");
	animals.push_back(&unAnimal);

	Elefant unElefant;
	unElefant.nom("Jumbo l'Orellut");
	animals.push_back(&unElefant); 

	Granota unaGranota;
	unaGranota.nom("Gustavo el Reporter");
	animals.push_back(&unaGranota);

	Gat unGat;
	unGat.nom("Gat Amb Botes");
	animals.push_back(&unGat);

	Grup g; //creem una instancia de Grup
	g.nom("Primer"); //assignem a l'atribut nom el string "Primer"
	g.insertarAnimal(&unGat); //assignem quins animals volem afeigir
	g.insertarAnimal(&unaGranota);
	grups.push_back(&g);//introduim el grup al zoo 

	Grup g2;
	g2.nom("Segon");
	g2.insertarAnimal(&unAnimal);
	g2.insertarAnimal(&unElefant);
	grups.push_back(&g2);


	for (Animals::iterator it=animals.begin(); it!=animals.end(); it++)
	{
		std::cout << "l'animal anomenat " << (*it)->nom() << " es de l'especie ";
		(*it)->escriuEspecie();
	}

	std::cout << endl;

	for (Grups::iterator it=grups.begin(); it!=grups.end(); it++){ //mostrem tots els grups amb els animals que hi pertanyen
		(*it)->mostrarGrup();
	}

	return 0;
}
