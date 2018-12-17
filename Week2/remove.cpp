//Program tested on Microsoft Visual Studio 2008 - Zahid Ghadialy
//Abstract Factory is part of Creational Patterns
//Creational Patterns deal with initializing and configuring classes and objects
//Abstract Factory creates an instance of several families of classes

//We will take an example of Animal Classes and Abstract them.
//There are 2 types of animals; Herbivores and Carnivores.
//The rule of nature is that Carnivores eats Herbivores which will be shown
//Different animas live in different continents but the same rule applies

#include<iostream>
#include<string>

using namespace std;

//The Herbivore class - The 'AbstractProductA' abstract class
class Herbivore
{
public:
	virtual const string& getName(void) = 0;
};

//Lets define couple of Herbivores called Cow and Deer
class Cow : public Herbivore //The 'ProductA1' class
{
public:
	Cow() :name("Cow") {};
	//default destructor
	const string& getName(void) { return name; }
private:
	string name;
};

class Deer : public Herbivore //The 'ProductA2' class
{
public:
	Deer() :name("Deer") {};
	//default destructor
	const string& getName(void) { return name; }
private:
	string name;
};

//The Carnivore class - The 'AbstractProductB' abstract class
class Carnivore
{
public:
	virtual const string& getName(void) = 0;
	virtual void eat(Herbivore& h) = 0;
};

//Lets define couple of Carnivores called Lion and Wolf
class Lion : public Carnivore //The 'ProductB1' class
{
public:
	Lion() :name("Lion") {};
	const string& getName(void) { return name; }
	void eat(Herbivore& h) //override
	{
		cout << name << " eats " << h.getName() << endl;
	}
private:
	string name;
};

class Wolf : public Carnivore //The 'ProductB2' class
{
public:
	Wolf() :name("Wolf") {};
	const string& getName(void) { return name; }
	void eat(Herbivore& h) //override
	{
		cout << name << " eats " << h.getName() << endl;
	}
private:
	string name;
};

//The 'AbstractFactory' abstract class
class ContinentFactory
{
public:
	virtual Herbivore& CreateHerbivore() = 0;
	virtual Carnivore& CreateCarnivore() = 0;
};

class AfricaFactory : public ContinentFactory //The 'ConcreteFactory1' class
{
	Herbivore& CreateHerbivore()
	{
		return *(dynamic_cast<Herbivore *>(new Cow()));
	}
	Carnivore& CreateCarnivore()
	{
		return *(dynamic_cast<Carnivore *>(new Lion()));
	}
};

class AmericaFactory : public ContinentFactory //The 'ConcreteFactory2' class
{
	Herbivore& CreateHerbivore()
	{
		return *(dynamic_cast<Herbivore *>(new Deer()));
	}
	Carnivore& CreateCarnivore()
	{
		return *(dynamic_cast<Carnivore *>(new Wolf()));
	}
};

//The 'Client' class
class AnimalWorld
{
public:
	AnimalWorld(ContinentFactory& factory) :_herbivore(factory.CreateHerbivore()), _carnivore(factory.CreateCarnivore())
	{
	}
	void RunFoodChain()
	{
		_carnivore.eat(_herbivore);
	}
private:
	Herbivore & _herbivore;
	Carnivore& _carnivore;
};

int main()
{
	//Create and run African Animal World
	ContinentFactory& africa = *(dynamic_cast<ContinentFactory *>(new AfricaFactory()));
	AnimalWorld& world1 = *(new AnimalWorld(africa));
	world1.RunFoodChain();

	// Create and run the American animal world
	ContinentFactory& america = *(dynamic_cast<ContinentFactory *>(new AmericaFactory()));
	AnimalWorld& world2 = *(new AnimalWorld(america));
	world2.RunFoodChain();

	return 0;
}