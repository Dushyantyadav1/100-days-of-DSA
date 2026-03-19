#include <stdio.h>
#include <stdlib.h>

// Define structure
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

// Function to find height
int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + (left > right ? left : right);
}

int main() {
    // Creating tree:
    //       1
    //      / \
    //     2   3
    //    /
    //   4

    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    // Print height
    printf("Height of Binary Tree: %d\n", height(root));

    return 0;
}