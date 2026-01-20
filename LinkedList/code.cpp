#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

    ~Node(){
        cout<<"Node Desctructor for data = "<< data <<endl;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

class List{
    public:
    Node* head;
    Node* tail;

    List(){
        head = NULL;
        tail = NULL;
    }

    ~List() // destructor to free memory
    {
        cout<<"Destructor of list\n";
        if(head != NULL)
        {
            delete head;
            head = NULL;
        }

    }
    // PUSH FRONT
    void push_front(int val)
    {
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = tail = newNode;
        }
        else{   
            newNode->next = head;
            head = newNode;
        }

    }
    // PUSH BACK
    void push_back(int val)
    {
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    // POP FRONT

    void pop_front()
    {

        if(head == NULL)
        {
            cout<<"Linkelist is empty"<<endl;
            return ;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    
    }

    // POP BACK

    void pop_back()
    {
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        // If only one node is present
        if(head == tail)

        {
            delete head;
            head = tail = NULL;
            return;
        }


        Node* temp = head;
        while(temp->next != tail) // temp->next->next != NUll , because we want accss of one node before tail
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    // ITERATIVE SEARCH IN LINKEDLIST

    int searchItr(int key) // TC -> O(n)
    {
        Node* temp = head;
        int idx = 0;
        while(temp != NULL)
        {
            if(temp->data == key)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    // RECURSIVE SEARCH IN LINKEDLIST

    int searchRecHelper(Node* temp, int key, int idx)
    {
        if(temp == NULL) return -1;          // base case: end of list

        if(temp->data == key) return idx;    // key found

        return searchRecHelper(temp->next, key, idx + 1);
    }

    int searchRec(int key)
    {
        return searchRecHelper(head, key, 0);
    }

    // INSERT IN LINKEDLIST

    void insert(int val , int pos)
    {
        if(pos == 0)
        {
            push_front(val);
            return;
        }

        Node* newNode = new Node(val);

        Node* temp = head;

        for(int i = 0 ; i<pos - 1 ; i++)
        {
            if(temp == NULL)
            {
                delete newNode; 
                cout << "Invalid Position\n";
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if(newNode->next == NULL)
        {
        tail = newNode;
        }
    }

    // REVERSE A LINKED LIST
    void reverse()
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        tail = head;  // jo pehle head tha, wahi ab tail banega

        while(curr != NULL)
        {
            next = curr->next;   // next node store karo
            curr->next = prev;   // link reverse karo
            prev = curr;         // prev ko aage badhao
            curr = next;         // curr ko aage badhao
        }

        head = prev;  // last me prev hi naya head ban jaata hai
    }

    // SIZE OF LINKEDLIST
    int getSize()
    {
        int sz = 0;
        Node*temp = head;
        while(temp!=NULL)
        {
            temp = temp->next;
            sz++;
        }
        return sz;
    }

    // FIND AND REMOVE Nth NODE FROM END
    // Nth node from end ka front index hota hai: (size - n + 1)
    // Lekin delete karne ke liye hume us node ka prev chahiye,
    // jo front se hoga: (size - n)

    void removeNth(int n) // TC -> O(n) , SC -> O(1)
    {
        int size = getSize();
        Node* prev = head;
        for(int i = 1 ; i<(size-n) ; i++)
        {
            prev = prev->next;
        }
        Node* toDelete = prev->next;
        cout<<"Going to delete: "<<toDelete->data<<endl;
        prev->next = prev->next->next;
    }

    // PRINT LINKEDLIST
    void printList() // TC -> O(n)
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

};

int main()
{
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.printList();

    int n = 4;
    ll.removeNth(n);
    ll.printList();

    // cout<<ll.searchItr(4)<<endl;

    // ll.reverse();
    // ll.printList();



    return 0;
}