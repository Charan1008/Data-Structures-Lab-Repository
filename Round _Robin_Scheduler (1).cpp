// Round Robin scheduler using the header file created....
#include "Round_Robin_scheduler.h"

// Constructor
RoundRobinScheduler::RoundRobinScheduler(int slice) : tail(nullptr), timeSlice(slice) {}

// Destructor to free memory
RoundRobinScheduler::~RoundRobinScheduler() {
    if (tail == nullptr) return;
    Node* current = tail->next;
    while (current != tail) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete tail;
}

// Insert a process at the end
void RoundRobinScheduler::insertProcess(int time) {
    Node* newNode = new Node{time, nullptr};
    if (tail == nullptr) {
        newNode->next = newNode;  // Point to itself to form a circular list
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

// Execute the processes in a round-robin manner
void RoundRobinScheduler::execute() {
    if (tail == nullptr) {
        cout << "No processes to execute." << endl;
        return;
    }

    Node* current = tail->next;
    do {
        int remainingTime = current->processTime - timeSlice;
        cout << "Executing process with time " << current->processTime << ". Remaining time: ";

        if (remainingTime <= 0) {
            cout << "0 (Process completed)" << endl;
            if (current == tail) {
                delete current;
                tail = nullptr;
                return;
            }
            Node* temp = current->next;
            if (current == tail->next) {
                tail->next = temp;
            }
            delete current;
            current = temp;
        } else {
            cout << remainingTime << " (Reinserted to queue)" << endl;
            current->processTime = remainingTime;
            tail = current;
            current = current->next;
        }
    } while (current != tail->next);
}

// Display all processes in the queue
void RoundRobinScheduler::displayProcesses() {
    if (tail == nullptr) {
        cout << "No processes in the queue." << endl;
        return;
    }

    Node* current = tail->next;
    cout << "Processes in queue: ";
    do {
        cout << current->processTime << " ";
        current = current->next;
    } while (current != tail->next);
    cout << endl;
}

#include "Round_Robin_scheduler.h"

int main() {
    int timeSlice;
    cout << "Enter the fixed time slice: ";
    cin >> timeSlice;

    RoundRobinScheduler scheduler(timeSlice);
    int choice, processTime;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Insert Process" << endl;
        cout << "2. Execute" << endl;
        cout << "3. Display Processes" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter process time: ";
                cin >> processTime;
                scheduler.insertProcess(processTime);
                break;
            case 2:
                scheduler.execute();
                break;
            case 3:
                scheduler.displayProcesses();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
