#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct StackNode{
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int data){
    //dynamic memory allocation
    struct StackNode* node = (struct StackNode*)malloc(sizeof(struct StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(struct StackNode* top){
    return top == NULL;
}

/*we will not create an isFull function since it cannot be full*/

void push(struct StackNode** top, int item){
    struct StackNode* newStackNode = newNode(item);
    newStackNode->next = *top;
    *top = newStackNode;
}

int pop(struct StackNode** top){
    if(isEmpty(*top)){
        printf("Stack underflow!!!\n");
        return INT_MIN; //stack underflow handled
    }
    struct StackNode* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

int peek(struct StackNode* top){
    if(isEmpty(top)){
        printf("Stack underflow!!!\n");
        return INT_MIN; //stack underflow handled
    }
    return top->data;
}

int main(){
    struct StackNode* top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printf("%d popped from the stack.\n", pop(&top));
    printf("Top element is %d\n", peek(top));

    pop(&top);
    pop(&top);
    pop(&top);

    return 0;
}