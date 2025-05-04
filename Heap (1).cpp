// Heap having driven menu of 5 Operations...

#include <iostream>
using namespace std;

class MaxHeap {
private:
    int *heap;
    int size;
    int capacity;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap(int cap) {
        capacity = cap;
        heap = new int[capacity];
        size = 0;
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    void deleteMax() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }

    void display() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    bool search(int value) {
        for (int i = 0; i < size; i++) {
            if (heap[i] == value) return true;
        }
        return false;
    }

    void heapSort() {
        int tempSize = size;
        while (size > 1) {
            swap(heap[0], heap[size - 1]);
            size--;
            heapifyDown(0);
        }
        size = tempSize;
        cout << "Sorted elements: ";
        display();
    }

    ~MaxHeap() {
        delete[] heap;
    }
};

int main() {
    int capacity;
    cout << "Enter capacity of max heap: ";
    cin >> capacity;
    MaxHeap maxHeap(capacity);

    int choice, value;
    do {
        cout << "\nPriority Queue Menu:\n";
        cout << "1. Insert\n2. Delete\n3. Display\n4. Search\n5. Sort (Heap Sort)\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                maxHeap.insert(value);
                break;
            case 2:
                maxHeap.deleteMax();
                break;
            case 3:
                maxHeap.display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (maxHeap.search(value))
                    cout << "Value found!" << endl;
                else
                    cout << "Value not found!" << endl;
                break;
            case 5:
                maxHeap.heapSort();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
