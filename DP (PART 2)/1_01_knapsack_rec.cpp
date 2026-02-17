// val[] and wt[] -> represent value and weight for each item
// W -> maximum capacity of knapsack

// The task is to put the items into the knapsack such that the total value obtained is maximum without exceeding the capacity W.

// val[] = {15, 14, 10, 45, 30};
// wt[] =  {2 , 5 ,  1,  3,  4};
// W = 7;

// Item1 = (15 , 2)
// Item2 = (14 , 5)
// Item3 = (10 , 1)
// Item4 = (45 , 3)
// Item5 = (30 , 4)

#include<iostream>
#include<vector>
using namespace std;

// using recursion
// O(2^n) -> because there are 2 choices for each item
int knapsackrec(vector<int> &val, vector<int> &wt , int W , int n) { 

        if(n==0 || W==0)
        {
            return 0;
        }
        int itemWt =  wt[n-1];
        int itemVal = val[n-1];


        if(itemWt <= W)
        {
            // include
            int ans1 = knapsackrec(val , wt , W-itemWt , n-1) + itemVal;

            // exclude
            int ans2 = knapsackrec(val , wt , W , n-1);


            return max(ans1 , ans2);
        }
        else
        {
            //exclude
            return knapsackrec(val , wt , W , n-1);
        }
        
    }
int main()
{
    vector<int>val = {15 , 14 , 10 , 45 , 30};
    vector<int>wt = {2 , 5 , 1 , 3 , 4};
    int W = 7;
    int n = 5;

    cout<<knapsackrec(val , wt , W , n)<<endl;
    return 0;
}