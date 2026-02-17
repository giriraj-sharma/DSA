#include <iostream>
#include <vector>
using namespace std;

// Memoization = recursion + storage (Top-Down DP)
// Solve big problem by breaking it into smaller subproblems
// TC -> O(n)
// Each fibonacci value from 0 to n is computed only once
// SC -> O(n)

int fib(int n , vector<int> & store)
{
    if(n == 0 || n==1)
    {
        return n;
    }

    if(store[n]!=-1) return store[n];

    return store[n] = fib(n-1 , store) + fib(n-2 , store);

}
int main() {
    int n;
    cin>>n;

    vector<int> store(n+1 , -1);

    cout<<fib(n , store);

    return 0;
}