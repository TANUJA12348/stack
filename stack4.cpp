#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int decimal, rem;
    stack<char> s;

    cout << "Enter a decimal number: ";
    cin >> decimal;

    if (decimal == 0)
    {
        cout << "Hexadecimal=0";
        return 0;
    }

    while (decimal > 0)
    {
        rem = decimal %16;

        if (rem < 10)
            s.push(rem + '0');   
        else
            s.push(rem - 10 + 'A'); 
                      
        decimal = decimal / 16;
    }

    cout << "Hexadecimal = ";

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}