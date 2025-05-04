#include <iostream>
#include <stack>
using namespace std;

// Node structure for the Expression Tree
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

// Class to handle Expression Tree operations
class ExpressionTree {
public:
    Node* root;

    ExpressionTree() : root(nullptr) {}

    // Function to construct an Expression Tree from a postfix expression
    Node* constructTree(string postfix) {
        stack<Node*> st;
        
        for (char ch : postfix) {
            // If operand, create a node and push onto stack
            if (isalnum(ch)) {
                st.push(new Node(ch));
            } 
            // If operator, pop two operands, create a new node and push back
            else {
                Node* node = new Node(ch);
                node->right = st.top(); st.pop();
                node->left = st.top(); st.pop();
                st.push(node);
            }
        }
        root = st.top();
        return root;
    }

    // Preorder Traversal (Root -> Left -> Right)
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void preorder() { preorder(root); cout << endl; }

    // Inorder Traversal (Left -> Root -> Right)
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    void inorder() { inorder(root); cout << endl; }

    // Postorder Traversal (Left -> Right -> Root)
    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
    void postorder() { postorder(root); cout << endl; }
};

int main() {
    ExpressionTree tree;
    string postfix;
    int choice;

    do {
        cout << "\nExpression Tree Menu:\n";
        cout << "1. Enter Postfix Expression\n";
        cout << "2. Construct Expression Tree\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter postfix expression: ";
                cin >> postfix;
                break;
            case 2:
                tree.constructTree(postfix);
                cout << "Expression Tree Constructed!\n";
                break;
            case 3:
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case 4:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 5:
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
