#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert at end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Function to delete first occurrence
struct Node* deleteFirst(struct Node* head, int key) {
    if (head == NULL)
        return head;

    // If head contains key
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If key not found
    if (current == NULL)
        return head;

    // Delete node
    prev->next = current->next;
    free(current);

    return head;
}

// Function to print list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, value, key;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    scanf("%d", &key);

    head = deleteFirst(head, key);

    printList(head);

    return 0;
}