#pragma once
#include "CPrefixPostfixContainer.h"
class CPrefixPostfixSolution
{
private:

	string testEquation = "6^2*(1+2)";

	string equation;
	string solution;
	CPrefixPostfixContainer* mPostfixStack;
	CPrefixPostfix* mPostfixStackElement;
	//CPrefixPostfixContainer* mPrefixStack;
public:

	CPrefixPostfixSolution(string userInput);
	~CPrefixPostfixSolution();

	void algorithm();
	bool isOperator(char c);
	int priority(char );

};

