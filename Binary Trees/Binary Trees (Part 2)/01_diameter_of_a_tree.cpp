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
// Function to calculate height of a binary tree
// Height = maximum number of nodes from root to leaf
// --------------------------------------------------
int height(Node* root) {
    // Base case: empty tree
    if (root == NULL)
        return 0;

    // Height = max(left subtree height, right subtree height) + 1
    return max(height(root->left), height(root->right)) + 1;
}

// --------------------------------------------------
// Function to calculate Diameter of Binary Tree
// Diameter = maximum number of nodes on any path
// Time Complexity: O(n^2)
// Reason: height() is called for every node
// --------------------------------------------------
int diam1(Node* root) {
    // Base case
    if (root == NULL)
        return 0;

    // Diameter passing through current node
    int currDiam = height(root->left) + height(root->right) + 1;

    // Diameter in left subtree
    int leftDiam = diam1(root->left);

    // Diameter in right subtree
    int rightDiam = diam1(root->right);

    // Return maximum of all three
    return max(currDiam, max(leftDiam, rightDiam));
}

int main() {
    /*
            Binary Tree:
                    1
                   / \
                  2   3
                 / \
                4   5

        Diameter path examples:
        4 → 2 → 1 → 3
        5 → 2 → 1 → 3

        Diameter = 4 nodes
    */

    // Creating the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Print diameter
    cout << "Diameter (in nodes): " << diam1(root) << endl;

    return 0;
}