#include <stdio.h>
#include <stdlib.h>

// Tree Node Definition
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for building tree
struct QueueNode {
    struct TreeNode* node;
};

struct Queue {
    struct TreeNode** arr;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->arr = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    return q;
}

int isEmpty(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = node;
    q->size++;
}

struct TreeNode* dequeue(struct Queue* q) {
    struct TreeNode* node = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

// Build tree from level order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Queue* q = createQueue(n);
    struct TreeNode* root = createNode(arr[0]);
    enqueue(q, root);

    int i = 1;
    while (!isEmpty(q) && i < n) {
        struct TreeNode* current = dequeue(q);

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(q, current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(q, current->right);
        }
        i++;
    }

    return root;
}

// Pair for vertical traversal
struct Pair {
    struct TreeNode* node;
    int hd;
};

// Queue for vertical traversal
struct VQueue {
    struct Pair* arr;
    int front, rear, size, capacity;
};

struct VQueue* createVQueue(int capacity) {
    struct VQueue* q = (struct VQueue*)malloc(sizeof(struct VQueue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->arr = (struct Pair*)malloc(capacity * sizeof(struct Pair));
    return q;
}

void enqueueV(struct VQueue* q, struct TreeNode* node, int hd) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->size++;
}

struct Pair dequeueV(struct VQueue* q) {
    struct Pair p = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return p;
}

int isEmptyV(struct VQueue* q) {
    return q->size == 0;
}

// Vertical Order Traversal
void verticalOrder(struct TreeNode* root) {
    if (!root) return;

    struct VQueue* q = createVQueue(2000);
    enqueueV(q, root, 0);

    int offset = 1000;
    int columns[2000][2000] = {0};
    int colSize[2000] = {0};

    int minHD = 0, maxHD = 0;

    while (!isEmptyV(q)) {
        struct Pair temp = dequeueV(q);
        struct TreeNode* node = temp.node;
        int hd = temp.hd;

        int index = hd + offset;
        columns[index][colSize[index]++] = node->val;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left) enqueueV(q, node->left, hd - 1);
        if (node->right) enqueueV(q, node->right, hd + 1);
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        int index = i + offset;
        for (int j = 0; j < colSize[index]; j++) {
            printf("%d ", columns[index][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}