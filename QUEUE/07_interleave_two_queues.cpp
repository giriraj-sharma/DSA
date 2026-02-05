#include<iostream>
#include<queue>
using namespace std;

void interLeave(queue<int> &org)
{
    queue<int>q;
    int n = org.size();
    if(n%2!=0)
    {
        cout<<"Interleave not possible for odd numbers"<<endl;
        return;
    }

    int half = n/2;
    for(int i = 0 ; i<half ; i++)
    {
        q.push(org.front());
        org.pop();
    }

    while(!q.empty())
    {
        org.push(q.front());
        q.pop();

        org.push(org.front());
        org.pop();
    }
}

// void interLeave(queue<int> &org)
// {
//     int n = org.size();
//     queue<int> q;
//     int half = n / 2;
//     for (int i = 0; i < half; i++) {
//         q.push(org.front());
//         org.pop();
//     }
//     while (!q.empty()) {
//         org.push(q.front());
//         q.pop();

//         org.push(org.front());
//         org.pop();
//     }
// }

int main()
{

    queue<int>org;
    for(int i = 1 ; i<=10 ; i++)
    {
        org.push(i);
    }
    interLeave(org);

    for(int i = 1 ; i<=10 ; i++)
    {
        cout<<org.front()<<" ";
        org.pop();
    }
    cout<<endl;

    return 0;
}