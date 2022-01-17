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
	mpStackElement = mpStack->top(); // This points to the first Element of the stack
	char** ppTheGrid = mpStackElement->getGrid(); // This holds the grid address on the element
	nQueenPlacement(ppTheGrid, 0, 0);		
}





bool CNqueenSolution::nQueenPlacement(char** grid, int row, int col)
{
	static int count = 0;
	int previousRow = row;
	int previousCol = col;
	static int queenCount = 0;
	

	CNqueenGrid* topOfTheStack = mpStack->top();

	if (nQueenSolutionFound(topOfTheStack->getGrid()) == true)
	{
		mpStack->pop();
		mpStackElement = mpStack->top();
		return false; // exit this loop
	}
	else if (col == n) // second base case for col
	{
		cout << "Backtracking" << endl;
		mpStack->pop();
		mpStackElement = mpStack->top();
		return false;
	}
	else
	{
		for (int i = col; i < n; i++)
		{
				//cout << "the grid" << endl;
				//mpStackElement->print();
				//gridSeperator();

			if (nQueenCheck(grid, row, i) == true) // if place available
			{

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

				if (row + 1 < n)
				{
				//cout << "search for next queen placement on row + 1 : (" << row + 1<< ") " << endl;
				nQueenPlacement(newGrid, row + 1, 0); // recrusive call !!! checks next row placements

				}
				
				
			}
			else
			{
				
				
				nQueenPlacement(grid,row,col + 1); // place a queen at the next available col
				col++;

				return false;

			}
			col++; // move onto next column
		}
				
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


bool CNqueenSolution::nQueenSolutionFound(char** grid)
{
	static int solutionsFound = 0;
	int queenCounter = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == QUEEN)
			{
				queenCounter++;
			}
		}
	}
	//cout << " <--------------------------------------v" << endl;
	//cout << queenCounter << " Queens found in grid :)" << endl;
	//mpStackElement->print();
	//cout << " <--------------------------------------^" << endl;



	if (queenCounter == n)
	{
		solutionsFound++;

		gridSeperator();
		mpStackElement->print(); 
		cout << "solutions found = " << solutionsFound << endl;
		gridSeperator();

		return true;

	}
	else
	{
		return false;
	}

}