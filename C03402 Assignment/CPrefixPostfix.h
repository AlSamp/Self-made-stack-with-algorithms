#pragma once
#include "CElement.h"
#include <string>
class CPrefixPostfix : virtual public CElement<char> // declare the type of data that will be held by the container
{
private:

	char mEquationSegment;
	CPrefixPostfix* mpNextNode;

public:

	 CPrefixPostfix(char input);
	 ~CPrefixPostfix();
	 CPrefixPostfix* getNext();
	 void setNext() {};
	 void setNext(CPrefixPostfix* nextNode);
	//setNext(ConcreteClass* nextNode); // concrete class will require concrete class pointer pararmeter to establish next node in list.
	 char getData();
	 void print();
};

