/*program to implement tree ADT using a binary search tree using the following operations
1.Insert
2.Preorder
3.Inorder
4.Postorder
5.Search
6.Exit */
#include <iostream>
using namespace std;

// Definition of Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Class for Binary Search Tree
class BST {
public:
    Node* root;
    BST() : root(nullptr) {}

    // Insert function
    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->data) node->left = insert(node->left, value);
        else node->right = insert(node->right, value);
        return node;
    }
    void insert(int value) { root = insert(root, value); }

    // Inorder Traversal
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    void inorder() { inorder(root); cout << endl; }

    // Preorder Traversal
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void preorder() { preorder(root); cout << endl; }

    // Postorder Traversal
    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
    void postorder() { postorder(root); cout << endl; }

    // Search function
    bool search(Node* node, int key) {
        if (!node) return false;
        if (node->data == key) return true;
        return key < node->data ? search(node->left, key) : search(node->right, key);
    }
    bool search(int key) { return search(root, key); }
};

int main() {
    BST tree;
    int choice, value;
    do {
        cout << "\nBinary Search Tree Menu:";
        cout << "\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                tree.preorder();
                break;
            case 3:
                tree.inorder();
                break;
            case 4:
                tree.postorder();
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (tree.search(value) ? "Found" : "Not Found") << endl;
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);
    return 0;
}
