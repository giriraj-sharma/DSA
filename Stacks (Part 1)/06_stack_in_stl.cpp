#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<string> s;
    s.push("yash");
    s.push("parth");
    s.push("ayush");

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}