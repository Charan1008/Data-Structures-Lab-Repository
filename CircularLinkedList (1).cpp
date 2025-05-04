// Solving ADt List using Circular Linked List
#include <iostream>
using namespace std;

// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;
};

// Class to represent the circular linked list
class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() : tail(nullptr) {}

    // Insert at the beginning
    void insertBeginning(int data) {
        Node* newNode = new Node{data, nullptr};
        if (tail == nullptr) {
            newNode->next = newNode;
            tail = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    // Insert at the end
    void insertEnd(int data) {
        Node* newNode = new Node{data, nullptr};
        if (tail == nullptr) {
            newNode->next = newNode;
            tail = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Insert at a specific position (1-indexed)
    void insertPosition(int pos, int data) {
        if (pos <= 1) {
            insertBeginning(data);
            return;
        }
        Node* newNode = new Node{data, nullptr};
        Node* temp = tail->next;
        for (int i = 1; temp != tail && i < pos - 1; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) {
            tail = newNode;
        }
    }

    // Delete from the beginning
    void deleteBeginning() {
        if (tail == nullptr) return;
        Node* temp = tail->next;
        if (tail == temp) {
            tail = nullptr;
        } else {
            tail->next = temp->next;
        }
        delete temp;
    }

    // Delete from the end
    void deleteEnd() {
        if (tail == nullptr) return;
        Node* temp = tail->next;
        if (tail == temp) {
            delete tail;
            tail = nullptr;
            return;
        }
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = tail->next;
        delete tail;
        tail = temp;
    }

    // Delete from a specific position (1-indexed)
    void deletePosition(int pos) {
        if (tail == nullptr || pos <= 1) {
            deleteBeginning();
            return;
        }
        Node* temp = tail->next;
        for (int i = 1; temp->next != tail->next && i < pos - 1; ++i) {
            temp = temp->next;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        if (delNode == tail) {
            tail = temp;
        }
        delete delNode;
    }

    // Search for a value in the list
    bool search(int data) {
        if (tail == nullptr) return false;
        Node* temp = tail->next;
        do {
            if (temp->data == data) {
                return true;
            }
            temp = temp->next;
        } while (temp != tail->next);
        return false;
    }

    // Display the list
    void display() {
        if (tail == nullptr) return;
        Node* temp = tail->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;
    int choice, data, pos;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Insert Beginning" << endl;
        cout << "2. Insert End" << endl;
        cout << "3. Insert Position" << endl;
        cout << "4. Delete Beginning" << endl;
        cout << "5. Delete End" << endl;
        cout << "6. Delete Position" << endl;
        cout << "7. Search" << endl;
        cout << "8. Display" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                list.insertBeginning(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                list.insertEnd(data);
                break;
            case 3:
                cout << "Enter position and data: ";
                cin >> pos >> data;
                list.insertPosition(pos, data);
                break;
            case 4:
                list.deleteBeginning();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                list.deletePosition(pos);
                break;
            case 7:
                cout << "Enter data to search: ";
                cin >> data;
                if (list.search(data)) {
                    cout << "Data found!" << endl;
                } else {
                    cout << "Data not found." << endl;
                }
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 9);

    return 0;
}

/*
Time Complexity of Operations:
1. Insert Beginning: O(1)
2. Insert End: O(1)
3. Insert Position: O(n)
4. Delete Beginning: O(1)
5. Delete End: O(n)
6. Delete Position: O(n)
7. Search: O(n)
8. Display: O(n)
*/
