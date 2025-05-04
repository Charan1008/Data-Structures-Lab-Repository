#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class List {
    private:
    Node* head;
    Node* tail;

    public:
    List();
    void menu();
    void insertBeg(int value);
    void insertEnd(int value);
    void insertPos(int value, int position);
    void deleteBeg();
    void deleteEnd();
    void deletePos(int position);
    bool search(int value);
    void display();
    void displayReverse();
    void displayReverseHelper(Node* current);
    void reversedList();
};

int main() {
    List list;
    int choice;
    int value;
    int position;

    do {
        list.menu();
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                list.insertBeg(value);
                break;

            case 2:
                printf("Enter the value: ");
                scanf("%d", &value);
                list.insertEnd(value);
                break;

            case 3:
                printf("Enter the value: ");
                scanf("%d", &value);
                printf("Enter the position: ");
                scanf("%d", &position);
                list.insertPos(value, position);
                break;

            case 4:
                list.deleteBeg();
                break;

            case 5:
                list.deleteEnd();
                break;

            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                list.deletePos(position);
                break;

            case 7:
                printf("Enter the value: ");
                scanf("%d", &value);
                printf("%s\n", list.search(value) ? "Found" : "Not Found");
                break;

            case 8:
                list.display();
                break;

            case 9:
                list.displayReverse();
                break;

            case 10:
                list.reversedList();
                break;

            case 11:
                printf("Exiting the program..\n");
                break;

            default:
                printf("Invalid choice... Please enter a valid choice.\n");
                break;
        }
    } while (choice != 11);
    return 0;
}

List::List() : head(nullptr), tail(nullptr) {}

void List::menu() {
    printf("1. Insert at the Beginning.\n");
    printf("2. Insert at the End.\n");
    printf("3. Insert at the Position.\n");
    printf("4. Delete from the Beginning.\n");
    printf("5. Delete from the End.\n");
    printf("6. Delete at the Position.\n");
    printf("7. Search the Value.\n");
    printf("8. Display the List.\n");
    printf("9. Display the List in Reverse.\n");
    printf("10. Reverse the List.\n");
    printf("11. Exit.\n");
}

void List::insertEnd(int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->next = nullptr;
    if (head == nullptr) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

void List::insertPos(int value, int position) {
    if (position <= 0) {
        insertBeg(value);
        return;
    }

    Node* newnode = new Node();
    newnode->data = value;

    Node* current = head;
    int index = 0;

    while (current != nullptr && index < position - 1) {
        current = current->next;
        index++;
    }

    if (current == nullptr) {
        insertEnd(value);
    } else {
        newnode->next = current->next;
        current->next = newnode;
    }
}

void List::deleteBeg() {
    if (head == nullptr) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr) {
        tail = nullptr;
    }
}

void List::deleteEnd() {
    if (head == nullptr) {
        printf("List is empty.\n");
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }

    delete tail;
    tail = current;
    tail->next = nullptr;
}

void List::deletePos(int position) {
    if (position <= 0) {
        deleteBeg();
        return;
    }

    Node* current = head;
    Node* prev = nullptr;
    int index = 0;

    while (current != nullptr && index < position) {
        prev = current;
        current = current->next;
        index++;
    }

    if (current == nullptr) {
        printf("Position out of bounds.\n");
        return;
    }

    prev->next = current->next;
    if (current == tail) {
        tail = prev;
    }
    delete current;
}

void List::display() {
    Node* current = head;
    if (current == nullptr) {
        printf("List is empty.\n");
        return;
    }

    while (current != nullptr) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void List::displayReverse() {
    displayReverseHelper(head);
    printf("\n");
}

void List::displayReverseHelper(Node* current) {
    if (current == nullptr) {
        return;
    }
    displayReverseHelper(current->next);
    printf("%d ", current->data);
}

void List::reversedList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    tail = head;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}
