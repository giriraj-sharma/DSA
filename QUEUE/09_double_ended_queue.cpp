#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque<int> dq;

    // push_front
    // pop_front

    //push_back
    //pop_back

    //front
    //back

    dq.push_front(2);
    dq.push_front(1);

    dq.push_back(3);
    dq.push_back(4);

    while(!dq.empty())
    {
        cout<<dq.front();
        
    }
    return 0;
}