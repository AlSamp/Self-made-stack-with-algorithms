#include "CPrefixPostfix.h"

CPrefixPostfix::CPrefixPostfix(char input)
{
	mEquationSegment = input;
	mpNextNode = nullptr;
}

CPrefixPostfix::~CPrefixPostfix()
{
	cout << "Prefixpostfix destructor called" << endl;
}

CPrefixPostfix* CPrefixPostfix::getNext()
{
	return mpNextNode;
}

void CPrefixPostfix::setNext(CPrefixPostfix* nextNode)
{
	mpNextNode = nextNode;
}

char CPrefixPostfix::getData()
{
	return mEquationSegment;
}

void CPrefixPostfix::print()
{
	cout << mEquationSegment;
}