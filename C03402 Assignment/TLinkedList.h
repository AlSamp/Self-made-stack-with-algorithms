#pragma once
#include "CElement.h"
class CElement;

template<class TElement ,class Tdata>
class TLinkedList
{
private:

	TElement* mpHead;

public:
	TLinkedList();
	~TLinkedList();
	TElement* getHead();
	void push(Tdata data);
	void pop();
	TElement* top();
	void toString();
	bool isEmpty();
	int size();
};

