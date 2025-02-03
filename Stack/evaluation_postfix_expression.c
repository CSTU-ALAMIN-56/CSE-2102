#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 100

int stack_arr[MAX];
char postfix_arr[MAX];
int top = -1;

int is_empty() {
    return (top == -1);
}

int is_full() {
    return (top == MAX - 1);
}

void push(int value) {
    if (is_full()) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack_arr[++top] = value;
}

int pop() {
    if (is_empty()) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack_arr[top--];
}

int is_space(char c) {
    return (c == ' ' || c == '\t');
}

int evaluate_postfix_expr() {
    int i, a, b;

    for (i = 0; i < strlen(postfix_arr); i++) {
        if (!is_space(postfix_arr[i])) {
            if (postfix_arr[i] >= '0' && postfix_arr[i] <= '9') {
                push(postfix_arr[i] - '0');
            } else {
                a = pop();
                b = pop();
                switch (postfix_arr[i]) {
                    case '+': push(b + a); break;
                    case '-': push(b - a); break;
                    case '*': push(b * a); break;
                    case '/': push(b / a); break;
                    case '^': push(pow(b, a)); break;
                    default:
                        printf("Invalid operator encountered: %c\n", postfix_arr[i]);
                        exit(1);
                }
            }
        }
    }
    return pop();
}

int main() {
    printf("Enter a postfix expression (all characters separated by space):\n");
    fgets(postfix_arr, MAX, stdin);

    int result = evaluate_postfix_expr();
    printf("Result: %d\n", result);

    return 0;
}

