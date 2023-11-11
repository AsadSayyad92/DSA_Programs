3. Write a menu driven program to implement list ADT using DOUBLE LINKEDLIST and perform the following operations

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Function to create a doubly linked list
void create() {
    int value;
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
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
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

// Function to insert at the end of the list
void insertAtEnd() {
    int value;
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
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
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node* temp = head;
        for (i = 1; i < pos - 1; i++) {
            if (temp->next == NULL) {
                printf("Invalid position. Inserting at the end.\n");
                break;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

// Function to delete at the beginning of the list
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

// Function to delete at the end of the list
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    }
    free(temp);
}

// Function to delete at a specific location
void deleteAtLocation(int pos) {
    int i;
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    for (i = 1; i < pos; i++) {
        if (temp->next == NULL) {
            printf("Invalid position. Nothing to delete.\n");
            return;
        }
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Function to display the doubly linked list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for a value in the list
void search(int value) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Value %d not found in the list.\n");
}

// Function to count the number of nodes in the list
int count() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to reverse the doubly linked list
void reverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    struct Node* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    head = temp->prev;
}

int main() {
    int choice, position, value;
    while (1) {
        printf("\nDoubly Linked List Operations:\n");
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
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insertAtBeginning();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertAtLocation(position);
                break;
            case 5:
                deleteAtBeginning();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtLocation(position);
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 10:
                printf("Number of nodes in the list: %d\n", count());
                break;
            case 11:
                reverse();
                printf("List has been reversed.\n");
                break;
            case 12:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}