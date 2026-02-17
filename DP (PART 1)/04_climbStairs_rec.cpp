// Count ways to reach the nth stairs, A person can climb 1 or 2 stairs at a time

// recursion

#include <iostream>
using namespace std;
    int climbStairs(int n) // TC -> O(2^n) ; SC -> O(n)
    {
        if(n==0 || n==1)
        {
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
int main() {
    int n;
    cin>>n;
    cout<<climbStairs(n)<<endl;
    return 0;
}