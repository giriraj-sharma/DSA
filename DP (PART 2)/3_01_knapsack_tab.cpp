#include<iostream>
#include<vector>
using namespace std;
// Tabulation -> smallest to largest
// storage  -> dp[n+1][W+1]
// meaning -> (i,j) -> i items and j capacity ka maxProfit
// base case in recursion -> initialisation in tabulation

int knapsackTab(vector<int> &val, vector<int> &wt , int W , int n) // TC/SC -> O(n * W) in every case
{
    vector<vector<int>> dp(n+1 , vector<int> (W+1 , 0));

    for(int i = 1 ; i<=n ; i++)
    {
        for(int j = 1 ; j<=W ; j++)
        {
            int itemWt = wt[i-1]; // here i are items
            int itemVal = val[i-1];


            if(itemWt<=j) // include
            {
                dp[i][j] = max(itemVal + dp[i-1][j-itemWt] , dp[i-1][j]);
            }
            else // exclude
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i = 0 ; i<=n ; i++)
    {
        for(int j = 0 ; j<=W ; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][W];
}
int main()
{
    vector<int>val = {15 , 14 , 10 , 45 , 30};
    vector<int>wt = {2 , 5 , 1 , 3 , 4};
    int W = 7;
    int n = 5;

    cout<<knapsackTab(val , wt , W , n)<<endl;



    return 0;
}