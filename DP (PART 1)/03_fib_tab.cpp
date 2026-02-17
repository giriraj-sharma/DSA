#include<iostream>
#include<vector>
using namespace std;

// Tabulation = iterative DP (Bottom-Up approach)
// Solve from smallest subproblem to largest problem

// steps to solve using tabulation:
// 1. Define any data strucutre where we can store and assign some meaning to that
// 2. initialize with smaller solution
// 3. solve from small -> large

int fib(int n) // TC -> O(n) ; SC -> O(n)
{
    if(n<=1) return n;
    vector<int> dp(n+1 , 0);
    dp[0] = 0;
    dp[1] = 1;

    // dp[i] => store ith fib 
    for(int i = 2 ; i<=n ; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;

    cout<<fib(n)<<endl;
    return 0;
}