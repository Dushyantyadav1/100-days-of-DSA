#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for tree building and traversal
struct Queue {
    struct Node** arr;
    int front, rear;
};

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct Node**)malloc(sizeof(struct Node*) * size);
    q->front = q->rear = 0;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Queue* q = createQueue(n);
    struct Node* root = newNode(arr[0]);
    enqueue(q, root);

    int i = 1;

    while (i < n) {
        struct Node* curr = dequeue(q);

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Queue* q = createQueue(2000);
    enqueue(q, root);

    int leftToRight = 1;

    while (q->front < q->rear) {
        int size = q->rear - q->front;
        int temp[size];

        for (int i = 0; i < size; i++) {
            struct Node* node = dequeue(q);

            int index = leftToRight ? i : (size - 1 - i);
            temp[index] = node->data;

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }

        for (int i = 0; i < size; i++) {
            printf("%d ", temp[i]);
        }

        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}