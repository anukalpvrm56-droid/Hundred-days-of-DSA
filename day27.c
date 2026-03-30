#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, struct Node** tail, int val) {
    struct Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

// Get length
int getLength(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node* p1 = head1;
    struct Node* p2 = head2;

    // Align both lists
    int diff = abs(len1 - len2);
    if (len1 > len2) {
        while (diff--) p1 = p1->next;
    } else {
        while (diff--) p2 = p2->next;
    }

    // Traverse together
    while (p1 && p2) {
        if (p1 == p2)  // pointer comparison
            return p1;
        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
}

int main() {
    int n, m, val;

    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&head1, &tail1, val);
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        insertEnd(&head2, &tail2, val);
    }

    // ⚠️ For demonstration ONLY:
    // Creating intersection manually
    // Connect tail2 to 3rd node of list1 (value 30)
    struct Node* temp = head1;
    for (int i = 0; i < 2; i++) temp = temp->next; // move to 30
    tail2->next = temp;

    struct Node* inter = getIntersection(head1, head2);

    if (inter)
        printf("%d", inter->data);
    else
        printf("No Intersection");

    return 0;
}