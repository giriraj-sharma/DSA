#include <iostream>
using namespace std;

class Stack {
    int* arr;        // dynamic array
    int topIndex;    
    int capacity;    

public:
    Stack(int size) {
        capacity = size;
        arr = new int[size];   // dynamic memory allocation
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
    Stack s(5);   // dynamic array of size 5

    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}