// Solving ADt List using Doubly Linked List 
#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Class to represent the doubly linked list with tail
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the beginning
    void insertBeginning(int data) {
        Node* newNode = new Node{data, nullptr, head};
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end
    void insertEnd(int data) {
        Node* newNode = new Node{data, tail, nullptr};
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
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
        Node* newNode = new Node{data, nullptr, nullptr};
        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos - 1; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            insertEnd(data);
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }
        temp->next = newNode;
    }

    // Delete from the beginning
    void deleteBeginning() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    // Delete from the end
    void deleteEnd() {
        if (tail == nullptr) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    // Delete from a specific position (1-indexed)
    void deletePosition(int pos) {
        if (pos <= 1) {
            deleteBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        if (temp == tail) {
            tail = temp->prev;
        }
        delete temp;
    }

    // Search for a value in the list
    bool search(int data) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == data) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
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
5. Delete End: O(1)
6. Delete Position: O(n)
7. Search: O(n)
8. Display: O(n)
*/
