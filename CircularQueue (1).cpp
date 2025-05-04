// Circular Queue ADT using the integer array..
#include <iostream>
using namespace std;

// Array size is 5..
#define SIZE 5

// Defining the class..
class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear + 1) % SIZE == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "\nQueue is Full. Cannot enqueue " << value << ".\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        cout << "\n" << value << " enqueued successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nQueue is Empty. Cannot dequeue.\n";
            return;
        }
        cout << "\n" << arr[front] << " dequeued successfully.\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "\nQueue is Empty. No element to peek.\n";
            return;
        }
        cout << "\nFront element: " << arr[front] << "\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "\nQueue is Empty.\n";
            return;
        }
        cout << "\nQueue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << "\n";
    }
};

void displayMenu() {
    cout << "\n---- Circular Queue ADT ----";
    cout << "\n1. Enqueue";
    cout << "\n2. Dequeue";
    cout << "\n3. Peek";
    cout << "\n4. Exit";
    cout << "\nEnter your choice: ";
}

int main() {
    CircularQueue cq;
    int choice, value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            cq.enqueue(value);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.peek();
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
