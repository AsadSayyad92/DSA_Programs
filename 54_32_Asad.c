#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Function to create a circular doubly linked list
void create() {
    int value;
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert: ");
    scanf("%d", &value);
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        struct Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
    }
}

// Function to insert at the beginning of the list
void insertAtBeginning() {
    int value;
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert: ");
    scanf("%d", &value);
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        struct Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
}

// Function to insert at the end of the list
void insertAtEnd() {
    int value;
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert: ");
    scanf("%d", &value);
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        struct Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
    }
}

// Function to insert at a specific location
void insertAtLocation(int pos) {
    int value, i;
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert: ");
    scanf("%d", &value);
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        struct Node* temp = head;
        for (i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

// Function to delete at the beginning of the list
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    } else if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* tail = head->prev;
        struct Node* newHead = head->next;
        newHead->prev = tail;
        tail->next = newHead;
        free(head);
        head = newHead;
    }
}

// Function to delete at the end of the list
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    } else if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* tail = head->prev;
        struct Node* newTail = tail->prev;
        newTail->next = head;
        head->prev = newTail;
        free(tail);
    }
}

// Function to delete at a specific location
void deleteAtLocation(int pos) {
    int i;
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    } else if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        for (i = 1; i < pos; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

// Function to display the circular doubly linked list
void display() {
    struct Node* temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("Head\n");
}

// Function to search for a value in the list
void search(int value) {
    struct Node* temp;
    int position = 1;
    temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    do {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != head);
    printf("Value %d not found in the list.\n");
}

// Function to count the number of nodes in the list
int count() {
    struct Node* temp;
    int count = 0;
    if (head == NULL) {
        return 0;
    }
    temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Function to reverse the circular doubly linked list
void reverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    struct Node* temp = NULL;
    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != head);
    head = head->prev;
}

int main() {
    int choice, position, value;
    while (1) {
        printf("\nCircular Doubly Linked List Operations:\n");
        printf("1. CREATE\n");
        printf("2. INSERT AT BEGINNING\n");
        printf("3. INSERT AT END\n");
        printf("4. INSERT AT LOCATION\n");
        printf("5. DELETE AT BEGINNING\n");
        printf("6. DELETE AT END\n");
        printf("7. DELETE AT LOCATION\n");
        printf("8. DISPLAY\n");
        printf("9. SEARCH\n");
        printf("10. COUNT\n");
        printf("11. REVERSE\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
