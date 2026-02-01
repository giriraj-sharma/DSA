#include <iostream>
using namespace std;

// --------------------------------------------------
// Binary Tree Node Structure
// --------------------------------------------------
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// --------------------------------------------------
// Height of Binary Tree
// Height = maximum number of nodes from root to leaf
// Time Complexity: O(n)
// --------------------------------------------------
int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    return max(leftHt, rightHt) + 1;
}

// --------------------------------------------------
// Count number of nodes in Binary Tree
// Time Complexity: O(n)
// --------------------------------------------------
int countNodes(Node* root) {
    if (root == NULL)
        return 0;

    int leftCnt = countNodes(root->left);
    int rightCnt = countNodes(root->right);

    return leftCnt + rightCnt + 1;
}

// --------------------------------------------------
// Sum of all node values in Binary Tree
// Time Complexity: O(n)
// --------------------------------------------------
int sum(Node* root) {
    if (root == NULL)
        return 0;

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    return leftSum + rightSum + root->data;
}

// --------------------------------------------------
// Driver Code
// --------------------------------------------------
int main() {

    /*
            Binary Tree:
                    1
                   / \
                  2   3
                 / \
                4   5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Height of Tree: " << height(root) << endl;
    cout << "Total Nodes: " << countNodes(root) << endl;
    cout << "Sum of Nodes: " << sum(root) << endl;

    return 0;
}