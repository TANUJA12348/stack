#include <iostream>
#include <stack>
using namespace std;


int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

int main()
{
    string infix, postfix = "";
    stack<char> st;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        
        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9'))
        {
            postfix += ch;
        }

        
        else if (ch == '(')
        {
            st.push(ch);
        }

        
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop(); 
        }

        
        else
        {
            while (!st.empty() && precedence(st.top()) >= precedence(ch))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}