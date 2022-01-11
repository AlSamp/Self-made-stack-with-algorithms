#include <iostream>
#include "TLinkedList.cpp"
#include "CNqueenGrid.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

using namespace std;

const int n = 4;

using namespace std;

int main()
{
	int gridLength;
	cout << "Please enter a number - " << endl;
	cin >> gridLength;

	//array<double, 3, 3>
	TLinkedList<CNqueenGrid, int>* myList = new TLinkedList<CNqueenGrid, int>;

	myList->push(gridLength);

	myList->toString();





	delete myList;

	_CrtDumpMemoryLeaks();

}














bool DoQueenStuff(char grid[n][n], int targetRow, int targetCol)
{
	bool placement = true;

	// navigate along the row by moving along the columns	
	for (int i = 0; i < n; i++)
	{
		if (grid[targetRow][i] == 'Q')
		{
			placement = false;
			break;

		}
	}


	// navigate along the columns by moving along the row
	for (int i = 0; i < n; i++)
	{
		if (grid[i - 1][targetCol] == 'Q')
		{
			placement = false;
			break;

		}

	}

	{
		// searching diagonally down right
		int copyRow = targetRow + 1;
		int copyCol = targetCol + 1;


		for (int i = 0; i < n; i++)
		{
			if (copyRow >= n || copyCol >= n)
			{
				break;
			}
			else if (grid[copyRow][copyCol] == 'Q')
			{
				placement = false;

			}
			copyRow++;
			copyCol++;

		}

	}

	{
		// searching diagonally up right
		int copyRow = targetRow - 1;
		int copyCol = targetCol + 1;


		for (int i = 0; i < n; i++)
		{
			if (copyRow < 0 || copyCol >= n) // if the row or column is greater than the length this will prevent a read access violation
			{
				break;
			}
			else if (grid[copyRow][copyCol] == 'Q')
			{
				placement = false;

			}
			copyRow--;
			copyCol++;

		}

	}
	{
		// searching diagonally up left
		int copyRow = targetRow - 1;
		int copyCol = targetCol - 1;


		for (int i = 0; i < n; i++)
		{
			if (copyRow < 0 || copyCol < 0)
			{
				break;
			}
			else if (grid[copyRow][copyCol] == 'Q')
			{
				placement = false;

			}
			copyRow--;
			copyCol--;

		}
	}

	{
		// searching diagonally down left
		int copyRow = targetRow + 1;
		int copyCol = targetCol - 1;


		for (int i = 0; i < n; i++)
		{
			if (copyRow < 0 || copyCol >= n)
			{
				break;
			}
			else if (grid[copyRow][copyCol] == 'Q')
			{
				placement = false;

			}
			copyRow--;
			copyCol++;

		}
	}


	return placement;

}