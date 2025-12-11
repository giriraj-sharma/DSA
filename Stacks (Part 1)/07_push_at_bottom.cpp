// stl k jitne bhi container hote hai (vector , list , stack ) wo by default pass by value hote h , hume hi & use karna padta hai reference k liye

// tc = O(n)
// sc = O(n)
#include<iostream>
#include<stack>
using namespace std;

void pushAtBottom(stack<int> &s , int val) 
{
    if(s.empty())
    {
        s.push(val); // empty stack k push at top hi push at bottom hota hai 
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtBottom(s , val);

    s.push(temp);
}
int main()
{
    stack<int>s;
    s.push(3);
    s.push(2);
    s.push(1);

    pushAtBottom(s , 4);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}