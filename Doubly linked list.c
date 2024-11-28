#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void create_list(struct Node** head, int data[], int size) {
    struct Node* new_node;
    struct Node* temp = NULL;

    for (int i = 0; i < size; i++) {
        new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data[i];
        new_node->next = NULL;
        new_node->prev = NULL;

        if (*head == NULL) {
            *head = new_node;
        } else {
            temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
    }
}

void insert_left(struct Node** head, int target_value, int new_value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    new_node->data = new_value;
    new_node->prev = NULL;
    new_node->next = NULL;

    while (temp != NULL) {
        if (temp->data == target_value) {
            new_node->next = temp;
            new_node->prev = temp->prev;

            if (temp->prev != NULL) {
                temp->prev->next = new_node;
            } else {
                *head = new_node;  // New node becomes the head if target is at the start
            }

            temp->prev = new_node;
            return;
        }
        temp = temp->next;
    }
    printf("Node with value %d not found.\n", target_value);
}

void delete_node(struct Node** head, int value) {
    struct Node* temp = *head;

    while (temp != NULL) {
        if (temp->data == value) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                *head = temp->next;  // Update head if the node to delete is at the beginning
            }

            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }

            free(temp);
            printf("Node with value %d deleted.\n", value);
            return;
        }
        temp = temp->next;
    }
    printf("Node with value %d not found.\n", value);
}

void display_list(struct Node* head) {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, size, target, new_value, delete_value;
    
    int *data = NULL;

    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Create a Doubly Linked List\n");
        printf("2. Insert a Node to the Left of a Specific Node\n");
        printf("3. Delete a Node Based on Value\n");
        printf("4. Display the List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements in the list: ");
                scanf("%d", &size);
                
                data = (int*)malloc(size * sizeof(int));

                if (data == NULL) {
                    printf("Memory allocation failed!\n");
                    return 1;
                }

                printf("Enter the elements:\n");
                for (int i = 0; i < size; i++) {
                    scanf("%d", &data[i]);
                }
                create_list(&head, data, size);
                printf("\nDoubly Linked List created.\n");
                printf("\nList: ");
                display_list(head);
                break;

            case 2:
                printf("Enter the value of the node you want to insert to the left of: ");
                scanf("%d", &target);
                printf("Enter the value of the new node to insert: ");
                scanf("%d", &new_value);
                insert_left(&head, target, new_value);
                break;

            case 3:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &delete_value);
                delete_node(&head, delete_value);
                break;

            case 4:
                printf("\nList: ");
                display_list(head);
                break;

            case 5:
                printf("Exiting the program...\n");
                free(data);  // Free the dynamically allocated memory
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
