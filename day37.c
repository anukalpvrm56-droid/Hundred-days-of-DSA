// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20
#include <stdio.h>
#include <string.h>

#define MAX 1000

int pq[MAX];
int size = 0;

void insert(int x) {
    int i = size++;
    while (i > 0 && pq[(i - 1) / 2] > x) {
        pq[i] = pq[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq[i] = x;
}

int deleteMin() {
    if (size == 0) return -1;

    int root = pq[0];
    int last = pq[--size];

    int i = 0;
    while (2 * i + 1 < size) {
        int child = 2 * i + 1;
        if (child + 1 < size && pq[child + 1] < pq[child])
            child++;

        if (last <= pq[child]) break;

        pq[i] = pq[child];
        i = child;
    }
    pq[i] = last;

    return root;
}

int peek() {
    if (size == 0) return -1;
    return pq[0];
}

int main() {
    int n, x;
    char op[10];

    scanf("%d", &n);

    while (n--) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            printf("%d\n", deleteMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}