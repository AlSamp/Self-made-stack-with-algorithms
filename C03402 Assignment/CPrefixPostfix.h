#pragma once
#include "CElement.h"
#include <string>
template <class T>
class CPrefixPostfix : virtual public CElement<T> // declare the type of data that will be held by the container
{
private:

	char mEquationSegment;
	CPrefixPostfix* mpNextNode;

public:

	 CPrefixPostfix(T input);
	 ~CPrefixPostfix();
	 CPrefixPostfix* getNext();
	 void setNext() {};
	 void setNext(CPrefixPostfix* nextNode);
	//setNext(ConcreteClass* nextNode); // concrete class will require concrete class pointer pararmeter to establish next node in list.
	 T getData();
	 void print();
};


template <class T>
CPrefixPostfix<T>::CPrefixPostfix(T input)
{
	mEquationSegment = input;
	mpNextNode = nullptr;
}

template <class T>
CPrefixPostfix<T>::~CPrefixPostfix()
{

}
template<class T>
CPrefixPostfix<T>* CPrefixPostfix<T>::getNext()
{
	return mpNextNode;
}
template <class T>
void CPrefixPostfix<T>::setNext(CPrefixPostfix* nextNode)
{
	mpNextNode = nextNode;
}

template <class T>
T CPrefixPostfix<T>::getData()
{
	return mEquationSegment;
}

template <class T>
void CPrefixPostfix<T>::print()
{
	cout << mEquationSegment;
}