#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* successor(Node* root, int x) {
    Node* ans = NULL;

    while (root != NULL) {
        if (x < root->data) {
            ans = root;
            root = root->left;
        }
        else
            root = root->right;
    }

    return ans;
}

int main() {
    Node* root = new Node{50, NULL, NULL};
    root->left = new Node{30, NULL, NULL};
    root->right = new Node{70, NULL, NULL};

    int x;
    cin >> x;

    Node* s = successor(root, x);

    if (s != NULL)
        cout << s->data;
    else
        cout << "No Successor";

    return 0;
}