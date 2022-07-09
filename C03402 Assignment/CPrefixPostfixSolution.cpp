#include "CPrefixPostfixSolution.h"

CPrefixPostfixSolution::CPrefixPostfixSolution(string userInput)
{
	mPostfixSolution = "";

	mEquation = userInput;
	mEquation2 = "";
	mpStackElement = nullptr;
	mpOperatorStack = new CPrefixPostfixContainer();

	mPrefixSolution = "";
	mPostfixSolution = "";
}

CPrefixPostfixSolution::~CPrefixPostfixSolution()
{
	delete mpOperatorStack;
}

string CPrefixPostfixSolution::postfixAlgorithm(string equation)
{
	
	cout << "Starting the algorithm " << endl;
	cout << "The starting equation is " << equation << endl;
	cout << endl;

	int index = 0;
	
	while (equation[index] != 0) // end loop at null terminator
	{
		cout << "Checking : " << equation[index] << endl;
		cout << "Currently the solution is " << mPostfixSolution << endl;
		if (mpOperatorStack->isEmpty() == false)
		{
			cout << "Currently on the stack : ";
			mpOperatorStack->toString();
			cout << endl << endl << endl;
		}

		
		if (isOperator(equation[index]) == false) // if a number is found instead of an operator
		{
			cout << "Number: "<< equation[index] << " found"   << endl;
			mPostfixSolution += equation[index]; // add number to the solution
			cout << endl;
		}
		else // if an operator is found
		{
			if (equation[index] != '(' || equation[index] != ')')
			{				
				mPostfixSolution += ' '; // add a space to the solution		
			}
			
			if (priority(equation[index]) == 5) // if a ^ char is found					(Power found)
			{
				cout << "Power has been found and added to stack" << endl;
				mpOperatorStack->push(equation[index]); // Place ^ on to the stack
				
				if (!mpOperatorStack->isEmpty()) //if stack not empty.
				{
					if (priority(mpOperatorStack->top()->getData()) < 5)
					{
						cout << "^ goes before all other operators on stack" << endl;
						cout << "appending to solution and popping operator from operator stack" << endl;
						mPostfixSolution += equation[index]; // append ^ to solution.
						mPostfixSolution += mpOperatorStack->top()->getData(); // append operator on stack to solution.
						mPostfixSolution += ' '; // append space.
						mpOperatorStack->pop(); // remove operator from stack.
					}
				}

			}
			else if (priority(equation[index]) == 4) // if a * or / char is found		(Multiplication/Division found)
			{
				cout << "Multiplication/Division had been found and added to stack" << endl;
				if (!mpOperatorStack->isEmpty()) //if stack not empty.
				{
					mpStackElement = mpOperatorStack->top(); // get the top element of the operator stack.
					if (priority(mpStackElement->getData()) >= priority(equation[index])) // compare priority of top operator with current operator.
					{
						int previous = priority(mpOperatorStack->top()->getData()); // track the priority of the top element of the stack.
						mPostfixSolution += mpOperatorStack->top()->getData(); // append operator to solution.
						mPostfixSolution += ' '; // append space.
						mpOperatorStack->pop(); // remove operator from stack.
						

						if (!mpOperatorStack->isEmpty()) // check if stack is not empty after pop
						{
							if (previous == 5 && priority(mpOperatorStack->top()->getData()) == 4) // if the previous top priority was * or / and the current priority is + or - also pop and append.
							{
								cout << "^ before * or / on stack, impeltementing right to left association" << endl;
								cout << "appending to solution and popping * or / from operator stack" << endl;
								mPostfixSolution += mpOperatorStack->top()->getData(); // append operator to solution.
								mPostfixSolution += '!'; // append space.
								mpOperatorStack->pop(); // remove operator from stack.
							}
						}

					}
				}

				mpOperatorStack->push(equation[index]); // Place * or / on to the stack
			}
			else if (priority(equation[index]) == 3) // if a + or - char is found		(Addition/Subtraction found)
			{
				cout << "Addition or Subtration has been found and added to stack" << endl;
				
				if (!mpOperatorStack->isEmpty())
				{
					if (priority(mpOperatorStack->top()->getData()) >= priority(equation[index])) // if the top element of the stack has a higher or equal priority than the current operator in the equation.
					{
						cout << "operator on stack has higher priority than current operator in equation" << endl;
						cout << "appened stack operator to solution and pop from stack" << endl;
						int previous = priority(mpOperatorStack->top()->getData()); // track the priority of the top element of the stack.
						mPostfixSolution += mpOperatorStack->top()->getData(); // append operator to solution.
						mPostfixSolution += ' '; // append space.
						mpOperatorStack->pop(); // remove operator from stack.

						if (!mpOperatorStack->isEmpty()) // check stack isnt empty after pop
						{
						
							if (previous == 5 && priority(mpOperatorStack->top()->getData()) < 5)
							{
								if (mpOperatorStack->top()->getData() != '(')
								{
									cout << "^ was previously on stack. impeltementing right to left association" << endl;
									cout << "appending to operator solution and popping operator from stack" << endl;
									mPostfixSolution += mpOperatorStack->top()->getData(); // append operator to solution.
									mPostfixSolution += ' '; // append space.
									previous = priority(mpOperatorStack->top()->getData()); // track the priority of the top element of the stack before pop.
									mpOperatorStack->pop(); // remove operator from stack.
								}
							}
							
							if (!mpOperatorStack->isEmpty()) // check stack is not empty if there was just a pop from stack
							{
								if (previous == 4 && priority(mpOperatorStack->top()->getData()) == 3) // if the previous top priority was * or / and the current priority is + or - also pop and append.
								{
									cout << "* or / found before + or - on stack" << endl;
									cout << "appending to solution and popping + or - from operator stack" << endl;
									mPostfixSolution += mpOperatorStack->top()->getData(); // append operator to solution.
									mPostfixSolution += ' '; // append space.
									mpOperatorStack->pop(); // remove operator from stack.
								}						
								
							}
						}

					}
				}

				mpOperatorStack->push(equation[index]); // Place + or - on to the stack
			}
			else if (priority(equation[index]) == 2) // if a "(" char is found			(Opening Bracket found)
			{
				cout << "opening bracket has been found" << endl;
				mpOperatorStack->push(equation[index]);
			}
			else if (priority(equation[index]) == 1) // if a ")" char is found			(Closing Bracket found)
			{
				cout << "closing bracket has been found" << endl;
				cout << "appending and popping operators until '(' found" << endl;
				while(mpOperatorStack->top()->getData() != '(') // while the top element of the stack is not an opening bracket.
				{
					cout << mpOperatorStack->top()->getData() << " appended to solution" << endl;
					if (mpOperatorStack->top()->getData() != '(') // append operators to solution
					{
						mPostfixSolution += mpOperatorStack->top()->getData(); // append operator to solution.
						mPostfixSolution += ' '; // append space.
						mpOperatorStack->pop(); // remove operator from stack.						
					}
				}
				mpOperatorStack->pop(); // pop ( from stack.

				// check top of stack

				//compare priority of top operator with current operator.
				
			}
			else 
			{
				cout << "Error: Unknown operator : '" << equation[index] << "'" << endl;
			
				break; // end loop
			}
		}
		index++; // move along to next char
	}
	
	cout << "End of equation reached appending and popping remaining viable stack operators " << endl;
	for (int i = mpOperatorStack->size(); i > 0; i--) // once at the end of the equation, pop all remaining operators off the stack.
	{
		if (isOperator(mpOperatorStack->top()->getData())) // ignore appending of ( operator on stack to solution
		{	
			mPostfixSolution += ' '; // add a space to the solution		
			mPostfixSolution += mpOperatorStack->top()->getData(); // append operator at the top of the stack to solution.
			cout << mpOperatorStack->top()->getData() << " appended to solution" << endl;
		}
			mpOperatorStack->pop(); // remove operator from stack.
	}
	
	cout << endl;



	for (int i = 0; i < mPostfixSolution.size(); i++) // remove double spaces.
	{
		if (mPostfixSolution[i] == ' ' && mPostfixSolution[i + 1] == ' ')
		{
			mPostfixSolution.erase(i, 1);
		}
	}

	return mPostfixSolution;

}

