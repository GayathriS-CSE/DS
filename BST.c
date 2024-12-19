#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation failed");
        free(newNode);
    }
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    
    return newNode;
}

struct node* insert(struct node* root,int data){
    if(root==NULL){
        root=createNode(data);
        return root;
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

void display(struct node* root){
    if(root != NULL){
        display(root->left);
        printf("%d, ",root->data);
        display(root->right);
    }
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d, ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root){
    if(root != NULL){
        printf("%d, ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d, ",root->data);
    }
}

int main(){
    struct node* root=NULL;
    int data, choice;
    
    while(1){
        printf("\n-----MENU-----");
        printf("\n1.Insert\n2.Display\n3.In Order\n4.Pre Order\n5.Post Order");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("Enter data:");
                scanf("%d",&data);
                root = insert(root,data);
                break;
            case 2:
                printf("\nDiplaying:");
                display(root);
                break;
            case 3:
                printf("\nIn Order:");
                inorder
                (root);
                break;
            case 4:
                printf("\nPre Order:");
                preorder(root);
                break;
            case 5:
                printf("\nPost Order:");
                postorder(root);
                break;
            case 6:
                printf("\nExiting the program!!");
                return 0;
            default:
                printf("Wrong choice");
        }
    }
    return 0;
}



