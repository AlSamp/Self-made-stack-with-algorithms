#include "CPrefixPostfixSolution.h"

CPrefixPostfixSolution::CPrefixPostfixSolution(string userInput)
{
	solution = "";
	equation = userInput;
	mPostfixStackElement = nullptr;
	mPostfixStack = new CPrefixPostfixContainer();
}

CPrefixPostfixSolution::~CPrefixPostfixSolution()
{
	delete mPostfixStack;
}

void CPrefixPostfixSolution::algorithm()
{
	enum EOperators {power,times,divide,add,subtrack,openBrackets,closedBrackets};
	EOperators;


	//int i = 0;
	////string testEquation = "6^2*(1+2)";
	//string testEquation = "4*8^2+1";
	//cout << testEquation << endl;
	////equation[i] for user input equations
	//while (testEquation[i] != 0)				// terminates at null terminator
	//{
	//
	//	cout << "Solution is currently : " << solution << endl;
	//	if (isOperator(testEquation[i]) == false) // equal to not operand)
	//	{
	//		solution += testEquation[i];
	//		//solution += equation[i];
	//		//cout << equation[i] << "is not an operator" << endl;
	//
	//		i++;	//increment i after operand has added.
	//	}
	//	else // push all of the operators to the stack
	//	{
	//
	//		if (priority(testEquation[i]) == 1) // curerntly looking at an operator
	//		{
	//			cout << "Power found " << endl;
	//			mPostfixStack->push(testEquation[i]);
	//			mPostfixStackElement = mPostfixStack->top(); // get the address of the new top element
	//			solution += testEquation[++i];// append the char after the power symbol onto the solution
	//
	//			solution += mPostfixStackElement->getData(); // append top of the stack;
	//			mPostfixStack->pop(); // remove the just added operator
	//			//mPostfixStackElement = nullptr;
	//
	//			i++; //move onto the next char for inspection
	//		}
	//		else if (priority(testEquation[i]) == 2)
	//		{
	//			
	//			//cout << "Multiplication/Division found " << endl;
	//			//mPostfixStack->push(testEquation[i]); // push operand onto the stack
	//			//
	//			//cout << " here ----> " << mPostfixStack->top()->getData() << endl; // confirming * is on stack
	//			i++;
	//		}
	//		//else if (priority(testEquation[i]) == 3)
	//		//{
	//		//	cout << "Addition / Subtraction found " << endl;
	//		//
	//		//	mPostfixStack->push(testEquation[i]); // push operand onto the stack
	//		//	i++;
	//		//	
	//		//}
	//		//else if (priority(testEquation[i]) == 4)
	//		//{
	//		//	cout << "Open Brackets found " << endl;
	//		//	i++;
	//		//}
	//		//else if (priority(testEquation[i]) == 5)
	//		//{
	//		//	cout << "Closed Brackets found " << endl;
	//		//	i++;
	//		//}			
	//		else // its will just be an operand
	//		{
	//			//solution += testEquation[++i];
	//			i++;
	//
	//		}
	//		//if(testEquation[i])
	//		
	//		//i++; //increment i after operator has been added.
	//	}
	//
	//}
	
	
	
	//solution += mPostfixStack->top()->getData(); // appends operators onto the solution
	
	
	//cout << solution << endl;
	cout << "sfidshfisdhfishdbfhb" << endl;
	mPostfixStack->push('*');
	cout << mPostfixStack->getHead()->getData() << endl;
	mPostfixStack->push('^');
	cout << mPostfixStack->top()->getData() << endl;
	mPostfixStack->pop();
	cout << mPostfixStack->top()->getData() << endl;
	cout << mPostfixStack->getHead()->getData() << endl;
	mPostfixStack->pop();

	


	//	mPostfixStack->pop();
	//	cout << mPostfixStack->top()->getData() << endl;
	//	mPostfixStack->pop();
	//mPostfixStack->push('X');



	
	cout << endl;
	

	

	cout << "algorithm has successfully started" << endl;

}

int CPrefixPostfixSolution::priority(char c)
{
	switch (c)
	{
	case '^':

		return 1;
		break;

	case '*':

		return 2;
		break;

	case '/':

		return 2;
		break;

	case '+':

		return 3;
		break;

	case '-':

		return 3;
		break;

	case '(':

		return 4;
		break;

	case ')':

		return 5;
		break;
	default:
		break;
	}
}

bool CPrefixPostfixSolution::isOperator(char c)
{
	switch (c)
	{
	case '^':

		return true;
		break;

	case '*':

		return true;
		break;

	case '/':

		return true;
		break;

	case '+':

		return true;
		break;

	case '-':

		return true;
		break;

	case '(':

		return true;
		break;

	case ')':

		return true;
		break;
	default:
		return false;
	}


}