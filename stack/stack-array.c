#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack{
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity){
    //dynamic memory allocation for stack and its array
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack){
    return stack->top == stack->capacity-1;
}

int isEmpty(struct Stack* stack){
    return stack->top == -1;
}

void push(struct Stack* stack, int item){
    if(isFull(stack)){
        /*replacing the stack array with a larger one*/
        int* array2 = (int*)malloc(stack->capacity*2 * sizeof(int));
        for(int i=0; i<stack->capacity; i++){
            array2[i] = stack->array[i];
        }
        free(stack->array);
        stack->array = array2;
        stack->capacity *= 2;
    }
    stack->array[++stack->top] = item;
    //increase top and add the item
}

int pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack underflow!!!\n");
        return INT_MIN; //stack underflow handled
    }
    return stack->array[stack->top--];
    //return top value and decrease top
}

int peek(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack underflow!!!\n");
        return INT_MIN; //stack underflow handled
    }
    return stack->array[stack->top];
}

int main(){
    struct Stack* stack = createStack(2);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    
    printf("%d popped from the stack.\n", pop(stack));
    printf("Top element is %d\n", peek(stack));

    pop(stack);
    pop(stack);
    pop(stack);

    free(stack->array);
    free(stack);

    return 0;
}