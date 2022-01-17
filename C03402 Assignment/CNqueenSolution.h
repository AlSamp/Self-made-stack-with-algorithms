#pragma once
#include "CNqueenContainer.h"
#include <iostream>

class CNqueenSolution
{
private:

	int n;						 // Length of the grid will be (n x n)
	int matrix;
	const char QUEEN = 'Q';
	CNqueenContainer* mpStack;   // The stack itself
	CNqueenGrid* mpStackElement; // Will point to the element class on the stack.
public:
	CNqueenSolution(int input);
	~CNqueenSolution();
	void algorithm();
	void gridSeperator();
	bool nQueenCheck(char** grid, int row, int col);
	bool nQueenPlacement(char** grid, int row, int col);
	bool nQueenSolutionFound(char** grid);



};

