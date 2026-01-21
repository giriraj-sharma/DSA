// INSERT????
// list in STL
// push_front(val) , push_back(val) , pop_front() , pop_back() 
// size()
// front() -> head
// back() -> tail
// ll.begin() -> iterator of head
// ll.end() -> iterator of tail->next
#include<iostream>
#include<list>
using namespace std;

void printlist(list<int>ll)
{
    list<int>::iterator itr;
    for(itr = ll.begin() ; itr != ll.end() ; itr++)
    {
        cout<<(*itr)<<" -> ";
    }
    cout<<"NULL"<<endl;
}
int main()
{
    list<int>ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);

    printlist(ll);
    
    return 0;
}