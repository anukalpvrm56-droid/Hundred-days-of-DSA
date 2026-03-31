#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** top, int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = *top;
    *top = temp;
}

int pop(Node** top) {
    if (*top == NULL) return 0;
    Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int evaluatePostfix(char* expr) {
    Node* stack = NULL;
    char* token = strtok(expr, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || 
           (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        } else {
            int b = pop(&stack);
            int a = pop(&stack);

            if (token[0] == '+') push(&stack, a + b);
            else if (token[0] == '-') push(&stack, a - b);
            else if (token[0] == '*') push(&stack, a * b);
            else if (token[0] == '/') push(&stack, a / b);
        }
        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

int main() {
    char expr[1000];
    fgets(expr, sizeof(expr), stdin);

    printf("%d\n", evaluatePostfix(expr));
    return 0;
}