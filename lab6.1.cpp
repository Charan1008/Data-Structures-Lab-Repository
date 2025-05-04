#include <iostream>
using namespace std;

#define MAX_SIZE 5 // Stack size

class Stack {
private:
    char arr[MAX_SIZE];
    int top;

public:
    Stack() { top = -1; } // Constructor initializes top to -1

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

        // Push an element onto the stack
    void push(char value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << "\n";
            return;
        }
        arr[++top] = value;
        cout << "Pushed: " << value << "\n";
    }

      // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return;
        }
        cout << "Popped: " << arr[top--] << "\n";
    }

        // Peek the top element of the stack
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Top element: " << arr[top] << "\n";
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
