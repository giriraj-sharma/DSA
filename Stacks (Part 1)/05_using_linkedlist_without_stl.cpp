#include <iostream>
using namespace std;

// Node structure
template <class T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) {
        data = val;
        next = NULL;
    }
};

// Stack using Linked List (No STL)
template <class T>
class Stack {
    Node<T>* topNode;   // ✅ FIXED HERE

public:
    Stack() {
        topNode = NULL;
    }

    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (topNode == NULL) return;

        Node<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    T top() {
        if (topNode == NULL) return T();
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == NULL;
    }
};

int main() {
    Stack<string> s;
    s.push("yash");
    s.push("parth");
    s.push("ayush");

    while (!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}