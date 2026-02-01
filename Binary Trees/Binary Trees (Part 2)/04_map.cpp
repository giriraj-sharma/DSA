#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    // Create a map with key = int, value = string
    // Map stores keys in sorted order (by default)
    map<int, string> mp;

    // Inserting key-value pairs
    mp[101] = "rahul";
    mp[110] = "neha";
    mp[131] = "rahul";

    // Updating value of an existing key
    // Key 131 already exists, so value gets overwritten
    mp[131] = "Giriraj";

    // Accessing value using key
    cout << "Value at key 131: " << mp[131] << endl;

    // count() returns:
    // 1 -> if key exists
    // 0 -> if key does not exist
    cout << "Does key 131 exist? " << mp.count(131) << endl;
    cout << "Does key 120 exist? " << mp.count(120) << endl;

    // Traversing the map using range-based for loop
    cout << "\nMap elements (sorted by key):" << endl;
    for (auto it : mp) {
        cout << it.first << " -> " << it.second << endl;
    }

    return 0;
}