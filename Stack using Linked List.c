#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
int data;
struct Node *next;
};

void push(int x,struct Node* *top){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=*top;
    *top=newnode;
}

void pop(struct Node* *top){
    if(*top==NULL){
        printf("Empty\n");
    }
    struct Node *temp=*top;
    *top=(*top)->next;
    free(temp);
}

void peek(struct Node* top) {
    if (top == NULL) {
        printf("Empty\n");
    } 
    else {
        printf("%d \n", top->data);
    }
}

void display(struct Node* top) {
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main(){
    int data,choice;
    struct Node *top=NULL;
    while(true){
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data:");
                scanf("%d",&data);
                push(data,&top);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                display(top);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
        }
    }
}
