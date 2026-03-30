#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, struct Node** tail, int c, int e) {
    struct Node* newNode = createNode(c, e);

    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

// Print polynomial
void printPolynomial(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        } 
        else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        } 
        else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        if (temp->next != NULL) {
            printf(" + ");
        }

        temp = temp->next;
    }
}

int main() {
    int n, c, e;
    struct Node *head = NULL, *tail = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        insertEnd(&head, &tail, c, e);
    }

    printPolynomial(head);

    return 0;
}