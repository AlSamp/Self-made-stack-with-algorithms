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
	mpStackElement->print();
	char** ppTheGrid = mpStackElement->getGrid(); // This holds the grid address on the element
	int pushCount = 1;
	int row = 0;
	int col = 0;

	for (int i = 0; i < n; i++) // maybe 
	{
		nQueenPlacement(ppTheGrid, 0, i);
		
	
	}


}





bool CNqueenSolution::nQueenPlacement(char** grid, int row, int col)
{

	int previousRow = row;
	//if (previousRow < 0) previousRow = 0;
	int previousCol = col;
	static int queenCount = 0;
	static int solutionsFound = 0;

	//CNqueenGrid* mpStackPreviousElement = mpStackElement; // keep track of previous stack element.


	//if (queenCount == n)
	//{
	//	queenCount--;
	//	return false;
	//}

	if (col == n) // second base case for col
	{
		return false;
	}

	if (row == n) // recursive base case
	{
		if (queenCount == n)
		{
			solutionsFound++;
			cout << "Solution : " << solutionsFound << endl;
			mpStackElement->print();
			gridSeperator();

		}
			//mpStackElement = mpStackPreviousElement;
			mpStack->pop();
			return false;
	}
	else
	{
		for (int i = col; i < n; i++)
		{
			if (nQueenCheck(grid, row, i) == true) // if place available
			{

				//// maybe if
				mpStack->push(n); // create another element with a grid of size n.
				mpStackElement = mpStack->top(); // place the pointer at the tail of the list
				char** newGrid = mpStackElement->getGrid(); // get the new elements grid

				for (int x = 0; x < n; x++) // copy over the grid before placement of queen.
				{
					for (int y = 0; y < n; y++)
					{
						newGrid[x][y] = grid[x][y];

					}

				}
	
				newGrid[row][i] = QUEEN; // new grid set to hold the position of the freshly placed queen
			
				
				
				
				cout << "Placing queen at " << row << "," << i << endl;
				queenCount++;// track the amount of queens
				cout << "Queen count = " << queenCount << endl;
				
				
				//previousCol = i;
				//
				nQueenPlacement(newGrid, row + 1, col = 0); // recrusive call !!! checks next row placements

			}
			else
			{
				
				nQueenPlacement(grid,row,col + 1); // place a queen at the next available col
				//mpStackElement = mpStackPreviousElement;
				mpStack->pop();
				queenCount--;
				if (queenCount < 0) queenCount = 0;
				return false;

			}

		}

				//mpStackElement = mpStackPreviousElement;
				//mpStack->pop();
				////grid[previousRow][previousCol] = '.'; // pop
				//cout << "Queen count = " << queenCount << endl;
				//cout << "Backtracking at " << previousRow << "," << previousCol << endl;
				//mpStackElement = mpStackPreviousElement;
				//mpStack->pop();
				
				
	}

}

void CNqueenSolution::gridSeperator() //adds lines inbetween grids
{
	for (int i = 0; i < n; i++)
	{
		cout << "_";
	}
	cout << endl;
}

bool CNqueenSolution::nQueenCheck(char** grid, int targetRow, int targetCol)
{


	// navigate along the row by moving along the columns	
	for (int i = 0; i < n; i++)
	{
	
		if (grid[targetRow][i] == QUEEN)
		{
			return false;

		}
	}


	// navigate along the columns by moving along the row
	for (int i = 0; i < n; i++)
	{
		if (grid[i][targetCol] == QUEEN)
		{
			return false;

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
				return false;

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
				return false;

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
				return false;

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
				return false;

			}
			copyRow++;
			copyCol--;

		}
	}

	return true;

}