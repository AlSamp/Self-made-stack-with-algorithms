
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "CPrefixPostfixSolution.h"
#include "CNqueenSolution.h"

#include <string>

using namespace std;

int input = NULL;

void MenuSelection( int userInput);
void NQueens(int input);
void PrefixPostfix();

int main()
{
	{
	cout << "1. NQueens Problem" << endl
	
		<< "2. Infix to prefix/postfix" << endl;
	
	cin >> input;
	
	MenuSelection(input);
	}
	_CrtDumpMemoryLeaks();

}





void MenuSelection(int userInput)
{

	switch (userInput)
	{
	case 1:
		NQueens(userInput);


		break;
	case 2:

		PrefixPostfix();
	default:
		break;
	}
}


void NQueens(int input)
{
	int number;
	cout << "Please enter a number for the grid size of the N Queens problem" << endl;
	cin >> number;
	CNqueenSolution* solution = new CNqueenSolution(number);
	solution->algorithm();
	delete solution;
	cout << "end of program" << endl;
}

void PrefixPostfix()
{
	string userEquation;
	cout << "Please enter an equation" << endl;
	cin >> userEquation;
	CPrefixPostfixSolution* solution = new CPrefixPostfixSolution(userEquation);
	solution->prefix();
	solution->postfix();
	cout << endl << endl;
	cout << "the prefix solution  :	" << solution->mPrefixSolution << endl;
	cout << "the postfix solution :	" << solution->mPostfixSolution << endl;
	
	cout << "end of program" << endl;

	delete solution;

}

