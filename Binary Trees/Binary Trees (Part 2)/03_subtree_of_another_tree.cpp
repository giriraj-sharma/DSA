#include <iostream>
using namespace std;

// Structure of a Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// --------------------------------------------------
// Function to check if two binary trees are identical
// Trees are identical if:
// 1. Both are NULL
// 2. Root data is same
// 3. Left subtrees are identical
// 4. Right subtrees are identical
// --------------------------------------------------
bool isIdentical(Node* root1, Node* root2) {

    // Both trees empty
    if (root1 == NULL && root2 == NULL)
        return true;

    // One empty, one not
    if (root1 == NULL || root2 == NULL)
        return false;

    // Data mismatch
    if (root1->data != root2->data)
        return false;

    // Check left and right subtrees
    return isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

// --------------------------------------------------
// Function to check if subRoot is a subtree of root
// Idea:
// - Traverse root tree
// - At each node, check if subtree starting there
//   is identical to subRoot
// --------------------------------------------------
bool isSubtree(Node* root, Node* subRoot) {

    // If main tree ends, subtree not found
    if (root == NULL)
        return false;

    // If trees match from this node
    if (isIdentical(root, subRoot))
        return true;

    // Otherwise, check left and right subtrees
    return isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}

int main() {
    /*
        Tree 1:
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

    /*
        Tree 2:
                2
               / \
              4   5
    */
    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    // Check subtree
    if (isSubtree(root, subRoot))
        cout << "Subtree exists" << endl;
    else
        cout << "Subtree does not exist" << endl;

    return 0;
}