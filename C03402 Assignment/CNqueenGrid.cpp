#include "CNqueenGrid.h"

CNqueenGrid::CNqueenGrid(int gridLength)
{
	mpNextNode = nullptr;

	mGridLength = gridLength;
	mGrid = new char* [mGridLength]; //creates the grid of gridLength(n)
	for (int i = 0; i < mGridLength; i++)
	{
		mGrid[i] = new char[mGridLength];
	}

	for (int i = 0; i < mGridLength; i++)
	{
		for (int j = 0; j < mGridLength; j++)
		{
			mGrid[i][j] = '.';
		}
	}
}

CNqueenGrid::~CNqueenGrid()
{
	for (int i = 0; i < mGridLength; i++)
	{
		delete [] mGrid[i]; // how did i figure this out lmfao
	}
	delete[] mGrid;
}

CNqueenGrid* CNqueenGrid::getNext()
{
	return mpNextNode;
}

void CNqueenGrid::setNext(CNqueenGrid* nextNode)
{
	mpNextNode = nextNode;
}

int CNqueenGrid::getData()
{
	return 0;
}



void CNqueenGrid::print()
{
	for (int i = 0; i < mGridLength; i++)
	{
		for (int j = 0; j < mGridLength; j++)
		{
			//mGrid[i][j] = '.';
			cout << mGrid[i][j];
		}
		cout << endl;
	}
}

char** CNqueenGrid::getGrid()
{
	return mGrid;
}
