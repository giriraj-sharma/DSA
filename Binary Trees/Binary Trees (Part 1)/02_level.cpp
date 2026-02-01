#include <iostream>
#include <queue>
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
// Level Order Traversal (Continuous Printing)
// Output: 1 2 3 4 5 6
// Time Complexity: O(n)
// Space Complexity: O(n)
// --------------------------------------------------
void levelOrderContinuous(Node* root) {

    if (root == NULL)
        return;

    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty()) {
        Node* curr = Q.front();
        Q.pop();

        cout << curr->data << " ";

        if (curr->left != NULL)
            Q.push(curr->left);

        if (curr->right != NULL)
            Q.push(curr->right);
    }
    cout << endl;
}

// --------------------------------------------------
// Level Order Traversal (Each Level in New Line)
// Uses NULL marker to separate levels
// Time Complexity: O(n)
// Space Complexity: O(n)
// --------------------------------------------------
void levelOrder(Node* root) {

    if (root == NULL)
        return;

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);   // Marker for end of level

    while (!Q.empty()) {
        Node* curr = Q.front();
        Q.pop();

        // End of current level
        if (curr == NULL) {
            cout << endl;

            // If queue is empty, traversal is complete
            if (Q.empty())
                break;

            // Push marker for next level
            Q.push(NULL);
        }
        else {
            cout << curr->data << " ";

            if (curr->left != NULL)
                Q.push(curr->left);

            if (curr->right != NULL)
                Q.push(curr->right);
        }
    }
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
                 / \   \
                4   5   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Level Order (Continuous): ";
    levelOrderContinuous(root);

    cout << "Level Order (Line by Line):" << endl;
    levelOrder(root);

    return 0;
}