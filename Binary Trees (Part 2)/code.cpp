#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
int height(Node* root)
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

int diam1(Node* root) // O(n^2)
{
    if(root == NULL)
    {
        return 0;
    }
    int currDiam = height(root->left) + height(root->right) + 1;
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam , max(leftDiam , rightDiam));
}

pair<int,int> diam2(Node* root) // O(n)
{
    if(root == NULL)
    {
        return make_pair(0,0);
    }
    // (diameter , height)
    pair<int , int> leftInfo = diam2(root->left); // LD , LH
    pair<int , int> rightInfo = diam2(root->right); // RD , RH 

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam , max(leftInfo.first , rightInfo.first));

    int finalHt = max(leftInfo.second , rightInfo.second) + 1;

    return make_pair(finalDiam , finalHt);

}

bool isIdentical(Node* root1 , Node* root2)
{

    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if(root1 == NULL || root2 == NULL)
    {
        return false;
    }

    if(root1->data != root2->data)
    {
        return false;
    }
    return isIdentical(root1->left , root2->left)
    && isIdentical(root1->right , root2->right);
}

bool isSubtree(Node* root , Node* subRoot)
{
    if(root == NULL && subRoot == NULL)
    {
        return true;
    }
    else if(root == NULL || subRoot == NULL)
    {
        return false;
    }
    

    if(root->data == subRoot->data)
    {
        if(isIdentical(root , subRoot))
        {
            return true;
        }
    }
    int isLeftSubtree = isSubtree(root->left , subRoot);
    if(!isLeftSubtree)
    {
        return isSubtree(root->right , subRoot);
    }

    return true;
}

void topView(Node* root)
{
    queue<pair<Node* , int>>Q; // node and horizontal distance pair
    map<int , int> m; // HD and node data

    Q.push(make_pair(root , 0));
    while(!Q.empty())
    {
        pair<Node* , int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;


        if(m.count(currHD) == 0) 
        {
            m[currHD] = currNode->data;

        }

        if(currNode->left != NULL)
        {
            pair<Node* , int>left = make_pair(currNode->left , currHD -1);
            Q.push(left);
        }

        if(currNode->right != NULL)
        {
            pair<Node* , int>right = make_pair(currNode->right , currHD + 1);
            Q.push(right);
        }
    }

    for(auto it: m)
    {
        cout<<it.second<<" ";
    }

    cout<<endl;


}

int main()
{

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    // cout<<diam1(root)<<endl;
    // cout<<diam2(root).first<<endl;

    // Node* subRoot = new Node(2);
    // subRoot->left = new Node(4);
    // subRoot->right = new Node(5);


    // cout<<isSubtree(root , subRoot)<<endl;

    topView(root);

 
    return 0;
}