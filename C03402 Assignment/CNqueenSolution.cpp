#include "CNqueenSolution.h"
#include <iostream>
using namespace std;

CNqueenSolution::CNqueenSolution(int input)
{
	n = input;
	matrix = n * n;
	mpStack = new CNqueenContainer();
	mpStackElement = nullptr;

}

CNqueenSolution::~CNqueenSolution()
{
	delete mpStack;
}

void CNqueenSolution::algorithm()
{
	mpStack->push(n); // This will create the first Element of the stack with a grid of n x n
	mpStackElement = mpStack->getHead(); // This points to the first Element of the stack
	char** ppTheGrid = mpStackElement->getGrid(); // This holds the grid address on the element
	int pushCount = 1;
	int row = 0;
	int col = 0;
	int loops = 0;



	int numSolutions = 0;
	// going through each starting point
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
				col = 0;
				row++;
			}

			//ppTheGrid[row][col] = 'Q';
			if (nQueenPlacement(ppTheGrid, row, col) == true)
			{
				numSolutions++;
				mpStackElement->print(); // only print solutions
				gridSeperator();

			}
			mpStack->push(n);							// push a new element on to the stack
			mpStackElement = mpStackElement->getNext(); //move along stack element pointer to the next element in the list that was just created
			ppTheGrid = mpStackElement->getGrid();		// set the grid pointer to that elements grid.


			col++;
		}

	}
	cout << "Number of solutions found = " << numSolutions << endl;
	

}

void CNqueenSolution::gridSeperator() //adds lines inbetween grids
{
	for (int i = 0; i < n; i++)
	{
		cout << "_";
	}
	cout << endl;
}





bool CNqueenSolution::nQueenPlacement(char** grid, int row, int col)
{
	bool solutionFound = false;
	int queenCount = 0;
	while (row != n) // 0 based index, once row is 4 a read access violation will happen so end the loop before that happens.
	{
		if (nQueenCheck(grid, row, col) == true && col != n) // if grid target is available, set it to be a Queen
		{												// make sure it doesnt write something out of bounds. avoid writing over memory with col != n
			grid[row][col] = QUEEN;

			if (grid[row][col] == QUEEN) 
			{
				queenCount++;
			}

		}
		else
		{
			if (col == n) //at then end of a row move on to the next row and set column to 0.
			{
				row++;
				col = 0;
			}
			else		 // else move along the column on the row
			{
				col++;
			}
		}
	}

	if (queenCount == n)
	{
		solutionFound = true;
	}

	return solutionFound;

}


bool CNqueenSolution::nQueenCheck(char** grid, int targetRow, int targetCol)
{
	bool placement = true;

	// navigate along the row by moving along the columns	
	for (int i = 0; i < n; i++)
	{
	
		if (grid[targetRow][i] == QUEEN)
		{
			placement = false;
			break;

		}
	}


	// navigate along the columns by moving along the row
	for (int i = 0; i < n; i++)
	{
		if (grid[i][targetCol] == QUEEN)
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
			else if (grid[copyRow][copyCol] == QUEEN)
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
			else if (grid[copyRow][copyCol] == QUEEN)
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
			else if (grid[copyRow][copyCol] == QUEEN)
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
			if (copyRow >= n || copyCol < 0)
			{
				break;
			}
			
			if (grid[copyRow][copyCol] == QUEEN)
			{
				placement = false;

			}
			copyRow++;
			copyCol--;

		}
	}


	return placement;

}