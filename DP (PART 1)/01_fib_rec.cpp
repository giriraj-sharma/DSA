// Fibonacci -> every number is sum of previous 2 numbers
// 0 1 1 2 3 5 8 13 21....
// fib(n) = fin(n-1) + fib(n-2)

// first term is fib(0) 
// so fib(5) = 5

#include<iostream>
using namespace std;

// recursive function 
// TC -> O(2^N) Exponential
// Because each call makes two more recursive calls. The number of calls roughly doubles at each level.


int fib(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int main()
{
    int n;
    cin>>n;

    cout<<fib(n)<<endl;
    return 0;
}


// recursion tree
// fib(4)
// ├── fib(3)
// │   ├── fib(2)
// │   │   ├── fib(1)   → 1
// │   │   └── fib(0)   → 0
// │   └── fib(1)       → 1
// └── fib(2)
//     ├── fib(1)       → 1
//     └── fib(0)       → 0


// there is problem in this that we are calculating fib(2) again, although we have calculated it before 
// here comes the concept of dynamic programming 
// in dp we use an addition data structure which store the calculated results and when required it returns the results, due to which we dont have to calculate that again