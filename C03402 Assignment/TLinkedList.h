#pragma once
#include "CElement.h"
class CElement;

class TLinkedList
{
private:

	CElement* mpHead;

public:
	TLinkedList();
	~TLinkedList();
	void push(int data);
	void pop();
	void top();
	void toString();
	bool isEmpty();
	int size();
};

