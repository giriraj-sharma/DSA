#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Create Stack using Vector (Template)
template <class T>
class Stack {
    vector<T> vec;

public:
    void push(T val) {          // O(1)
        vec.push_back(val);
    }

    void pop() {                // O(1)
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        vec.pop_back();
    }

    T top() {                   // O(1)
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return T();         // Safe default return for any datatype
        }
        int lastIndex = vec.size() - 1;
        return vec[lastIndex];
    }

    bool isEmpty() {
        return vec.size() == 0;
    }
};

int main() {
    Stack<string> s;   // Stack of string type

    s.push("learn");
    s.push("stack");
    s.push("data structure");

    while (!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}