#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

bool isBST(Node* root, int min, int max) {
    if (root == NULL)
        return true;

    if (root->data <= min || root->data >= max)
        return false;

    return isBST(root->left, min, root->data) &&
           isBST(root->right, root->data, max);
}

int main() {
    Node* root = new Node{50, NULL, NULL};

    root->left = new Node{30, NULL, NULL};
    root->right = new Node{70, NULL, NULL};

    if (isBST(root, INT_MIN, INT_MAX))
        cout << "It is a BST";
    else
        cout << "It is not a BST";

    return 0;
}