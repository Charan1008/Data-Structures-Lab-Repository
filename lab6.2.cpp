/*program to implement stack ADT using a character singly linked list*/
#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() { top = nullptr; } // Constructor initializes top to nullptr

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to push a character onto the stack
    void push(char value) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Heap Overflow! Cannot push " << value << "\n";
            return;
        }
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Pushed: " << value << "\n";
    }

    // Function to pop a character from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return;
        }
        Node* temp = top;
        cout << "Popped: " << top->data << "\n";
        top = top->next;
        delete temp;
    }

    // Function to get the top element of the stack
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Top element: " << top->data << "\n";
    }

    // Destructor to free allocated memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack stack;
    int choice;
    char value;

    do {
        cout << "\nStack Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a character to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
