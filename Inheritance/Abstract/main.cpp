#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void sound() = 0;	//„исто виртуальный метод
};

class Cat :public Animal
{
public:
	void sound()
	{
		cout << "ћ€у" << endl;
	}
};

class Dog :public Animal
{
public:
	void sound()
	{
		cout << "√ав" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Animal animal;	//Ќевозможно создать экземпл€р абстрактного класса.
	Animal* zoo[] =
	{
		new Cat(),
		new Cat(),
		new Dog(),
		new Cat(),
		new Dog()
	};
	for (int i = 0; i < sizeof(zoo) / sizeof(Animal*); i++)
	{
		zoo[i]->sound();
	}
}