#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void printList(Node* node){
    Node* temp = node;

    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(Node** head, int newData){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    //Case 1 : List is empty
    if(*head == NULL || (*head)->data >= newData){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    //Case 2 : List is not empty
    Node* current = *head;
    while(current->next != NULL && current->next->data <= newData){
    current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    
}

void deleteNode(Node** head, int value){
    // Case 1 : If list is empty
    if (*head == NULL){
        printf("The list is empty!!!\n");
        return;
    }

    //Case 2 : List is not empty
    //Case 2.1 : If we want to delete head
    Node* current = *head;
    if(value == (*head)->data){
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    while(current->next != NULL && current->next->data != value){
        current = current->next;
    }
    
    Node* willbedeleted = current->next;

    if(current->next == NULL){
        printf("The number is not in the list\n");
        return;
    }

    current->next = current->next->next;
    free(willbedeleted);
}

int main(){
    Node* head = NULL;
    
    //Node* tail = NULL;
    /*
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = 2;
    node->next = NULL;
    head = node;
    tail = node;

    Node* secondNode = (Node*)malloc(sizeof(Node));
    secondNode->data = 1;
    //secondNode->next = head;
    //secondNode->next = tail;
    secondNode->next = node;
    head = secondNode;
    */

    insertNode(&head, 5);
    insertNode(&head, 1);
    insertNode(&head, 3);
    insertNode(&head, 7);
    insertNode(&head, 2);

    printf("List: ");
    printList(head);

    deleteNode(&head, 1);
    printf("Deleting the head node: ");
    printList(head);

    deleteNode(&head, 5);
    printf("Deleting a middle node: ");
    printList(head);

    deleteNode(&head, 7);
    printf("Deleting the tail node: ");
    printList(head);

    return 0;
}