#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

bool isMaxHeap(Node* root) {
    if (root == NULL)
        return true;

    bool left = isMaxHeap(root->left);
    bool right = isMaxHeap(root->right);

    if (!left || !right)
        return false;

    if (root->left != NULL && root->data < root->left->data)
        return false;
    if (root->right != NULL && root->data < root->right->data)
        return false;

    return true;
}

bool isMinHeap(Node* root) {
    if (root == NULL)
        return true;

    bool left = isMinHeap(root->left);
    bool right = isMinHeap(root->right);

    if (!left || !right)
        return false;

    if (root->left != NULL && root->data > root->left->data)
        return false;
    if (root->right != NULL && root->data > root->right->data)
        return false;

    return true;
}

int main() {
 
    Node* root = new Node();
    root->data = 10;
    root->left = new Node();
    root->right = new Node();
    root->left->data = 5;
    root->left->left = new Node();
    root->left->right = new Node();
    root->left->left->data = 1;
    root->left->right->data = 4;
    root->right->data = 6;
    root->right->left = new Node();
    root->right->left->data = 2;

    if (isMaxHeap(root))
        cout << "The binary tree is a max heap" << endl;
    else
        cout << "The binary tree is not a max heap" << endl;

    if (isMinHeap(root))
        cout << "The binary tree is a min heap" << endl;
    else
        cout << "The binary tree is not a min heap" << endl;

    return 0;
}
