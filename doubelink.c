#include <stdio.h>
#include <stdlib.h>

// Structure of Doubly Linked List Node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Insert at tail
Node* insertAtTail(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;

    // Traverse to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Forward traversal
void traverseForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Node* head = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertAtTail(head, value);
    }

    traverseForward(head);

    return 0;
}