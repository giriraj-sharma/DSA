#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    public:
    Node* head;
    Node* tail;

    Queue(){
        head = tail = NULL;
    }

    void push(int data)
    {
        Node* newNode = new Node(data);

        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
        tail->next = newNode;
        tail = newNode;
        }

    }

    void pop()
    {
        if(empty()){
            cout<<"Queue is empty "<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
    }

    int front()
    {
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return head->data;

    }

    bool empty()
    {
        return head == NULL;
    }

};
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}
