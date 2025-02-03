
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack_arr[MAX];
char infix_arr[MAX];
char postfix_arr[MAX];
int top = -1;

int is_empty() {
    return (top == -1);
}

int is_full() {
    return (top == MAX - 1);
}

void push(char data) {
    if (is_full()) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack_arr[++top] = data;
}

char pop() {
    if (is_empty()) {
        printf("Stack Underflow!\n");
        return '\0';  // Return null character instead of undefined behavior
    }
    return stack_arr[top--];
}

int precedence(char symbol) {
    switch (symbol) {
        case '^': return 5;
        case '*':
        case '/': return 4;
        case '+':
        case '-': return 3;
        default: return 2;
    }
}

int is_space(char symbol) {
    return (symbol == ' ' || symbol == '\t');
}

void infix_to_postfix() {
    printf("Enter an infix expression: \n");
    fgets(infix_arr, MAX, stdin);

    int i, j = 0;
    char value, symbol;

    for (i = 0; i < strlen(infix_arr); i++) {
        symbol = infix_arr[i];

        if (!is_space(symbol)) {
            switch (symbol) {
                case '(':
                    push(symbol);
                    break;

                case ')':
                    while ((value = pop()) != '(') {
                        postfix_arr[j++] = value;
                    }
                    break;

                case '+':
                case '-':
                case '/':
                case '*':
                case '^':
                    while (!is_empty() && precedence(stack_arr[top]) >= precedence(symbol)) {
                        postfix_arr[j++] = pop();
                    }
                    push(symbol);
                    break;

                default:
                    postfix_arr[j++] = symbol;
            }
        }
    }

    while (!is_empty()) {
        postfix_arr[j++] = pop();
    }

    postfix_arr[j] = '\0';
}

void print_postfix_arr() {
    printf("Postfix Expression: %s\n", postfix_arr);
}

int main() {
    infix_to_postfix();
    print_postfix_arr();
    return 0;
}
