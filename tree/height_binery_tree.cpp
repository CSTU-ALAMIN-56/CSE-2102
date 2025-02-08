#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new node
struct node* create_node(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Calculate the height of the binary tree
int height(struct node* root) {
    if (root == NULL)
        return 0;

    int left_height = height(root->left);
    int right_height = height(root->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

int main() {
    struct node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);

    printf("Height of the tree: %d\n", height(root));

    return 0;
}
