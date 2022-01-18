#pragma once
#include "CElement.h"
class CNqueenGrid : virtual public CElement<char**>
{
private:
	CNqueenGrid* mpNextNode;
	int mGridLength;
	char** mGrid;


public:

	CNqueenGrid(int gridLength);
	~CNqueenGrid();
	CNqueenGrid* getNext();
	void setNext() {};
	void setNext(CNqueenGrid* nextNode);
	char** getData();// super duper importante
	void print();


};

