#include <cstdio>

const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
private:
    int table[TABLE_SIZE];

public:
    HashTable();
    int hash(int key);
    void insert(int key);
    void remove(int key);
    void search(int key);
    void display();
};

// Main function
int main() {
    HashTable ht;
    int choice, key;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
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
            ht.remove(key);
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
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Constructor
HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = EMPTY;
}

// Hash function
int HashTable::hash(int key) {
    return key % TABLE_SIZE;
}

// Insert function
void HashTable::insert(int key) {
    int index = hash(key);
    int startIndex = index;

    do {
        if (table[index] == EMPTY || table[index] == DELETED) {
            table[index] = key;
            printf("Inserted %d at index %d\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != startIndex);

    printf("Hash Table is full! Cannot insert %d\n", key);
}

// Remove function
void HashTable::remove(int key) {
    int index = hash(key);
    int startIndex = index;

    do {
        if (table[index] == EMPTY) {
            printf("Key %d not found.\n", key);
            return;
        }
        if (table[index] == key) {
            table[index] = DELETED;
            printf("Key %d deleted.\n", key);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != startIndex);

    printf("Key %d not found.\n", key);
}

// Search function
void HashTable::search(int key) {
    int index = hash(key);
    int startIndex = index;

    do {
        if (table[index] == EMPTY) {
            printf("Key %d not found.\n", key);
            return;
        }
        if (table[index] == key) {
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != startIndex);

    printf("Key %d not found.\n", key);
}

// Display function
void HashTable::display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d] : ", i);
        if (table[i] == EMPTY)
            printf("EMPTY");
        else if (table[i] == DELETED)
            printf("DELETED");
        else
            printf("%d", table[i]);
        printf("\n");
    }
}

