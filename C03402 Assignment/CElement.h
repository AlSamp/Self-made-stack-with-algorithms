#pragma once

#include <iostream>

using namespace std;

class CElement
{
private:
	CElement* mpNextNode;
	int mData;
public:
	CElement();
	CElement(int data);
	~CElement();
	CElement* getNext();
	void setNext(CElement* nextNode);
	int getData();
	void print();
};

