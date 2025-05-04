#include <iostream>
#include <list>
#include <iterator>
using namespace std;

// Define the hash table size
#define SIZE 10

// Hash Table class with Separate Chaining
class HashTable {
public:
    list<int> *table; // Array of linked lists

    // Constructor to initialize the hash table
    HashTable() {
        table = new list<int>[SIZE];
    }

    // Destructor to delete the dynamically allocated memory
    ~HashTable() {
        delete[] table;
    }
};

int main() {
    HashTable hashTable;
    int choice, key;

    do {
        // Menu-driven options
        printf("\nHash Table Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(hashTable, key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(hashTable, key);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(hashTable, key);
                break;
            case 4:
                printf("Hash Table Contents: \n");
                display(hashTable);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}


// Hash function to map values to keys
int hashFunction(int key) {
    return key % SIZE;
}

// Insert a key into the hash table
void insert(HashTable &hashTable, int key) {
    int index = hashFunction(key);
    hashTable.table[index].push_back(key); // Add key to the linked list
    printf("Key %d inserted.\n", key);
}

// Delete a key from the hash table
void deleteKey(HashTable &hashTable, int key) {
    int index = hashFunction(key);
    list<int>::iterator it = find(hashTable.table[index].begin(), hashTable.table[index].end(), key);
    
    if (it != hashTable.table[index].end()) {
        hashTable.table[index].erase(it);
        printf("Key %d deleted.\n", key);
    } else {
        printf("Key %d not found.\n", key);
    }
}

// Search for a key in the hash table
void search(HashTable &hashTable, int key) {
    int index = hashFunction(key);
    list<int>::iterator it = find(hashTable.table[index].begin(), hashTable.table[index].end(), key);
    
    if (it != hashTable.table[index].end()) {
        printf("Key %d found.\n", key);
    } else {
        printf("Key %d not found.\n", key);
    }
}

// Display the hash table
void display(const HashTable &hashTable) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d", i);
        for (auto x : hashTable.table[i]) {
            printf(" --> %d", x);
        }
        printf("\n");
    }
}

