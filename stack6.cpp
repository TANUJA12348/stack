#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string postfix;
    stack<int> s;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

    
        if (ch >= '0' && ch <= '9')
        {
            s.push(ch - '0');
        }
        else
        {
            int op2 = s.top();
            s.pop();

            int op1 = s.top();
            s.pop();

            switch (ch)
            {
                case '+':
                    s.push(op1 + op2);
                    break;

                case '-':
                    s.push(op1 - op2);
                    break;

                case '*':
                    s.push(op1 * op2);
                    break;

                case '/':
                    s.push(op1 / op2);
                    break;
            }
        }
    }

    cout << "Result = " << s.top();

    return 0;
}