#pragma once
#include "CElement.h"
class CNqueenGrid : virtual public CElement
{
private:
	CNqueenGrid* mpNextNode;
	int mGridLength;
	char** mGrid;
	
public:
	char** getGrid(); // super duper importante
	CNqueenGrid(int gridLength);
	~CNqueenGrid();
	CNqueenGrid* getNext();
	void setNext() {};
	void setNext(CNqueenGrid* nextNode);
	int getData();
	void print();


};

