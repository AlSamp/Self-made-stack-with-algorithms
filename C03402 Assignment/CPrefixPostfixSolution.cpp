#include "CPrefixPostfixSolution.h"

CPrefixPostfixSolution::CPrefixPostfixSolution(string userInput)
{
	mPostfixSolution = "";
	mEquation = userInput;
	mpCharStack = new CCharStack();
	mpDoubleStack = new CDoubleStack();
	mPrefixSolution = "";
	mPostfixSolution = "";
}

CPrefixPostfixSolution::~CPrefixPostfixSolution()
{
	delete mpCharStack;
	delete mpDoubleStack;
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
		if (mpCharStack->isEmpty() == false)
		{
			cout << "Currently on the stack : ";
			mpCharStack->toString();
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
				mpCharStack->push(equation[index]); // Place ^ on to the stack
				
				if (!mpCharStack->isEmpty()) //if stack not empty.
				{
					if (priority(mpCharStack->top()->getData()) < 5)
					{
						cout << "^ goes before all other operators on stack" << endl;
						cout << "appending to solution and popping operator from operator stack" << endl;
						mPostfixSolution += equation[index]; // append ^ to solution.
						mPostfixSolution += mpCharStack->top()->getData(); // append operator on stack to solution.
						mPostfixSolution += ' '; // append space.
						mpCharStack->pop(); // remove operator from stack.
					}
				}

			}
			else if (priority(equation[index]) == 4) // if a * or / char is found		(Multiplication/Division found)
			{
				cout << "Multiplication/Division had been found and added to stack" << endl;
				if (!mpCharStack->isEmpty()) //if stack not empty.
				{
					
					if (priority(mpCharStack->top()->getData()) >= priority(equation[index])) // compare priority of top operator with current operator.
					{
						int previous = priority(mpCharStack->top()->getData()); // track the priority of the top element of the stack.
						mPostfixSolution += mpCharStack->top()->getData(); // append operator to solution.
						mPostfixSolution += ' '; // append space.
						mpCharStack->pop(); // remove operator from stack.
						

						if (!mpCharStack->isEmpty()) // check if stack is not empty after pop
						{
							if (previous == 5 && priority(mpCharStack->top()->getData()) == 4) // if the previous top priority was * or / and the current priority is + or - also pop and append.
							{
								cout << "^ before * or / on stack, impeltementing right to left association" << endl;
								cout << "appending to solution and popping * or / from operator stack" << endl;
								mPostfixSolution += mpCharStack->top()->getData(); // append operator to solution.
								mPostfixSolution += '!'; // append space.
								mpCharStack->pop(); // remove operator from stack.
							}
						}

					}
				}

				mpCharStack->push(equation[index]); // Place * or / on to the stack
			}
			else if (priority(equation[index]) == 3) // if a + or - char is found		(Addition/Subtraction found)
			{
				cout << "Addition or Subtration has been found and added to stack" << endl;
				
				if (!mpCharStack->isEmpty())
				{
					if (priority(mpCharStack->top()->getData()) >= priority(equation[index])) // if the top element of the stack has a higher or equal priority than the current operator in the equation.
					{
						cout << "operator on stack has higher priority than current operator in equation" << endl;
						cout << "appened stack operator to solution and pop from stack" << endl;
						int previous = priority(mpCharStack->top()->getData()); // track the priority of the top element of the stack.
						mPostfixSolution += mpCharStack->top()->getData(); // append operator to solution.
						mPostfixSolution += ' '; // append space.
						mpCharStack->pop(); // remove operator from stack.

						if (!mpCharStack->isEmpty()) // check stack isnt empty after pop
						{
						
							if (previous == 5 && priority(mpCharStack->top()->getData()) < 5)
							{
								if (mpCharStack->top()->getData() != '(')
								{
									cout << "^ was previously on stack. impeltementing right to left association" << endl;
									cout << "appending to operator solution and popping operator from stack" << endl;
									mPostfixSolution += mpCharStack->top()->getData(); // append operator to solution.
									mPostfixSolution += ' '; // append space.
									previous = priority(mpCharStack->top()->getData()); // track the priority of the top element of the stack before pop.
									mpCharStack->pop(); // remove operator from stack.
								}
							}
							
							if (!mpCharStack->isEmpty()) // check stack is not empty if there was just a pop from stack
							{
								if (previous == 4 && priority(mpCharStack->top()->getData()) == 3) // if the previous top priority was * or / and the current priority is + or - also pop and append.
								{
									cout << "* or / found before + or - on stack" << endl;
									cout << "appending to solution and popping + or - from operator stack" << endl;
									mPostfixSolution += mpCharStack->top()->getData(); // append operator to solution.
									mPostfixSolution += ' '; // append space.
									mpCharStack->pop(); // remove operator from stack.
								}						
								
							}
						}

					}
				}

				mpCharStack->push(equation[index]); // Place + or - on to the stack
			}
			else if (priority(equation[index]) == 2) // if a "(" char is found			(Opening Bracket found)
			{
				cout << "opening bracket has been found" << endl;
				mpCharStack->push(equation[index]);
			}
			else if (priority(equation[index]) == 1) // if a ")" char is found			(Closing Bracket found)
			{
				cout << "closing bracket has been found" << endl;
				cout << "appending and popping operators until '(' found" << endl;
				while(mpCharStack->top()->getData() != '(') // while the top element of the stack is not an opening bracket.
				{
					cout << mpCharStack->top()->getData() << " appended to solution" << endl;
					if (mpCharStack->top()->getData() != '(') // append operators to solution
					{
						mPostfixSolution += mpCharStack->top()->getData(); // append operator to solution.
						mPostfixSolution += ' '; // append space.
						mpCharStack->pop(); // remove operator from stack.						
					}
				}
				mpCharStack->pop(); // pop ( from stack.

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
	for (int i = mpCharStack->size(); i > 0; i--) // once at the end of the equation, pop all remaining operators off the stack.
	{
		if (isOperator(mpCharStack->top()->getData())) // ignore appending of ( operator on stack to solution
		{	
			mPostfixSolution += ' '; // add a space to the solution		
			mPostfixSolution += mpCharStack->top()->getData(); // append operator at the top of the stack to solution.
			cout << mpCharStack->top()->getData() << " appended to solution" << endl;
		}
			mpCharStack->pop(); // remove operator from stack.
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
		if (mpCharStack->isEmpty() == false) // output contents of stack
		{
			cout << "Currently on the PREFIX stack : ";
			mpCharStack->toString();
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
			
			if (mpCharStack->isEmpty() == true) // if the stack is empty
			{
				cout << "Pushing operator '" << reversedEquation[index] << " 'onto stack" << endl;
				mpCharStack->push(reversedEquation[index]); // push operator onto stack

			}
			else // if the stack is not empty
			{

				if (priority(reversedEquation[index]) >= priority(mpCharStack->top()->getData()))
				{					
					mpCharStack->push(reversedEquation[index]); // push operator onto stack
				}
				else if (priority(reversedEquation[index]) == 2) // if a opening bracket is found
				{
					cout << "Opening bracket found" << endl;
					cout << "Pushing operator onto stack" << endl;
					mpCharStack->push(reversedEquation[index]); // push operator onto stack
					
				}
				else if (priority(reversedEquation[index]) == 1) // if a closing bracket is found
				{
					cout << "Closing bracket found" << endl;

					cout << "Appending and popping operators until opening bracket found" << endl;
					while (mpCharStack->top()->getData() != '(') // while the top element of the stack is not an opening bracket.
					{
						cout << mpCharStack->top()->getData() << " appended to solution" << endl;
						if (mpCharStack->top()->getData() != '(') // append operators to solution
						{
							reversedSolution += mpCharStack->top()->getData(); // append operator to solution.
							mpCharStack->pop(); // remove operator from stack.
						}
						reversedSolution += ' ';
					}
					mpCharStack->pop(); // pop ( from stack.
				}
				else
				{
					reversedSolution += mpCharStack->top()->getData(); // append operator to solution
					reversedSolution += ' '; // append space to solution
					mpCharStack->pop(); // pop operator from stack
					mpCharStack->push(reversedEquation[index]);
				}

			}
		}
			
		index++;
	}

	cout << "End of equation reched popping remaining operators" << endl;

	for (int i = mpCharStack->size(); i > 0; i--)
	{
		reversedSolution += ' '; // append space to solution
		reversedSolution += mpCharStack->top()->getData(); // append operator to solution
		mpCharStack->pop(); // pop operator from stack
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

double CPrefixPostfixSolution::calculate(char operant, double operand1, double operand2)
{

	switch (operant)
	{
	case '^':

		return pow(operand1,operand2);
		break;

	case '*':

		return (operand1 * operand2);
		break;

	case '/':

		return (operand1 / operand2);
		break;

	case '+':

		return (operand1 + operand2);
		break;

	case '-':

		return (operand1 - operand2);
		break;
	}
	
}

void CPrefixPostfixSolution::prefix()
{
	cout << prefixAlgorithm(mEquation);	
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

void CPrefixPostfixSolution::calculatePrefix()
{
	cout << endl;
	cout << "---------------- Calulcate Prefix Solution : " << mPrefixSolution << endl;

	int index = mPrefixSolution.length() - 1; // start at the end of the string and ignore null terminator.
	while (index != -1)
	{
		if(!isOperator(mPrefixSolution[index]) && mPrefixSolution[index] != ' ') // if number is found
		{

			string number = "";
			string reverseNumber = "";
			//number += mPrefixSolution[index]; // add number to string
			//index--; // move along the string

				while (mPrefixSolution[index] != ' ') // if not at the end of the full number in the equation append the rest of it.
				{
					number += mPrefixSolution[index];
					index--;
				}				
				
				if (number.length() >= 2) // if number is 2 or more digits long
				{
					for (int i = number.length()- 1; i >= 0; i--)
					{
						reverseNumber += number[i];
					}

					mpDoubleStack->push(stod(reverseNumber)); // convert number into double and push onto stack.
				}
				else
				{
				mpDoubleStack->push(stod(number)); // convert number into double and push onto stack.
				cout << "Pushed " << number << " onto stack" << endl;
				cout << mpDoubleStack->top()->getData() << endl;
					
				}

	
			
		}
		else if (isOperator(mPrefixSolution[index]) == true && mPrefixSolution[index] != ' ') // if the character is an operator
		{
			cout << "Operator " << mPrefixSolution[index]  << " found" << endl;
			cout << "Pop two operands from stack" << endl;
			// get two opernads and them from stack.
			double operand1 = mpDoubleStack->top()->getData();			
			mpDoubleStack->pop();
			double operand2 = mpDoubleStack->top()->getData();
			mpDoubleStack->pop();
			
			cout << "Calculating " << operand1 << " " << mPrefixSolution[index] << " " << operand2 << endl;
			double result = calculate(mPrefixSolution[index], operand1, operand2); // calculate the result.
			cout << result  << " calculated and pushed onto stack" << endl;
			mpDoubleStack->push(result); // push result onto stack.
		}

		index--;
	}
	cout << "End of prefex expression reached." << endl;
	cout << mPrefixSolution << " = " << mpDoubleStack->top()->getData() << endl;
	mpDoubleStack->pop(); //pop the last element of a list.
}

void CPrefixPostfixSolution::calculatePostfix()
{
	cout << endl;
	cout << "---------------- Calulcate Postfix Solution : " <<  mPostfixSolution << endl;
	int index = 0;

	while (mPostfixSolution[index] != NULL)
	{
		if (!isOperator(mPostfixSolution[index]) && mPostfixSolution[index] != ' ') // if a number is found
		{
			string number = "";
			number += mPostfixSolution[index]; // add number to string
			index++; // move along the string
		
			while (mPostfixSolution[index] != ' ') // if not at the end of the full number in the equation append the rest of it.
			{
				number += mPostfixSolution[index];
				index++;
			}			
				mpDoubleStack->push(stod(number)); // convert number into double and push onto stack.
				cout << "Pushed " << number << " onto stack" << endl;
				cout << mpDoubleStack->top()->getData() << endl;	
		}
		else // operator is found
		{

			if (!mpDoubleStack->isEmpty() && mPostfixSolution[index] != ' ')
			{

				cout << "Operator " << mPostfixSolution[index] << " found." << endl;
				//pop two numbers from stack
				double operand2 = mpDoubleStack->top()->getData();// get top element of stack
				mpDoubleStack->pop(); // pop top element of stack
				double operand1 = mpDoubleStack->top()->getData(); // get top element of stack
				mpDoubleStack->pop(); // pop top element of stack
				// calculate the result
				cout << operand1 << " " << mPostfixSolution[index] << " " << operand2 << endl;
				cout << calculate(mPostfixSolution[index], operand1, operand2) << " calulated and pushed on to the stack." << endl;
				mpDoubleStack->push(calculate(mPostfixSolution[index], operand1, operand2));
						
			}
		
		}
			index++;
		
	}
	cout << "End of postfix expression reached." << endl;

	cout << mPostfixSolution << " = " << mpDoubleStack->top()->getData() << endl;
	mpDoubleStack->pop(); // pop last element of stack making it empty

}