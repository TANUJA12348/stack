#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int decimal;
    stack<int> s;

    cout << "Enter a decimal number: ";
    cin >> decimal;

    if (decimal == 0)
    {
        cout << "Octal = 0";
        return 0;
    }

    while (decimal > 0)
    {
        s.push(decimal % 8);
        decimal = decimal / 8;
    }

    cout << "Octal = ";

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}