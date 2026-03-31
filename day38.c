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
#define MAX 10000

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} MyDeque;

MyDeque* dequeCreate() {
    MyDeque* obj = (MyDeque*)malloc(sizeof(MyDeque));
    obj->front = 0;
    obj->rear = -1;
    obj->size = 0;
    return obj;
}

void push_front(MyDeque* obj, int value) {
    if (obj->size == MAX) return;
    obj->front = (obj->front - 1 + MAX) % MAX;
    obj->arr[obj->front] = value;
    obj->size++;
    if (obj->size == 1) obj->rear = obj->front;
}

void push_back(MyDeque* obj, int value) {
    if (obj->size == MAX) return;
    obj->rear = (obj->rear + 1) % MAX;
    obj->arr[obj->rear] = value;
    obj->size++;
}

void pop_front(MyDeque* obj) {
    if (obj->size == 0) return;
    obj->front = (obj->front + 1) % MAX;
    obj->size--;
}

void pop_back(MyDeque* obj) {
    if (obj->size == 0) return;
    obj->rear = (obj->rear - 1 + MAX) % MAX;
    obj->size--;
}

int front(MyDeque* obj) {
    if (obj->size == 0) return -1;
    return obj->arr[obj->front];
}

int back(MyDeque* obj) {
    if (obj->size == 0) return -1;
    return obj->arr[obj->rear];
}

bool empty(MyDeque* obj) {
    return obj->size == 0;
}

int size(MyDeque* obj) {
    return obj->size;
}

void clear(MyDeque* obj) {
    obj->front = 0;
    obj->rear = -1;
    obj->size = 0;
}

void reverse(MyDeque* obj) {
    int i = obj->front;
    int j = obj->rear;
    for (int k = 0; k < obj->size / 2; k++) {
        int temp = obj->arr[i];
        obj->arr[i] = obj->arr[j];
        obj->arr[j] = temp;
        i = (i + 1) % MAX;
        j = (j - 1 + MAX) % MAX;
    }
}

void dequeFree(MyDeque* obj) {
    free(obj);
}