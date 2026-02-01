#include <iostream>
#include <vector>
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

// Global index to track position in preorder vector
static int idx = -1;

// --------------------------------------------------
// Function to build Binary Tree from Preorder traversal
// -1 represents NULL node
// Time Complexity: O(N)
// --------------------------------------------------
Node* buildTree(vector<int> nodes) {

    idx++;

    // Base case: if current value is -1, return NULL
    if (nodes[idx] == -1) {
        return NULL;
    }

    // Create current node
    Node* currNode = new Node(nodes[idx]);

    // Recursively build left subtree
    currNode->left = buildTree(nodes);

    // Recursively build right subtree
    currNode->right = buildTree(nodes);

    return currNode;
}

// --------------------------------------------------
// Preorder Traversal (Root → Left → Right)
// Time Complexity: O(N)
// --------------------------------------------------
void preOrder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// --------------------------------------------------
// Inorder Traversal (Left → Root → Right)
// Time Complexity: O(N)
// --------------------------------------------------
void inOrder(Node* root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// --------------------------------------------------
// Postorder Traversal (Left → Right → Root)
// Time Complexity: O(N)
// --------------------------------------------------
void postOrder(Node* root) {
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {

    /*
        Preorder representation with -1 as NULL:
        [1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1]

        Constructed Binary Tree:
                    1
                   / \
                  2   3
                 / \   \
                4   5   6
    */

    vector<int> nodes = {
        1, 2, 4, -1, -1, 5, -1, -1,
        3, -1, 6, -1, -1
    };

    // Build tree
    Node* root = buildTree(nodes);

    // Traversals
    cout << "Preorder Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}