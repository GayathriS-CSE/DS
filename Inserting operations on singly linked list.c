#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list from an array
void createList(struct Node** head, int arr[], int n) {
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        
        if (*head == NULL) {
            *head = newNode;  // First node becomes the head
        } else {
            struct Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;  // Append to the end
        }
    }
}

// Function to insert a node at the first position
void insertAtFirst(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;

    // If inserting at the first position
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse the list to find the position
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is greater than the length of the list\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int arr[] = {10, 20, 30, 40};  // Initial data for the linked list

    // Create the linked list
    createList(&head, arr, sizeof(arr) / sizeof(arr[0]));
    printf("Initial Linked List: \n");
    displayList(head);

    // Insert a node at the first position
    insertAtFirst(&head, 5);
    printf("\nLinked List after inserting 5 at the beginning: \n");
    displayList(head);

    // Insert a node at the end
    insertAtEnd(&head, 50);
    printf("\nLinked List after inserting 50 at the end: \n");
    displayList(head);

    // Insert a node at a specific position (e.g., position 3)
    insertAtPosition(&head, 25, 3);
    printf("\nLinked List after inserting 25 at position 3: \n");
    displayList(head);

    return 0;
}
