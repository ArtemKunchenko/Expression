//There is a string of symbols, a sign of the end, which is «;».In a string can be curly, round, square brackets.Brackets can be openingand closing.It is necessary to check correctness of bracket placement.The bracket rules are as follows : 1. Each opening bracket shall have the same closing bracket on the right. 2. The opening and closing pairs of different types of brackets shall be properly arranged in relation to each other.Example of a valid string : ({ x - y - z }*[x + 2y] - (z + 4x));   Example of an incorrect string : ([x - y - z}*[x + 2y) - {z + 4x)].If all the rules are met, print a message informing you that the string is correct, otherwise show the string before the first error occurred.
#include<iostream>
#include "Stack.h"
#include "Stack.cpp"
using namespace std;
bool conditionPushStack(char element);
bool conditionPopStack(char element1, char element2);
bool conditionMistake(char element1, char element2);
void checkExpression(char* expression, Stack<char> s );
void prinMistake(char* expression, char element);
int main()
{
	const int size = 100;
	char expression1[size] = "({x-y-z}*[x+2y]-(z+4x));";
	char expression2[size] = "([x-y-z}*[x+2y)-{z+4x)];";
	Stack<char> s(100);
	checkExpression(expression1, s);
	checkExpression(expression2, s);
	system("pause");
	return 0;
}

bool conditionPushStack(char element)
{
	if (element == '(' || element == '{' || element == '[') return true;
	else return false;
}

bool conditionPopStack(char element1, char element2)
{
	if (element1 == '(' && element2 == ')')
		return true;
	if (element1 == '{' && element2 == '}')
		return true;
	if (element1 == '[' && element2 == ']')
		return true;
	return false;
}

bool conditionMistake(char element1, char element2)
{
	if (element1 == '(' && (element2 == ']' || element2 == '}')) return true;
	if (element1 == '[' && (element2 == ')' || element2 == '}')) return true;
	if (element1 == '{' && (element2 == ']' || element2 == ')')) return true;
	return false;
}

void checkExpression(char* expression, Stack<char> s)
{
	int counter = 0;
	for (int i = 0; expression[i] !=';'&& expression[i] != '\0'; i++)
	{
		if (conditionPushStack(expression[i]))
		{
			s.push(expression[i]);
			counter++;
		}
		else
		{
			if (conditionPopStack(s.top(), expression[i]))
			{
				s.pop();
				counter--;
			}
			else if (conditionMistake(s.top(), expression[i]))
			{
				prinMistake(expression, expression[i]);
				break;
			}

		}
		
	}
	if (counter == 0) cout << "Expression " << expression << " is correct\n";
	
}

void prinMistake(char* expression, char element)
{
	cout << "Expression " << expression << " has mistakes after this part ";
	for (int i = 0; expression[i] != element; i++)
	{
		cout << expression[i];
	}
	cout << endl;
}
