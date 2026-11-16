#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* predecessor(Node* root, int x) {
    Node* ans = NULL;

    while (root != NULL) {
        if (x > root->data) {
            ans = root;
            root = root->right;
        }
        else
            root = root->left;
    }

    return ans;
}

int main() {
    Node* root = new Node{50, NULL, NULL};
    root->left = new Node{30, NULL, NULL};
    root->right = new Node{70, NULL, NULL};

    int x;
    cin >> x;

    Node* p = predecessor(root, x);

    if (p != NULL)
        cout << p->data;
    else
        cout << "No Predecessor";

    return 0;
}