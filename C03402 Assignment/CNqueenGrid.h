#pragma once
#include "CElement.h"
class CNqueenGrid : virtual public CElement
{
private:
	CNqueenGrid* mpNextNode;
	char** mGrid;
	int mGridLength;
public:
	CNqueenGrid();
	CNqueenGrid(int gridLength);
	~CNqueenGrid();
	CNqueenGrid* getNext();
	void setNext() {};
	void setNext(CNqueenGrid* nextNode);
	int getData();
	void print();

};

