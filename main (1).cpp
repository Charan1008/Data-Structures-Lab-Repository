#include "ListADT.h"

// Constructor
List::List() : head(nullptr) {}

// Private function to return the head of the list
Node* List::getHead() {
    return head;
}

// Insert in ascending order
void List::insertAscending(int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->next = nullptr;

    if (head == nullptr || head->data >= value) {
        newnode->next = head;
        head = newnode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data < value) {
        current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
}

// Merge two lists into a third list in ascending order
List List::merge(const List& list1, const List& list2) {
    List mergedList;
    Node* head1 = list1.head;
    Node* head2 = list2.head;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            mergedList.insertAscending(head1->data);
            head1 = head1->next;
        } else {
            mergedList.insertAscending(head2->data);
            head2 = head2->next;
        }
    }

    while (head1 != nullptr) {
        mergedList.insertAscending(head1->data);
        head1 = head1->next;
    }

    while (head2 != nullptr) {
        mergedList.insertAscending(head2->data);
        head2 = head2->next;
    }

    return mergedList;
}

// Display the list
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

#include "ListADT.h"

int main() {
    List list1, list2, list3;
    int choice;
    int value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert into List1\n");
        printf("2. Insert into List2\n");
        printf("3. Merge List1 and List2 into List3\n");
        printf("4. Display Lists\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert into List1: ");
                scanf("%d", &value);
                list1.insertAscending(value);
                break;

            case 2:
                printf("Enter value to insert into List2: ");
                scanf("%d", &value);
                list2.insertAscending(value);
                break;

            case 3:
                list3 = List::merge(list1, list2);
                printf("Lists merged into List3.\n");
                break;

            case 4:
                printf("List1: ");
                list1.display();
                printf("List2: ");
                list2.display();
                printf("List3: ");
                list3.display();
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
