#include<iostream>
#include<deque>
using namespace std;

class Queue{
    public:
    deque<int> deq;

    void push(int val)
    {
        deq.push_back(val);
    }
    void pop()
    {
        if(empty())
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        deq.pop_front();
    }
    int front()
    {
        if(empty())
        {
            cout<<"Queue is empty"<<endl;
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
    Queue q;
    for(int i = 1 ; i<=5 ; i++)
    {
        q.push(i);
    }

    for(int i = 1 ; i<=5 ; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}