#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class BSTNode {
public:
    int value;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree {
private:
    BSTNode* root;
public:
    BinarySearchTree() {
        root = NULL;
    }

    void insert(int val) {
        if (root == NULL) {
            root = new BSTNode(val);
            return;
        }

        BSTNode* curr = root;
        while (true) {
            if (val < curr->value) {
                if (curr->left == NULL) {
                    curr->left = new BSTNode(val);
                    break;
                }
                else {
                    curr = curr->left;
                }
            }
            else {
                if (curr->right == NULL) {
                    curr->right = new BSTNode(val);
                    break;
                }
                else {
                    curr = curr->right;
                }
            }
        }
    }

    void traverseInorder(BSTNode* node) {
        if (node == NULL) {
            return;
        }
        traverseInorder(node->left);
        cout << node->value << " ";
        traverseInorder(node->right);
    }

    void printTree() {
        traverseInorder(root);
        cout << endl;
    }

    int getDepth(BSTNode* node) {
        if (node == NULL) {
            return 0;
        }

        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);

        return max(leftDepth, rightDepth) + 1;
    }

    int getDepth() {
        return getDepth(root);
    }

    bool search(int val) {
        BSTNode* curr = root;
        while (curr != NULL) {
            if (val == curr->value) {
                return true;
            }
            else if (val < curr->value) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
        return false;
    }
};

int main() {
    srand(time(NULL));
    BinarySearchTree bst;

    int numElements;
    cout << "Enter number of elements: ";
    cin >> numElements;

    for (int i = 0; i < numElements; i++) {
        bst.insert(rand() % 100);
    }

    cout << "Tree:" << endl;
    bst.printTree();

    cout << "Depth: " << bst.getDepth() << endl;

    int searchVal;
    cout << "Enter value to search: ";
    cin >> searchVal;

    if (bst.search(searchVal)) {
        cout << "Value found in tree" << endl;
    }
    else {
        cout << "Value not found in tree" << endl;
    }

    return 0;
}
