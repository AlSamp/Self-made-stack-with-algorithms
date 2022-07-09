#pragma once
#include "CPrefixPostfixContainer.h"

using namespace std;

class CPrefixPostfixSolution
{
private:

	//string equation = "6^2*(1+2)";
	// string solution should = 62^12+*

	string mEquation;
	string mEquation2;
	CPrefixPostfixContainer* mpOperatorStack;
	CPrefixPostfix* mpStackElement;
	//CPrefixPostfixContainer* mPrefixStack;
public:

	string mPrefixSolution;
	string mPostfixSolution;
	CPrefixPostfixSolution(string userInput);
	~CPrefixPostfixSolution();

	string postfixAlgorithm(string equation);
	string prefixAlgorithm(string equation);
	bool isOperator(char c);
	int	 priority(char );
	void prefix();
	void postfix();

};

