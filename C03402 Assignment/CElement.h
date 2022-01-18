#pragma once

#include <iostream>

using namespace std;
template <class T>
class CElement
{
private:
	//CElement* mpNextNode;				// example of waht should be in the concrete class
	//int mData;						// example of waht should be in the concrete class
public:

	virtual ~CElement() {};
	virtual CElement* getNext() = 0;
	virtual void setNext() = 0;
	// vitual void setNext(ConcreteClass* nextNode); // concrete class will require concrete class pointer pararmeter to establish next node in list.
	virtual T getData() = 0;
	virtual void print() = 0;
};

