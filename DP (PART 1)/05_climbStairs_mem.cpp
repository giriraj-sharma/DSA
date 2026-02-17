#include <iostream>
#include<vector>
using namespace std;

// Memoization (top-down)
int climbStairs(int n , vector<int>& store) // TC->O(n) ; SC->O(n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    if(store[n]!=-1)
    {
        return store[n];
    }

    return store[n] = climbStairs(n-1 , store) + climbStairs(n-2 , store);
}
int main() {
    
    int n;
    cin>>n;
    vector<int> store(n+1 , -1);

    cout<<climbStairs(n , store)<<endl;
    return 0;
}