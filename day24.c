// Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key

// Output:
// - Print the linked list elements after deletion, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// 10 20 40 50

// Explanation:
// Traverse list, find first node with key, remove it by adjusting previous node's next pointer.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, struct Node** tail, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

// Delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {
    struct Node* curr = head;
    struct Node* prev = NULL;

    // Case 1: key at head
    if (curr != NULL && curr->data == key) {
        head = curr->next;
        free(curr);
        return head;
    }

    // Case 2: search in rest
    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If key found
    if (curr != NULL) {
        prev->next = curr->next;
        free(curr);
    }

    return head;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, value, key;

    struct Node *head = NULL, *tail = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, &tail, value);
    }

    scanf("%d", &key);

    head = deleteKey(head, key);

    printList(head);

    return 0;
}