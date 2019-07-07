#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool Is_Uniform(string expression)  //check if the sting in uniform !
{
	stack<char> stack;  // take a empty stack of characters
	bool is_comment = false;  // to check the comment
	for (int i = 0; i < expression.length(); i++)
	{
	    if(is_comment == true)
        {
            if(expression[i] == '*')
            {
                if(i + 1 < expression.length())
                {
                    if(expression[i + 1] == '/')
                    {
                        is_comment = false;
                        i = i + 1;
                        continue;
                    }
                }
            }
            else
            {
                continue;
            }
        }
		// push the current char if it is --> ( { [ * + - or /*
		if (expression[i] == '(' ||  expression[i] == '{' || expression[i] == '['
                                 ||  expression[i] == '*' || expression[i]=='+' || expression[i]=='-')
        {
			stack.push(expression[i]);
        }
        if(expression[i] == '/')
        {
            if(i + 1 < expression.length())
            {
                if(expression[i + 1] == '*')
                {
                    is_comment = true;
                    i = i + 1;
                    continue;
                }
            }
        }
        // pop the current char if it is --> ) } ] * + - or */
		if ( expression[i] == ')' ||  expression[i] == '}' || expression[i] == ']'
                            ||  expression[i] == '*' || expression[i]=='+' || expression[i]=='-')
		{
        // if stack is empty, it will have  } ] * + - or */  more than  ( { [ * + - or /*  , so expression cannot be uniform
			if(stack.empty()) {
				return false;
			}
			char top = stack.top();
			stack.pop();
			// if the popped character if not an opening brace or does not pair with current character of the expression
        if ((top == '(' && expression[i] != ')') ||
            (top == '{' && expression[i] != '}') ||
            (top == '[' && expression[i] != ']')) return false;

      //  if  (top == expression[i] == '*'  expression[i+1]=='/'))  return false;

		}
	}
	if(is_comment==true) return 0;
	// expression is uniform only if stack is empty at this point
	return stack.empty();
}

int main()
{
	string expression ;
	cout<<endl<<" Write the Expression here to check it : "<<endl;
	cin>> expression ;
	if (Is_Uniform(expression))
		cout <<endl<< " The Expression is VALID "<<endl;
	else
		cout <<endl<< " The Expression is INVALID** "<<endl;
	return 0;
}
