// TC = O(n)
// SC = O(n)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void stockSpanProblem(vector<int> &stock, vector<int> &span) {
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for (int i = 1; i < stock.size(); i++) {
        int currPrice = stock[i];

        while (!s.empty() && currPrice >= stock[s.top()]) {
            s.pop();
        }

        if (s.empty()) {
            span[i] = i + 1;
        } else {
            int prevHigh = s.top();
            span[i] = i - prevHigh;
        }

        s.push(i); // IMPORTANT LINE
    }

    for (int i = 0; i < span.size(); i++) {
        cout << span[i] << " ";
    }
    cout << endl;
}

int main() {
     vector<int> stock;
    stock.push_back(100);
    stock.push_back(80);
    stock.push_back(60);
    stock.push_back(70);
    stock.push_back(60);
    stock.push_back(85);
    stock.push_back(100);
    stock.push_back(120);

    vector<int> span(stock.size(), 0);

    stockSpanProblem(stock, span);
    return 0;
}