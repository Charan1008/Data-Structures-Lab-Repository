// Queue ADT using integer array...
#include <iostream>
using namespace std;

// Size of the array is 5...
#define SIZE 5

// Defining the class..
class Queue {
private:
    int arr[SIZE];
    int front, rear; 

public:
    // Defining the class name Queue..
    Queue() {
        front = -1;
        rear = -1;
    }
    // Full Condition..
    bool isFull() {
        return rear == SIZE - 1;
    }
    // Empty condition..
    bool isEmpty() {
        return front == -1 || front > rear;
    }
    // Enqueue Function..
    void enqueue(int value) {
        if (isFull()) {
            cout << "\nQueue is Full. Cannot enqueue " << value << ".\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
        cout << "\n" << value << " enqueued successfully.\n";
    }
    // Dequeue Function..
    void dequeue() {
        if (isEmpty()) {
            cout << "\nQueue is Empty. Cannot dequeue.\n";
            return;
        }
        cout << "\n" << arr[front++] << " dequeued successfully.\n";
        if (front > rear) front = rear = -1; // Reset after last element
    }
    // Peeking the first element..
    void peek() {
        if (isEmpty()) {
            cout << "\nQueue is Empty. No element to peek.\n";
            return;
        }
        cout << "\nFront element: " << arr[front] << "\n";
    }
    // Displaying the Queue..
    void display() {
        if (isEmpty()) {
            cout << "\nQueue is Empty.\n";
            return;
        }
        cout << "\nQueue: ";
        for (int i = front; i <= rear; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};
// Menu Function..
void displayMenu() {
    cout << "\n-----MENU-----\n";
    cout << "1. Enqueue.\n";
    cout << "2. Dequeue.\n";
    cout << "3. Peek.\n";
    cout << "4. Exit..\n";
    cout << "Enter the choice.\n";
}

// Main Function..
int main() {
    Queue q;
    int choice, value;

    do {
        displayMenu(); // Calling the menu function in the main function..
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