#ifndef LIST_ADT_H
#define LIST_ADT_H

#include <cstdio>
#include <cstdlib>

struct Node {
    int data;
    Node* next;
};

class List {
private:
    Node* head;
    Node* getHead();  // Private function to get the head node address

public:
    List();
    void insertAscending(int value);  // Insert in ascending order
    static List merge(const List& list1, const List& list2);  // Merge two lists
    void display();  // Display the list
};

#endif  // LIST_ADT_H
