#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "CNqueenSolution.h"

using namespace std;

const int n = 4;

using namespace std;



int main()
{
	int input;
	cout << "Please enter a number" << endl;
	cin >> input;

	CNqueenSolution* solution = new CNqueenSolution(input);

	solution->algorithm();
	delete solution;
	
	cout << "end of program" << endl;

	_CrtDumpMemoryLeaks();

}











