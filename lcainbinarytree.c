#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode* root = newNode(arr[0]);

    struct TreeNode* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct TreeNode* curr = queue[front++];

        // left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Find node by value
struct TreeNode* findNode(struct TreeNode* root, int val) {
    if (!root) return NULL;

    if (root->val == val)
        return root;

    struct TreeNode* left = findNode(root->left, val);
    if (left) return left;

    return findNode(root->right, val);
}

// LCA function
struct TreeNode* LCA(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root)
        return NULL;

    if (root == p || root == q)
        return root;

    struct TreeNode* left = LCA(root->left, p, q);
    struct TreeNode* right = LCA(root->right, p, q);

    if (left && right)
        return root;

    return left ? left : right;
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int x, y;
    scanf("%d %d", &x, &y);

    struct TreeNode* root = buildTree(arr, n);

    struct TreeNode* p = findNode(root, x);
    struct TreeNode* q = findNode(root, y);

    struct TreeNode* ans = LCA(root, p, q);

    if (ans)
        printf("%d\n", ans->val);

    return 0;
}