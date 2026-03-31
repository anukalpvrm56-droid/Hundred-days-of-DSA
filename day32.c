#include <stdio.h>

#define MAX 1000

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        return; // overflow ignored as per problem
    }
    stack[++top] = value;
}

// Pop operation
void pop() {
    if (top == -1) {
        return; // underflow ignored
    }
    top--;
}

// Display stack from top to bottom
void display() {
    if (top == -1) return;

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    // push elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    scanf("%d", &m);

    // pop m times
    for (int i = 0; i < m; i++) {
        pop();
    }

    // display remaining stack
    display();

    return 0;
}