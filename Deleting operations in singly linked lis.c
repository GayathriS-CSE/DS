#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list from an array of integers
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

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete the first node of the linked list
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete first element.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;  // Move the head to the next node
    free(temp);  // Free the memory of the old head node
}

// Function to delete the last node of the linked list
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete last element.\n");
        return;
    }
    // If there is only one node
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);  // Free the last node
    temp->next = NULL;  // Set the second last node's next pointer to NULL
}

// Function to delete a specified element from the list
void deleteElement(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty, cannot delete element.\n");
        return;
    }
    // If the element to be deleted is the head node
    if ((*head)->data == value) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        if (temp->next->data == value) {
            struct Node* toDelete = temp->next;
            temp->next = temp->next->next;
            free(toDelete);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the list.\n", value);
}

// Driver code to test the implementation
int main() {
    struct Node* head = NULL;
    
    // Create the linked list
    int arr[] = {10, 20, 30, 40, 50};
    createList(&head, arr, 5);
    
    printf("Initial Linked List:\n");
    displayList(head);
    
    // Deleting the first element
    printf("\nAfter deleting the first element:\n");
    deleteFirst(&head);
    displayList(head);
    
    // Deleting the last element
    printf("\nAfter deleting the last element:\n");
    deleteLast(&head);
    displayList(head);
    
    // Deleting a specified element
    printf("\nAfter deleting element 30:\n");
    deleteElement(&head, 30);
    displayList(head);
    
    // Trying to delete a non-existent element
    printf("\nTrying to delete element 100 (which doesn't exist):\n");
    deleteElement(&head, 100);
    displayList(head);

    return 0;
}
