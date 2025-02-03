#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 8
int top = -1;
int stack_arr[MAX_SIZE];

int is_empty() {
    return top == -1;
}

int is_full() {
    return top == MAX_SIZE - 1;
}

int peek() {
    if (is_empty()) {
        printf("STACK UNDERFLOW!\n");
        return -1;
    }
    return stack_arr[top];
}

void push(int data) {
    if (is_full()) {
        printf("STACK OVERFLOW!\n");
        return;
    }
    stack_arr[++top] = data;
}

int pop() {
    if (is_empty()) {
        printf("STACK UNDERFLOW!\n");
        return -1;
    }
    return stack_arr[top--];
}

void show() {
    if (is_empty()) {
        printf("STACK UNDERFLOW!\n");
        return;
    }
    printf("\nThe elements of the stack: \n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack_arr[i]);
    }
    printf("\n");
}

int top_most() {
    if (is_empty()) {
        printf("STACK UNDERFLOW!\n");
        return -1;
    }
    return stack_arr[top];
}

int size() {
    return top + 1;
}

int main() {
    int choice, data;
    while (1) {
        printf("\nChoose an operation: \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if Empty\n");
        printf("4. Check if Full\n");
        printf("5. Peek\n");
        printf("6. Show\n");
        printf("7. Stack Size\n");
        printf("8. Top Most Element\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 9) {
            exit(0);
        } else if (choice == 1) {
            printf("Enter element to push: ");
            scanf("%d", &data);
            push(data);
        } else if (choice == 2) {
            printf("Popped value: %d\n", pop());
        } else if (choice == 3) {
            printf(is_empty() ? "STACK IS EMPTY!\n" : "STACK IS NOT EMPTY!\n");
        } else if (choice == 4) {
            printf(is_full() ? "STACK IS FULL!\n" : "STACK IS NOT FULL!\n");
        } else if (choice == 5) {
            printf("Peek value: %d\n", peek());
        } else if (choice == 6) {
            show();
        } else if (choice == 7) {
            printf("Stack size: %d\n", size());
        } else if (choice == 8) {
            printf("Top most element: %d\n", top_most());
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

