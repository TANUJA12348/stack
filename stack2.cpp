#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string binary;
    stack<int> st;
    int decimal = 0, base = 1;

    cout << "Enter a binary number: ";
    cin >> binary;

    
    for (char ch : binary) {
        st.push(ch - '0');
    }

   
    while (!st.empty()) {
        int bit = st.top();
        st.pop();

        decimal += bit * base;
        base *= 2;
    }

    cout << "Decimal number = " << decimal << endl;

    return 0;
}