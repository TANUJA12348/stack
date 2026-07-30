# include <iostream>
# include <vector>
using namespace std;
class stack{
    vector <int> item;
    int top;
    public:
    stack( int s) {
        item.resize(s);
        top = -1;
    }
    void push( int x) {
        if (top == item.size() -1) {
            cout << "Stack overflow " << endl;
            
        }
        else {
            top++;
            item[top]=x;
        }
    }
      int pop( ) {
        if ( top==-1){
            cout<<" stack underflow"<<endl;
            return -1;
        }
        else {
            int x;
            x=item[top];
            top--;
            return x;
        }
      }
      int stacktop( ) {
        int x;
        x=item[top];
        return x;
      }

      bool isempty ( ) {
        if( top==-1){
            return true;
        }
        else {
            return false;
        }
      }
};
int main ( ) {
    stack stk(10);
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.push(6);
    stk.push(7);
    stk.push(8);
    stk.push(9);
    
    stk.push(10);
    cout<<stk.stacktop()<<endl;
    stk.push(11);
    stk.pop();
    cout<<stk.stacktop()<<endl;
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();
    cout<<stk.stacktop()<<endl;
    return 0;
}