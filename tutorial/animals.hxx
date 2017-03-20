#ifndef animals_hxx
#define animals_hxx

#include <iostream>
#include <string> /*  NO CAL INCLUIR STRING SI JA HO HAS FET AMB EL IOSTREAM */

class Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "...indefinida..." << std::endl;
	}
	void nom(std::string elNom)
	{
		_nom = elNom;
	}
	std::string& nom()
	{
		return _nom;
	}

private:
	std::string _nom;
};

class Elefant : public Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "elefant" << std::endl;
	}
};

class Granota : public Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "granota" << std::endl;
	}
};

class Gat : public Animal
{
public:
	virtual void escriuEspecie() const
	{
		std::cout << "gat" << std::endl;
	}
};

#endif
