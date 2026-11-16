#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* insert(Node* root, int x) {
    if (root == NULL)
        return new Node{x, NULL, NULL};

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

Node* deleteNode(Node* root, int x) {
    if (root == NULL) return root;

    if (x < root->data)
        root->left = deleteNode(root->left, x);

    else if (x > root->data)
        root->right = deleteNode(root->right, x);

    else {
        if (root->left == NULL)
            return root->right;

        if (root->right == NULL)
            return root->left;

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int maxDepth(Node* root) {
    if (root == NULL) return 0;

    return 1 + max(maxDepth(root->left),
                   maxDepth(root->right));
}

int minDepth(Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL)
        return 1 + minDepth(root->right);

    if (root->right == NULL)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left),
                   minDepth(root->right));
}

void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    root = deleteNode(root, 30);

    cout << "BST: ";
    inorder(root);

    cout << "\nMaximum Depth: " << maxDepth(root);
    cout << "\nMinimum Depth: " << minDepth(root);

    return 0;
}