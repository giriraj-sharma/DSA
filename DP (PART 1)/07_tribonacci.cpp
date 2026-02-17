// Count ways to reach the nth stair. A person an climb 1, 2 or 3 stairs at a time

#include <iostream>
#include<vector>
using namespace std;

int triboRec(int n) // TC -> O(3^n)
{
    if(n<=0)
    {
        return 0;
    }
    if(n==1 || n==2)
    {
        return 1;
    }
    return triboRec(n-1) + triboRec(n-2) + triboRec(n-3);
}

int triboMem(int n , vector<int> & store) // TC -> O(n) ; SC -> O(n)
{
    if(n<=0)
    {
        return 0;
    }
    if(n==1 || n==2)
    {
        return 1;
    }
    if(store[n] != -1)
    {
        return store[n];
    }
    store[n] =  triboMem(n-1 , store) + triboMem(n-2 , store) + triboMem(n-3 , store);
    return store[n];
}

int triboTab(int n) // TC -> O(n) ; Sc -> O(n)
{
    if(n <= 0) return 0;
    if(n == 1 || n == 2) return 1;
    vector<int> tab(n+1);
    tab[0] = 0;
    tab[1] = 1;
    tab[2] = 1;

    for(int i = 3 ; i<=n ; i++)
    {
        tab[i] = tab[i-1] + tab[i-2] + tab[i-3];
    }

    return tab[n];
}


int main() {
    
    int n;
    cin>>n;
    // vector<int> store(n+1 , -1);
    // cout<<triboRec(n)<<endl;
    // cout<<triboMem(n , store)<<endl;;

    cout<<triboTab(n)<<endl;


    return 0;
}