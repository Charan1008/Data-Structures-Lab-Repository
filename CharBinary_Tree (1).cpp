// Tree ADT using Character binary Tree...
#include <iostream>
using namespace std;

// Node structure for the tree
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = right = nullptr;
    }
};

// Class named as BinaryTree..
class BinaryTree {
private:
    Node* root;
    // Helper function for insertion
    Node* insert(Node* node, char value) {
        if (node == nullptr) {
            return new Node(value);
        }

        char choice;
        cout << "Insert " << value << " to the left or right of " << node->data << "? (l/r): ";
        cin >> choice;

        if (choice == 'l' || choice == 'L') {
            node->left = insert(node->left, value);
        } else if (choice == 'r' || choice == 'R') {
            node->right = insert(node->right, value);
        } else {
            cout << "Invalid choice. Skipping insertion.\n";
        }
        return node;
    }
    // Helper function for preorder traversal
    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    // Helper function for inorder traversal
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Helper function for postorder traversal
    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
    // Helper function for searching a node
    bool search(Node* node, char value) {
        if (node == nullptr) return false;
        if (node->data == value) return true;
        return search(node->left, value) || search(node->right, value);
    }

public:
    BinaryTree() {
        root = nullptr;
    }
    // Public method for insertion
    void insert(char value) {
        if (root == nullptr) {
            root = new Node(value);
            cout << "\nRoot node " << value << " inserted.\n";
        } else {
            insert(root, value);
        }
    }
    // Public method for preorder traversal
    void preorderTraversal() {
        if (root == nullptr) {
            cout << "\nTree is empty.\n";
            return;
        }
        cout << "\nPreorder Traversal: ";
        preorder(root);
        cout << "\n";
    }
    // Public method for inorder traversal
    void inorderTraversal() {
        if (root == nullptr) {
            cout << "\nTree is empty.\n";
            return;
        }
        cout << "\nInorder Traversal: ";
        inorder(root);
        cout << "\n";
    }
    // Public method for postorder traversal
    void postorderTraversal() {
        if (root == nullptr) {
            cout << "\nTree is empty.\n";
            return;
        }
        cout << "\nPostorder Traversal: ";
        postorder(root);
        cout << "\n";
    }
    // Public method for search operation
    void search(char value) {
        if (search(root, value)) {
            cout << "\nElement '" << value << "' found in the tree.\n";
        } else {
            cout << "\nElement '" << value << "' not found in the tree.\n";
        }
    }
};

void displayMenu() {
    cout << "\n---- Tree ADT using Character Binary Tree ----";
    cout << "\n1. Insert";
    cout << "\n2. Preorder Traversal";
    cout << "\n3. Inorder Traversal";
    cout << "\n4. Postorder Traversal";
    cout << "\n5. Search";
    cout << "\n6. Exit";
    cout << "\nEnter your choice: ";
}

// Main function to run the menu-driven program
int main() {
    BinaryTree tree;
    int choice;
    char value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter character value to insert: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2:
            tree.preorderTraversal();
            break;
        case 3:
            tree.inorderTraversal();
            break;
        case 4:
            tree.postorderTraversal();
            break;
        case 5:
            cout << "Enter character to search: ";
            cin >> value;
            tree.search(value);
            break;
        case 6:
            cout << "\nExiting the program. Goodbye!\n";
            break;
        default:
            cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}