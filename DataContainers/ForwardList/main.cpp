#include<iostream>
using namespace std;

class Element
{
	int Data;		//Значение элемента
	Element* pNext;	//Адрес следующего элемента
public:
	Element(int Data, Element* pNext = nullptr)
	{
		this->Data = Data;
		this->pNext = pNext;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class List;
};

class List
{
	Element* Head;	//Адрес начала списка
public:
	List()
	{
		this->Head = nullptr;
		cout << "LConstructor:\t" << this << endl;
	}
	~List()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	void push_front(int Data)
	{
		//1)Создаем новый элемент:
		Element* New = new Element(Data);
		//2)"Привязываем новый элемент к Голове (Head)":
		New->pNext = Head;
		//3)Голову переводим на новый элемент.
		Head = New;
	}

	void print()
	{
		Element* Temp = Head;	//Temp - это итератор.
		//Итератор - это указатель, при помощи которого
		//можно получить доступ, к элементам структуры данных.
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
}