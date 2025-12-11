#include <iostream>
using namespace std;

class Stack {
    int arr[100];   // fixed size array
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    void push(int val) {
        topIndex++;
        arr[topIndex] = val;
    }

    void pop() {
        topIndex--;
    }

    int top() {
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

int main() {
    Stack s;

    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}