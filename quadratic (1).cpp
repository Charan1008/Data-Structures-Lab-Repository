#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
private:
    int table[TABLE_SIZE];

    int hash(int key);

public:
    HashTable();
    void insert(int key);
    void deleteKey(int key);
    void search(int key);
    void display();
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        printf("\n------ Hash Table Menu ------\n");
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
            ht.insert(key);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            ht.deleteKey(key);
            break;
        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
            ht.search(key);
            break;
        case 4:
            ht.display();
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}

// Function definitions outside the class

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = EMPTY;
}

int HashTable::hash(int key) {
    return key % TABLE_SIZE;
}

void HashTable::insert(int key) {
    int index = hash(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int probeIndex = (index + i * i) % TABLE_SIZE;

        if (table[probeIndex] == EMPTY || table[probeIndex] == DELETED) {
            table[probeIndex] = key;
            printf("Inserted %d at index %d\n", key, probeIndex);
            return;
        } else if (table[probeIndex] == key) {
            printf("Duplicate key! Insertion failed.\n");
            return;
        }

        i++;
    }

    printf("Hash table is full! Insertion failed.\n");
}

void HashTable::search(int key) {
    int index = hash(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int probeIndex = (index + i * i) % TABLE_SIZE;

        if (table[probeIndex] == EMPTY) {
            printf("Key not found.\n");
            return;
        }

        if (table[probeIndex] == key) {
            printf("Key found at index %d\n", probeIndex);
            return;
        }

        i++;
    }

    printf("Key not found.\n");
}

void HashTable::deleteKey(int key) {
    int index = hash(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int probeIndex = (index + i * i) % TABLE_SIZE;

        if (table[probeIndex] == EMPTY) {
            printf("Key not found. Deletion failed.\n");
            return;
        }

        if (table[probeIndex] == key) {
            table[probeIndex] = DELETED;
            printf("Key deleted from index %d\n", probeIndex);
            return;
        }

        i++;
    }

    printf("Key not found. Deletion failed.\n");
}

void HashTable::display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        if (table[i] == EMPTY)
            printf("EMPTY\n");
        else if (table[i] == DELETED)
            printf("DELETED\n");
        else
            printf("%d\n", table[i]);
    }
}

