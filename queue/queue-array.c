#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue{
    int front, rear;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity){
    //dynamic memory allocation for queue and its array
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isEmpty(struct Queue* queue){
    return queue->front == -1 || queue->front > queue->rear;
}

int isFull(struct Queue* queue){
    return queue->rear == queue->capacity-1;
}

void enqueue(struct Queue* queue, int item){
    if(isFull(queue)){
        printf("Queue overflow!!!\n");
        return; //queue overflow handled
    }
    if(queue->front == -1){
        queue->front++;
    }
    queue->array[++queue->rear] = item;
}

int dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue underflow!!!\n");
        return INT_MIN; //queue underflow handled
    }
    return queue->array[queue->front++];
}

int main(){
    struct Queue* queue = createQueue(3);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    enqueue(queue, 4);
    printf("%d dequeued from the queue.\n", dequeue(queue));
    printf("%d dequeued from the queue.\n", dequeue(queue));
    dequeue(queue);
    dequeue(queue);

    free(queue->array);
    free(queue);

    return 0;
}