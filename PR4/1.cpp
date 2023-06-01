#include <iostream>
#include <vector>

using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Hash table class
class HashTable {
private:
    vector<Node*> table; // Vector of linked lists
    int size; // Size of table

public:
    // Constructor
    HashTable(int s) {
        size = s;
        table.resize(size);
        for (int i = 0; i < size; i++) {
            table[i] = NULL;
        }
    }

    // Hash function - remainder method
    int hash(int key) {
        return key % size;
    }

    // Insert key into table
    void insert(int key) {
        int index = hash(key);
        Node* temp = new Node;
        temp->data = key;
        temp->next = NULL;
        if (table[index] == NULL) {
            table[index] = temp;
        }
        else {
            Node* p = table[index];
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp;
        }
    }

    // Print contents of table
    void print() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (table[i] != NULL) {
                Node* p = table[i];
                while (p != NULL) {
                    cout << p->data << " ";
                    p = p->next;
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(7);
    ht.insert(86);
    ht.insert(90);
    ht.insert(27);
    ht.insert(29);
    ht.insert(38);
    ht.insert(30);
    ht.insert(40);
    ht.print();
    return 0;
}
