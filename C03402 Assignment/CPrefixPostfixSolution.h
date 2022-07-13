#pragma once
#include "CPrefixPostfixStacks.h"
#include <math.h> // for pow()

using namespace std;

class CPrefixPostfixSolution
{
private:
	string mEquation;
	CCharStack* mpCharStack;
	CDoubleStack* mpDoubleStack;

public:
	string mPrefixSolution;
	string mPostfixSolution;

	CPrefixPostfixSolution(string userInput);
	~CPrefixPostfixSolution();

	string postfixAlgorithm(string equation);
	void calculatePostfix();
	void calculatePrefix();
	string prefixAlgorithm(string equation);
	double calculate(char operant, double operand1, double operand2);
	bool isOperator(char c);
	int	 priority(char );
	void prefix();
	void postfix();

};

