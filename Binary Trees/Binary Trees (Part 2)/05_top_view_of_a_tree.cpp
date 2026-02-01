#include <iostream>
#include <queue>
#include <map>
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
// Function to print Top View of Binary Tree
// Top View = first node visible at each horizontal distance
//
// Approach:
// - Level Order Traversal (BFS)
// - Track Horizontal Distance (HD)
// - For each HD, store first node encountered
// --------------------------------------------------
void topView(Node* root) {

    // Edge case
    if (root == NULL)
        return;

    // Queue stores pair of (node, horizontal distance)
    queue<pair<Node*, int>> Q;

    // Map stores HD -> node data
    // Map keeps keys sorted automatically (left to right)
    map<int, int> m;

    // Start with root at HD = 0
    Q.push(make_pair(root, 0));

    // BFS traversal
    while (!Q.empty()) {
        pair<Node*, int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        // Store only first node at each horizontal distance
        if (m.count(currHD) == 0) {
            m[currHD] = currNode->data;
        }

        // Left child -> HD - 1
        if (currNode->left != NULL) {
            Q.push(make_pair(currNode->left, currHD - 1));
        }

        // Right child -> HD + 1
        if (currNode->right != NULL) {
            Q.push(make_pair(currNode->right, currHD + 1));
        }
    }

    // Print top view from leftmost HD to rightmost HD
    for (auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    /*
            Binary Tree:
                    1
                   / \
                  2   3
                   \
                    4
                     \
                      5
                       \
                        6

        Top View Output:
        2 1 3 6
    */

    // Constructing the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    // Print top view
    topView(root);

    return 0;
}