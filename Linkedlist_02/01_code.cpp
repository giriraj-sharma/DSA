#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    public:
    Node* head;
    Node* tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }
    void push_front(int val){ 
        Node* newNode = new Node(val);
        if(tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = tail = newNode;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void pop_front()
    {
        if(head == NULL)
        {
            cout<<"List is empty "<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    // DETECT A CYCLE/LOOP IN LINKEDLIST
    // floyd cycle finding algorithm

    bool isCycle(Node* temp)
    {
        Node* fast = head;
        Node* slow = head;

        while(fast!=NULL && fast->next != NULL)
        {
            // pahle hum updation karenge uske baad check karenge kyuki starting me toh dono same hi postion pe hai toh true return kar dega..
            slow = slow->next;
            fast  = fast->next->next;
            if(slow == fast)
            {
                cout<<"cycle exist"<<endl;
                return true;
            }
            
        }
        cout<<"cycle doesn't exist"<<endl;
        return false;
    }

    // REMOVING CYCLE IN LINKEDLIST

    void removeCycle(Node* head)
    {
        // detect cycle

        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            {
                cout<<"Cycle exist"<<endl;
                isCycle = true;
                break;
            }
        }

        if(!isCycle)
        {
            cout<<"Cycle doesn't exist"<<endl;
            return;
        }

        slow = head;
        if(slow == fast) // speacial case -> tail head se connected hai
        {
            while(fast->next != slow)
            {
                fast = fast->next; // isse fast last node (tail) pe aa gya
            }
            fast->next = NULL; // removing cycle specail case
        }
        else // normal kaam
        {
            Node* prev = fast;
            while(slow != fast)
            {
                slow = slow->next;
                prev = fast;
                fast = fast->next;
            }

            prev->next = NULL; // cycle removed
        }
    }

    // MERGE SORT ON LINKEDLIST

Node* splitAtMid(Node* head)
{   
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL)
    {
        prev->next = NULL; // split at middle
    }

    return slow; // rightHead
}

Node* merge(Node* left, Node* right)
{
    List ans;
    Node* i = left;
    Node* j = right;

    while(i != NULL && j != NULL)
    {
        if(i->data <= j->data)
        {
            ans.push_back(i->data);
            i = i->next;
        }
        else
        {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while(i != NULL)
    {
        ans.push_back(i->data);
        i = i->next;
    }

    while(j != NULL)
    {
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;
}

Node* mergeSort(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    Node* rightHead = splitAtMid(head);

    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left, right);
    }

    Node* reverse(Node*head)
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev; //prev is head of reversed ll
    }
    // zig ziag linkedlist
    Node* zigZagll(Node* head)
    {
        Node* rightHead = splitAtMid(head);
        Node* rightHeadRev = reverse(rightHead);

        // alternate merging -> 1st head head , 2nd head rightHeadRev

        Node* left = head;
        Node* right = rightHeadRev;
        Node* tail = right;

        while(left != NULL && right != NULL){
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next = right;
        right->next = nextLeft;
        tail = right;

        left = nextLeft;
        right = nextRight;
        }

        if(right != NULL)
        {
            tail->next = right;

        }
        return head;
    }

    void printList()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};

int main()
{
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();
    cout<<endl;

    // ll.head = ll.mergeSort(ll.head);
    // ll.printList();
    

    // ll.tail->next = ll.head; // to make a cycle
    // cout<<ll.isCycle(ll.head)<<endl;
    // ll.removeCycle(ll.head);
    ll.zigZagll(ll.head);
    ll.printList();
    cout<<endl;


    return 0;
}