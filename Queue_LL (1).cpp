// Queue ADT using linked List...
#include <iostream>
using namespace std;

// Defining the struct named Node..
struct Node {
    int data;
    Node* next;
};

// Defining class named Queue...
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "\n" << value << " enqueued successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nQueue is Empty. Cannot dequeue.\n";
            return;
        }
        Node* temp = front;
        cout << "\n" << front->data << " dequeued successfully.\n";
        front = front->next;
        delete temp;

        if (front == nullptr) rear = nullptr;
    }

    void peek() {
        if (isEmpty()) {
            cout << "\nQueue is Empty. No element to peek.\n";
            return;
        }
        cout << "\nFront element: " << front->data << "\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "\nQueue is Empty.\n";
            return;
        }
        cout << "\nQueue: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n---- Queue ADT using Linked List ----";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            cout << "\nExiting the program. Goodbye!\n";
            break;
        default:
            cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}