#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
    map<int , string>mp;

    mp[101] = "rahul";
    mp[110] = "neha";
    mp[131] = "rahul";

    mp[131] = "Giriraj";

    cout<<mp[131]<<endl;

    cout<<mp.count(131)<<endl;
    cout<<mp.count(120)<<endl;

    for(auto it: mp)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}