int CPrefixPostfixSolution::priority(char c)
{
	switch (c)
	{
	case '^':

		return 5;
		break;

	case '*':

		return 4;
		break;

	case '/':

		return 4;
		break;

	case '+':

		return 3;
		break;

	case '-':

		return 3;
		break;

	case '(':

		return 2;
		break;

	case ')':

		return 1;
		break;
	default:
		break;
	}
}

string CPrefixPostfixSolution::prefixAlgorithm(string equation)
{

	cout << "Starting the PREFIX solution" << endl;

	
	string reversedEquation = ""; // create a string to store the reversed equation.
	string reversedSolution = "";


	cout << "Reversing the equation" << endl;
	
	for (int i = mEquation.length() - 1; i >= 0; i--)
	{

		if (mEquation[i] == ')') // reverse closing bracket
		{
			reversedEquation += "(";
		}
		else if (mEquation[i] == '(') // reverse opening bracket
		{
			reversedEquation += ")";
		}
		else // add operator to the reverse
		{
			reversedEquation += mEquation[i];
		}
	}

	cout << "The Reversed Equation : " << reversedEquation << endl;
	cout << "this needs to be solved " << reversedEquation << endl;


	int index = 0; 
	
	while (reversedEquation[index] != 0) // end at null terminator
	{
		if (mpOperatorStack->isEmpty() == false) // output contents of stack
		{
			cout << "Currently on the PREFIX stack : ";
			mpOperatorStack->toString();
			cout << endl;
		}

		if (isOperator(reversedEquation[index]) == false) // if a number is found instead of an operator
		{
			cout << "Number: " << reversedEquation[index] << " found" << endl;
			reversedSolution += reversedEquation[index]; // add number to the solution
			cout << endl;
		}
		else // if an operator is found
		{
			cout << "Operator: " << reversedEquation[index] << " found" << endl; 
		
			if (reversedEquation[index] != '(' || reversedEquation[index] != ')')
			{
				if (reversedSolution[reversedSolution.size()] != ' ') // if the last element of the solution is not a space, add a space.
				{
					reversedSolution += ' '; // add space when operator is found				
				}
				
			}
			
			if (mpOperatorStack->isEmpty() == true) // if the stack is empty
			{
				cout << "Pushing operator '" << reversedEquation[index] << " 'onto stack" << endl;
				mpOperatorStack->push(reversedEquation[index]); // push operator onto stack

			}
			else // if the stack is not empty
			{

				if (priority(reversedEquation[index]) >= priority(mpOperatorStack->top()->getData()))
				{					
					mpOperatorStack->push(reversedEquation[index]); // push operator onto stack
				}
				else if (priority(reversedEquation[index]) == 2) // if a opening bracket is found
				{
					cout << "Opening bracket found" << endl;
					cout << "Pushing operator onto stack" << endl;
					mpOperatorStack->push(reversedEquation[index]); // push operator onto stack
					
				}
				else if (priority(reversedEquation[index]) == 1) // if a closing bracket is found
				{
					cout << "Closing bracket found" << endl;

					cout << "Appending and popping operators until opening bracket found" << endl;
					while (mpOperatorStack->top()->getData() != '(') // while the top element of the stack is not an opening bracket.
					{
						cout << mpOperatorStack->top()->getData() << " appended to solution" << endl;
						if (mpOperatorStack->top()->getData() != '(') // append operators to solution
						{
							reversedSolution += mpOperatorStack->top()->getData(); // append operator to solution.
							mpOperatorStack->pop(); // remove operator from stack.
						}
						reversedSolution += ' ';
					}
					mpOperatorStack->pop(); // pop ( from stack.
				}
				else
				{
					reversedSolution += mpOperatorStack->top()->getData(); // append operator to solution
					reversedSolution += ' '; // append space to solution
					mpOperatorStack->pop(); // pop operator from stack
					mpOperatorStack->push(reversedEquation[index]);
				}

			}
		}
			
		index++;
	}

	cout << "End of equation reched popping remaining operators" << endl;

	for (int i = mpOperatorStack->size(); i > 0; i--)
	{
		reversedSolution += ' '; // append space to solution
		reversedSolution += mpOperatorStack->top()->getData(); // append operator to solution
		mpOperatorStack->pop(); // pop operator from stack
	}

	cout << "The reversed prefix solution is : " << reversedSolution << endl;

	cout << "Reversing the equation" << endl;


	for (int i = 0; i < reversedSolution.size(); i++) // remove double spaces.
	{
		if (reversedSolution[i] == ' ' && reversedSolution[i+1] == ' ')
		{
			reversedSolution.erase(i,1);
		}
	}
	

	for (int i = reversedSolution.length() - 1; i >= 0; i--) // reverse solution.
	{
			mPrefixSolution += reversedSolution[i];
	}

	
	return mPrefixSolution;
}

