#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
static int idx = -1;
// TC -> O(N) , N is size of preorder vector
Node* buildTree(vector<int> nodes) 
{
    idx++;

    if(nodes[idx] == -1)
    {
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]); 
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;

}

// pre-order traversal
void preOrder(Node* root) // O(N)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}

// in-order traversal
void inOrder(Node* root) // O(N)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

// post-order traversal
void postOrder(Node* root) //O(n)
{
    if(root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

// level-order traversal continous printing
// TC -> O(n) , SC -> O(n) extra queue
// void levelOrder(Node* root) 
// {
//     if(root == NULL)
//     {
//         return;
//     }
//     queue<Node*> Q;
//     Q.push(root);

//     while(!Q.empty())
//     {
//         Node* curr = Q.front();
//         Q.pop();

//         cout<<curr->data<<" ";

//         if(curr->left != NULL)
//         {
//             Q.push(curr->left);
//         }
//         if(curr->right != NULL)
//         {
//             Q.push(curr->right);
//         }
//     }
//     cout<<endl;
// }

// level-order with next line after each level
void levelOrder(Node* root) 
{
    if(root == NULL)
    {
        return;
    }
    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty())
    {
        Node* curr = Q.front();
        Q.pop();

        if(curr == NULL)
        {
            cout<<endl;
            if(Q.empty())
            {
                break;
            }
            Q.push(NULL);
        }
        else
        {
            cout<<curr->data<<" ";

            if(curr->left != NULL)
            {
                Q.push(curr->left);
            }
            if(curr->right != NULL)
            {
                Q.push(curr->right);
            }

        }
        
    }
    
}
// height of tree
int height(Node* root) // O(n)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    
    int currHt = max(leftHt , rightHt) + 1;
    return currHt;
}

// count nodes in tree
int count(Node* root) // O(n)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftCnt = count(root->left);
    int rightCnt = count(root->right);

    return leftCnt + rightCnt + 1;
}

// sum of nodes

int sum(Node* root) // O(n)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    return leftSum + rightSum + root->data;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    // cout<<"preOrder: ";
    // preOrder(root);
    // cout<<endl;

    // cout<<"inOrder: ";
    // inOrder(root);
    // cout<<endl;

    // cout<<"postOrder: ";
    // postOrder(root);
    // cout<<endl;

    // cout<<"levelOrder: "<<endl;
    // levelOrder(root);
    // cout<<endl;


    // cout<<"Height: "<<height(root);

    // cout<<"Count: "<<count(root)<<endl;

    // Node* root2 = new Node(5);
    // root2->left = new Node(3);
    // root2->right = new Node(4);

    // cout<<"Count: "<<count(root2)<<endl;

    cout<<"Sum of nodes: "<<sum(root);
 
    return 0;
}