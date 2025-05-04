/*program to get a string of'(' and ')' parenthesis from the user and check whether they are balanced*/
#include "lab6.3.h"

bool isBalanced(string expr) {
    Stack s;
    for (char ch : expr) {
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.isEmpty()) {
                return false;
            }
            s.pop();
        }
    }
    return s.isEmpty();
}

//Function to select choicefrom the user
int main() {
    string expression;
    int choice;
    do {
        cout << "\nMenu:\n1. Check Balance\n2. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter parenthesis string: ";
                cin >> expression;
                if (isBalanced(expression)) {
                    cout << "Balanced Parentheses\n";
                } else {
                    cout << "Unbalanced Parentheses\n";
                }
                break;
            case 2:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 2);
    return 0;
}
