#pragma once
#include "CNqueenContainer.h"

class CNqueenSolution
{
private:
	int n;
public:
	CNqueenSolution(int input) : n(input) {};
	void algorithm()
	{
		CNqueenContainer* myStack = new CNqueenContainer();

		
		myStack->push(n);


		CNqueenGrid* myPointer = myStack->getHead();

		char **ppTheGrid = myPointer->getGrid();

		int row = 0;
		int col = 0;





		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (row == n)
				{
					row = 0;
				}
				if (col == n)
				{
					row++;
				}
				col++;
				//ppTheGrid[i][j] = 'X';
				cout << ppTheGrid[i][j];
			}
			cout << endl;
		}




		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				
			}
		}

		//*(*ppTheGrid + 1) = 'Q';

		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < n; j++)
		//	{
		//		//ppTheGrid[i][j] = 'X';
		//		cout << ppTheGrid[i][j];
		//	}
		//	cout << endl;
		//}
	}



};