void CPrefixPostfixSolution::prefix()
{




	cout << prefixAlgorithm(mEquation);

	//string reversedSolution = prefixAlgorithm(reversedEquation);
	//
	//string prefixSolution;
	//for (int i = reversedSolution.length() - 1; i >= 0; i--)
	//{
	//	prefixSolution += reversedSolution[i];
	//}
	//
	////cout << "The reversed equation :	" << reversedEquation << endl;
	//cout << "The PREFIX Solution :	" << prefixSolution << endl;
	//
	//mPrefixSolution = prefixSolution;
	
}


void CPrefixPostfixSolution::postfix()
{
	cout << "Starting the POSTFIX solution" << endl;
	string postfixSolution = postfixAlgorithm(mEquation);
	cout << "Postfix solution = " << postfixSolution << endl;

	mPostfixSolution = postfixSolution;
}
//
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

//void CPrefixPostfixSolution::algorithm()
//{
//	enum EPriority {p1,p2,p3,p4};
//	EPriority power		= p1;
//	EPriority times		= p2;
//	EPriority divide	= p2;
//	EPriority add		= p3;
//	EPriority subtract	= p4;
//	EPriority EPower	= p4;
//
//
//	int i = 0;
//	int stackCount = 0;
//	//string testEquation = "6^2*(1+2)";
//	//string testEquation = "78+(30-0.5(28+8))/6";
//	//string testEquation = "4*8^2+1";
//	string testEquation = "5-3*(2^3-5+7*(-3))";
//
//	cout << testEquation << endl;
//	//equation[i] for user input equations
//	while (testEquation[i] != 0)				// terminates at null terminator
//	{
//	
//		cout << "Solution is currently : " << solution << endl;
//		if (isOperator(testEquation[i]) == false) // equal to not operand)
//		{
//			solution += testEquation[i];
//			//solution += equation[i];
//			//cout << equation[i] << "is not an operator" << endl;
//	
//			i++;	//increment i after operand has added.
//		}
//		else // push all of the operators to the stack
//		{
//	
//			if (priority(testEquation[i]) == 1) // curerntly looking at an operator
//			{
//				cout << "Power found " << endl;
//				mPostfixStack->push(testEquation[i]);
//				stackCount++;
//				mPostfixStackElement = mPostfixStack->top(); // get the address of the new top element
//				solution += testEquation[++i];// append the char after the power symbol onto the solution
//	
//				solution += mPostfixStackElement->getData(); // append top of the stack;
//				mPostfixStack->pop(); // remove the just added operator
//				stackCount--;
//				//mPostfixStackElement = nullptr;
//	
//				i++; //move onto the next char for inspection
//			}
//			else if (priority(testEquation[i]) == 2)
//			{
//				
//				cout << "Multiplication/Division found " << endl;
//				//mPostfixStackElement = mPostfixStack->top();
//				mPostfixStack->push(testEquation[i]); // push operand onto the stack
//				stackCount++;
//
//				 
//				 //cout << " here ----> " << mPostfixStack->top()->getData() << endl; // confirming * is on stack
//
//				 i++;
//				
//
//			}
//			else if (priority(testEquation[i]) == 3)
//			{
//				cout << "Addition / Subtraction found " << endl;
//
//				if (stackCount != 0)
//				{
//					cout << "Here" << endl;
//					mPostfixStackElement = nullptr;
//					mPostfixStackElement = mPostfixStack->top();
//
//					if (priority(mPostfixStackElement->getData()) == 2)// multiplication
//					{
//						solution += mPostfixStack->top()->getData(); // append operator on to solution
//						mPostfixStack->pop();
//						stackCount--;
//
//						//cout << "Solution is currently : " << solution << endl;
//					}
//					else if (priority(mPostfixStackElement->getData()) == 3)
//					{
//						solution += mPostfixStack->top()->getData(); // append operator on to solution
//						mPostfixStack->pop();
//						stackCount--;
//					}
//					else if (priority(mPostfixStackElement->getData()) == 5)
//					{
//
//					}
//					
//				}
//
//					mPostfixStack->push(testEquation[i]); // push operand onto the stack
//					stackCount++;
//					i++; // move i across to look at next char
//	
//			}
//			else if (priority(testEquation[i]) == 4)
//			{
//				cout << "Open Brackets found " << endl;
//				mPostfixStack->push(testEquation[i]); // push operand onto the stack
//				stackCount++;
//				i++;
//			}
//			else if (priority(testEquation[i]) == 4)
//			{
//				cout << "Closed Brackets found " << endl;
//				mPostfixStack->push(testEquation[i]); // push operand onto the stack
//				stackCount++;
//				i++;
//			}			
//			else // its will just be an operand
//			{
//				//solution += testEquation[++i];
//				i++;
//			
//			}
//		
//		}
//	
//	}
//
//	
//	
//	for (int j = stackCount; j > 0; j--)
//	{
//		mPostfixStackElement = mPostfixStack->top();	
//		if (priority(mPostfixStackElement->getData()) == 4 || priority(mPostfixStackElement->getData()) == 5)
//		{
//			mPostfixStack->pop();
//		}
//		else
//		{
//			solution += mPostfixStack->top()->getData();
//			//cout << "top of stack = " << mPostfixStack->top()->getData() << endl;
//			mPostfixStack->pop();
//
//		}
//	}
//	
//	cout << "Solution = " << solution << endl;
//	//solution += mPostfixStack->top()->getData(); // appends operators onto the solution
//	
//	
//
//	
//	cout << endl;
//	
//
//	
//
//	cout << "algorithm has successfully finshed " << endl;
//
//}
//