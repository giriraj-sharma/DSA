#include <iostream>
using namespace std;

// Structure of Binary Tree Node
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
// Function to calculate Diameter and Height together
// Returns a pair:
// first  -> Diameter of tree
// second -> Height of tree
//
// Time Complexity: O(n)
// Reason: Each node is visited only once
// --------------------------------------------------
pair<int,int> diam2(Node* root) {
    
    // Base case: empty tree
    // Diameter = 0, Height = 0
    if (root == NULL) {
        return make_pair(0, 0);
    }

    // Recursively get diameter and height of left subtree
    // leftInfo.first  -> Left Diameter
    // leftInfo.second -> Left Height
    pair<int,int> leftInfo = diam2(root->left);

    // Recursively get diameter and height of right subtree
    pair<int,int> rightInfo = diam2(root->right);

    // Diameter passing through current node
    int currDiam = leftInfo.second + rightInfo.second + 1;

    // Final diameter is maximum of:
    // 1. Diameter through current node
    // 2. Left subtree diameter
    // 3. Right subtree diameter
    int finalDiam = max(currDiam,
                        max(leftInfo.first, rightInfo.first));

    // Height of current node
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    // Return both diameter and height
    return make_pair(finalDiam, finalHt);
}

int main() {
    /*
            Binary Tree:
                    1
                   / \
                  2   3
                 / \
                4   5

        Longest paths:
        4 → 2 → 1 → 3
        5 → 2 → 1 → 3

        Diameter = 4 nodes
        Height   = 3 nodes
    */

    // Creating the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Call optimized diameter function
    pair<int,int> ans = diam2(root);

    cout << "Diameter (in nodes): " << ans.first << endl;
    cout << "Height: " << ans.second << endl;

    return 0;
}