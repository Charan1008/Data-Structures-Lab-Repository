// Programming in c
#include <iostream>
using namespace std;

#define SIZE 5  // Maximum size of the list

class LIST {
private:
    int array[SIZE];  // Array to store elements
    int count = 0;    // Number of elements in the list

public:
    int insertbeg(int);
    int insertend(int);
    int insertpos(int, int);
    int deletebeg();
    int deleteend();
    int deletepos(int);
    int search(int);
    void display();
    int rotate(int);  // New function for rotation
};

int main() {
    LIST li1;
    int value, choice, position, rotateCount;

    cout << "MENU: \n";
    cout << "1. Insert at beginning. \n";
    cout << "2. Insert at end. \n";
    cout << "3. Insert at position. \n";
    cout << "4. Delete from beginning. \n";
    cout << "5. Delete from end. \n";
    cout << "6. Delete from position. \n";
    cout << "7. Search for a value. \n";
    cout << "8. Display the list. \n";
    cout << "9. Rotate the list. \n";
    cout << "10. Exit. \n";

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element value: ";
                cin >> value;
                li1.insertbeg(value);
                break;

            case 2:
                cout << "Enter element value: ";
                cin >> value;
                li1.insertend(value);
                break;

            case 3:
                cout << "Enter element value: ";
                cin >> value;
                cout << "Enter the index at which you want to add element: ";
                cin >> position;
                li1.insertpos(value, position);
                break;

            case 4:
                li1.deletebeg();
                break;

            case 5:
                li1.deleteend();
                break;

            case 6:
                cout << "Enter the index at which you want to delete element: ";
                cin >> position;
                li1.deletepos(position);
                break;

            case 7:
                cout << "Enter the Value that has to be searched: ";
                cin >> value;
                li1.search(value);
                break;

            case 8:
                cout << "The elements of the array are: ";
                li1.display();
                break;

            case 9:
                cout << "Enter number of positions to rotate left: ";
                cin >> rotateCount;
                li1.rotate(rotateCount);
                break;

            case 10:
                cout << "The program Ends.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (choice != 10);

    return 0;
}

// Insert at the beginning
int LIST::insertbeg(int val) {
    if (count >= SIZE) {
        cout << "The array is full. Cannot add element.\n";
        return 0;
    }
    for (int i = count; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = val;
    count++;
    return 1;
}

// Insert at the end
int LIST::insertend(int val) {
    if (count >= SIZE) {
        cout << "The array is full. Cannot add element.\n";
        return 0;
    }
    array[count++] = val;
    return 1;
}

// Insert at a specific position
int LIST::insertpos(int val, int pos) {
    if (count >= SIZE) {
        cout << "The array is full. Cannot add element.\n";
        return 0;
    }
    if (pos < 0 || pos > count) {
        cout << "Invalid position. Must be between 0 and " << count << ".\n";
        return 0;
    }
    for (int i = count; i > pos; i--) {
        array[i] = array[i - 1];
    }
    array[pos] = val;
    count++;
    return 1;
}

// Delete from the beginning
int LIST::deletebeg() {
    if (count == 0) {
        cout << "The array is empty. Cannot delete an element.\n";
        return 0;
    }
    cout << "The element being deleted is: " << array[0] << "\n";
    for (int i = 1; i < count; i++) {
        array[i - 1] = array[i];
    }
    count--;
    return 1;
}

// Delete from the end
int LIST::deleteend() {
    if (count == 0) {
        cout << "The array is empty. Cannot delete an element.\n";
        return 0;
    }
    cout << "The element being deleted is: " << array[count - 1] << "\n";
    count--;
    return 1;
}

// Delete from a specific position
int LIST::deletepos(int pos) {
    if (count == 0) {
        cout << "The array is empty. Cannot delete an element.\n";
        return 0;
    }
    if (pos < 0 || pos >= count) {
        cout << "Invalid position. Must be between 0 and " << count - 1 << ".\n";
        return 0;
    }
    cout << "The element being deleted is: " << array[pos] << "\n";
    for (int i = pos; i < count - 1; i++) {
        array[i] = array[i + 1];
    }
    count--;
    return 1;
}

// Search for an element
int LIST::search(int val) {
    for (int i = 0; i < count; i++) {
        if (array[i] == val) {
            cout << "The Element is found at index: " << i << "\n";
            return 1;
        }
    }
    cout << "The Element was not found.\n";
    return 0;
}

// Display all elements
void LIST::display() {
    if (count == 0) {
        cout << "The list is empty.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

// Rotate the list left by k positions
int LIST::rotate(int k) {
    if (count == 0) {
        cout << "The array is empty. Cannot rotate.\n";
        return 0;
    }
    k = k % count; // Avoid unnecessary rotations
    if (k == 0) {
        cout << "Rotation not needed.\n";
        return 1;
    }

    // Temporary array to store rotated elements
    int temp[SIZE];
    for (int i = 0; i < count; i++) {
        temp[i] = array[(i + k) % count];
    }

    // Copy back rotated elements
    for (int i = 0; i < count; i++) {
        array[i] = temp[i];
    }

    cout << "Array after rotation: ";
    display();
    return 1;
}
