#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    Node *left;
    Node *right;
    int data;
};

// Function Declarations
Node* create_node(int item);
void add_left_child(Node* node, Node* child);
void add_right_child(Node* node, Node* child);
Node* create_tree();
void preOrder(Node* node);
Node* bst_insert(Node* root, int item);

// Create a new node
Node* create_node(int item) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory Not Allocated\n");
        exit(1);
    }
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Add left child to a node
void add_left_child(Node* node, Node* child) {
    node->left = child;
}

// Add right child to a node
void add_right_child(Node* node, Node* child) {
    node->right = child;
}

// Create a sample tree
Node* create_tree() {
    Node* eight = create_node(8);
    Node* three = create_node(3);
    Node* ten = create_node(10);
    Node* one = create_node(1);
    Node* six = create_node(6);
    Node* fourteen = create_node(14);

    add_left_child(eight, three);
    add_right_child(eight, ten);

    add_left_child(three, one);
    add_right_child(three, six);

    add_right_child(ten, fourteen);

    return eight;
}

// Preorder Traversal
void preOrder(Node* node) {
    if (node == NULL) return;

    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

// Insert into BST
Node* bst_insert(Node* root, int item) {
    Node* newnode = create_node(item);
    Node *parent_node = NULL, *current_node = root;

    if (root == NULL) {
        return newnode;
    }

    while (current_node != NULL) {
        parent_node = current_node;
        if (newnode->data < current_node->data) {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
    }

    if (newnode->data < parent_node->data) {
        add_left_child(parent_node, newnode);
    } else {
        add_right_child(parent_node, newnode);
    }
    return root;
}

int main() {
    Node* root = create_tree();

    printf("Preorder Traversal Before Insertion:\n");
    preOrder(root);

    root = bst_insert(root, 13);

    printf("\nPreorder Traversal After Insertion:\n");
    preOrder(root);

    return 0;
}
