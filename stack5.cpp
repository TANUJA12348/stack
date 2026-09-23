#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    string exp;
    stack<char> s;

    cout << "Enter an arithmetic expression: ";
    cin >> exp;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty())
            {
                cout << "Expression is Invalid";
                return 0;
            }

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                cout << "Expression is Invalid";
                return 0;
            }
        }
    }

    if (s.empty())
        cout << "Expression is Valid";
    else
        cout << "Expression is Invalid";

    return 0;
}