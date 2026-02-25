#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key;
    scanf("%d", &n);

    if (n <= 0) {
        printf("0");
        return 0;
    }

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Creating linked list dynamically
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Read key
    scanf("%d", &key);

    // Count occurrences
    int count = 0;
    temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}