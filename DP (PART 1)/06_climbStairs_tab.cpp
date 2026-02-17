#include <iostream>
using namespace std;
// tabulation(bottom up)
int climbStairs(int n) // TC-> O(n) ; SC -> O(n)
{
    vector<int> store(n+1);

    store[0] = 1;
    store[1] = 1;

    for(int i = 2 ; i<=n ; i++)
    {
        store[i] = store[i-1] + store[i-2];
    }
    return store[n];
}
int main() {
    int n;
    cin>>n;

    cout<<climbStairs(n)<<endl;
    return 0;
}