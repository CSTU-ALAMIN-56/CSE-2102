#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int item;
    struct node* left;
    struct node* right;
};

// Inorder traversal
void inorder_traversal(struct node* root) {
    if (root == NULL) return;
    inorder_traversal(root->left);
    printf("%d -> ", root->item);
    inorder_traversal(root->right);
}

// Preorder traversal
void preorder_traversal(struct node* root) {
    if (root == NULL) return;
    printf("%d -> ", root->item);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

// Postorder traversal
void postorder_traversal(struct node* root) {
    if (root == NULL) return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d -> ", root->item);
}

// Create a new node
struct node* create_node(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->item = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert node to the left
struct node* insert_left(struct node* root, int value) {
    root->left = create_node(value);
    return root->left;
}

// Insert node to the right
struct node* insert_right(struct node* root, int value) {
    root->right = create_node(value);
    return root->right;
}

int main() {
    struct node* root = create_node(1);
    insert_left(root, 12);
    insert_right(root, 9);
    insert_left(root->left, 5);
    insert_right(root->left, 6);

    printf("Inorder Traversal: \n");
    inorder_traversal(root);
    printf("NULL\n");

    printf("\nPreorder Traversal: \n");
    preorder_traversal(root);
    printf("NULL\n");

    printf("\nPostorder Traversal: \n");
    postorder_traversal(root);
    printf("NULL\n");

    return 0;
}

