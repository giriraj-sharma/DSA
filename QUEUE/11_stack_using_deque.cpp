#include<iostream>
#include<deque>
using namespace std;

class Stack{
    public:

    deque<int>deq;
    void push(int val)
    {
        deq.push_front(val);
    }
    void pop(){
        if(empty())
        {
            cout<<"Stack is empty"<<endl;
            return ;
        }
        deq.pop_front();

    }
    int top(){
        if(empty())
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return deq.front();
    }
    bool empty()
    {
        return deq.empty();
    }


};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}