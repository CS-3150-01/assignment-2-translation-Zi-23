#include <stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

void addNode(struct Node* head, int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    *head = newNode;
}

void display(struct Node* node){
    printf("Nodes of singly linked list: ");
    
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;

    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    
    display(head);

    return 0; 
}