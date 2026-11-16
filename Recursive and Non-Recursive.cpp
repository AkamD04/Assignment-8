#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* insert(Node* root, int x) {
    if (root == NULL) {
        Node* temp = new Node();
        temp->data = x;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

bool searchRecursive(Node* root, int x) {
    if (root == NULL) return false;
    if (root->data == x) return true;

    if (x < root->data)
        return searchRecursive(root->left, x);

    return searchRecursive(root->right, x);
}

bool searchIterative(Node* root, int x) {
    while (root != NULL) {
        if (root->data == x) return true;

        if (x < root->data)
            root = root->left;
        else
            root = root->right;
    }

    return false;
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    int x;
    cin >> x;

    cout << "Recursive: ";
    cout << (searchRecursive(root, x) ? "Found" : "Not Found");

    cout << "\nNon-Recursive: ";
    cout << (searchIterative(root, x) ? "Found" : "Not Found");

    return 0;
}