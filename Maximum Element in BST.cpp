#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

int maximum(Node* root) {
    if (root == NULL) return -1;

    while (root->right != NULL)
        root = root->right;

    return root->data;
}

int main() {
    Node* root = new Node{50, NULL, NULL};
    root->left = new Node{30, NULL, NULL};
    root->right = new Node{70, NULL, NULL};

    cout << "Maximum: " << maximum(root);

    return 0;
}