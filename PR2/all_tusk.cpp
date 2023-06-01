#include <iostream>
#include <ctime>
#include <stack>

using namespace std;

class AVL
{
    struct node
    {
        int data = -1;
        node* left = nullptr;
        node* right = nullptr;
        char color = 'N';
        int height;
    };
    node* root;
    void makeEmpty(node* t)
    {
        if (t == NULL)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    node* insert(int x, node* t)
    {
        if (t == NULL)
        {
            t = new node;
            t->data = x;
            t->height = 0;
            t->left = t->right = NULL;
        }
        else if (x < t->data)
        {
            t->left = insert(x, t->left);
            if (height(t->left) - height(t->right) == 2)
            {
                if (x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if (x > t->data)
        {
            t->right = insert(x, t->right);
            if (height(t->right) - height(t->left) == 2)
            {
                if (x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right)) + 1;
        return t;
    }
    node* singleRightRotate(node*& t)
    {
        node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        u->height = max(height(u->left), t->height) + 1;
        return u;
    }
    node* singleLeftRotate(node*& t)
    {
        node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        u->height = max(height(t->right), t->height) + 1;
        return u;
    }
    node* doubleLeftRotate(node*& t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }
    node* doubleRightRotate(node*& t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }
    node* findMin(node* t)
    {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }
    node* findMax(node* t)
    {
        if (t == NULL)
            return NULL;
        else if (t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }
    node* remove(int x, node* t)
    {
        node* temp;

        if (t == NULL)
            return NULL;

        else if (x < t->data)
            t->left = remove(x, t->left);
        else if (x > t->data)
            t->right = remove(x, t->right);

        else if (t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
      
        else
        {
            temp = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            delete temp;
        }
        if (t == NULL)
            return t;

        t->height = max(height(t->left), height(t->right)) + 1;

        if (height(t->left) - height(t->right) == 2)
        {
            if (height(t->left->left) - height(t->left->right) == 1)
                return singleLeftRotate(t);
            else
                return doubleLeftRotate(t);
        }
        else if (height(t->right) - height(t->left) == 2)
        {
            if (height(t->right->right) - height(t->right->left) == 1)
                return singleRightRotate(t);
            else
                return doubleRightRotate(t);
        }
        return t;
    }

    int height(node* t)
    {
        return (t == NULL ? -1 : t->height);
    }
    int getBalance(node* t)
    {
        if (t == NULL)
            return 0;
        else
            return height(t->left) - height(t->right);
    }
    void inorder(node* t)
    {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }
    void inorder_b(node* t)
    {
        if (t == NULL)
            return;
        inorder_b(t->left);
        cout << getBalance(t) << " ";
        inorder_b(t->right);
    }
    void inorder_c(node* t)
    {
        if (t == NULL)
            return;
        inorder_c(t->left);
        cout << t->color << " ";
        inorder_c(t->right);
    }
    void colored2(node &h, char C)
    {
        if (C == 'B')
        {
            h.color = 'R';
            if (h.left != nullptr) colored2(*(h.left), 'R');
            if (h.right != nullptr) colored2(*(h.right), 'R');
            if (h.left == nullptr && h.right == nullptr) h.color = 'B';
        }
        else
        {
            h.color = 'R';
            if (h.left != nullptr) colored2(*(h.left), 'B');
            if (h.right != nullptr) colored2(*(h.right), 'B');
            if (h.left == nullptr && h.right == nullptr) h.color = 'B';
        }
    }

public:
    AVL()
    {
        root = new node;
    }

    void insert(int x)
    {
        root = insert(x, root);
    }
    void remove(int x)
    {
        root = remove(x, root);
    }
    int getkey()
    {
        return root->data;
    }
    node* getr()
    {
        return root->right;
    }
    node* getl()
    {
        return root->left;
    }
    void setkey(int p)
    {
        root->data = p;
    }
    void setr(node*p)
    {
        root->right = p;
    }
    void setl(node* p)
    {
        root->left = p;
    }
    node* getnode()
    {
        return root;
    }
    void setnode(node* p)
    {
        root = p;
    }
    void colored()
    {
        root->color = 'B';
        if (root->left != nullptr) colored2(*(root->left), 'B');
        if (root->right != nullptr) colored2(*(root->right), 'B');
    }
    void display()
    {
        inorder(root);
        cout << endl;
    }
    void display_b()
    {
        inorder_b(root);
        cout << endl;
    }
    void display_c()
    {
        inorder_c(root);
        cout << endl;
    }
};

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));
	int rn;
	AVL t;
    t.setkey(rand() % 99 + 1);

    for (int i = 0; i < 5; i++)
    {
        rn = rand() % 99 + 1;
        t.insert(rn);
    }

    t.colored();

    t.display();
    t.display_b();
    t.display_c();

    cout << "\n";
    t.insert(rand() % 99 + 1);

    t.colored();

    t.display();
    t.display_b();
    t.display_c();

	return 0;
}
