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
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> nodes)
{
    idx++;
    if(nodes[idx]==-1)
    {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

// pre order traversal

void preOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
// inorder traversal
void inOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

// post order traversal

void postOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

// Level Order Traversal

void levelOrder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    queue<Node*>Q;
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
// height of a tree
int height(Node* root){
    if(root == NULL)
    {
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    return max(leftHt , rightHt) + 1;
}

// count of nodes of tree
int count(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftCnt = count(root->left);
    int rightCnt = count(root->right);

    return leftCnt + rightCnt + 1;
}

// Sum of node of tree

int sum(Node* root)
{
    if(root==NULL)
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

    cout<<"preorder: "; preOrder(root);cout<<endl;
    cout<<"ineorder: "; inOrder(root); cout<<endl;
    cout<<"postorder: "; postOrder(root); cout<<endl;
    cout<<"level order: "; 
    cout<<endl;
    levelOrder(root); cout<<endl;

    cout<<"Height: "<<height(root)<<endl;
    cout<<"Count: "<<count(root)<<endl;
    cout<<"Sum: "<<sum(root)<<endl;

    return 0;
}