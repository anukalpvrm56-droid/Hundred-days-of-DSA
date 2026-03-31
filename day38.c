// Problem: Deque (Double-Ended Queue)

// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

// Common Operations:
// 1. push_front(value): Insert an element at the front of the deque.
// 2. push_back(value): Insert an element at the rear of the deque.
// 3. pop_front(): Remove an element from the front of the deque.
// 4. pop_back(): Remove an element from the rear of the deque.
// 5. front(): Return the front element of the deque.
// 6. back(): Return the rear element of the deque.
// 7. empty(): Check whether the deque is empty.
// 8. size(): Return the number of elements in the deque.

// Additional Operations:
// - clear(): Remove all elements from the deque.
// - erase(): Remove one or more elements from the deque.
// - swap(): Swap contents of two deques.
// - emplace_front(): Insert an element at the front without copying.
// - emplace_back(): Insert an element at the rear without copying.
// - resize(): Change the size of the deque.
// - assign(): Replace elements with new values.
// - reverse(): Reverse the order of elements.
// - sort(): Sort the elements in ascending order.

// Time Complexity:
// - push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
// - clear, erase, resize, assign, reverse: O(n)
// - sort: O(n log n)

// Input:
// - Sequence of deque operations with values (if applicable)

// Output:
// - Results of operations such as front, back, size, or the final state of the deque after all operations
#include <stdio.h>
#include <string.h>

#define MAX 10000

int dq[MAX];
int front = 0, rear = -1, size = 0;

void push_front(int x) {
    if (size == MAX) return;
    front = (front - 1 + MAX) % MAX;
    dq[front] = x;
    size++;
    if (size == 1) rear = front;
}

void push_back(int x) {
    if (size == MAX) return;
    rear = (rear + 1) % MAX;
    dq[rear] = x;
    size++;
}

void pop_front() {
    if (size == 0) return;
    front = (front + 1) % MAX;
    size--;
}

void pop_back() {
    if (size == 0) return;
    rear = (rear - 1 + MAX) % MAX;
    size--;
}

int get_front() {
    if (size == 0) return -1;
    return dq[front];
}

int get_back() {
    if (size == 0) return -1;
    return dq[rear];
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    while (n--) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        } else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        } else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        } else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        } else if (strcmp(op, "front") == 0) {
            printf("%d\n", get_front());
        } else if (strcmp(op, "back") == 0) {
            printf("%d\n", get_back());
        }
    }

    return 0;
}