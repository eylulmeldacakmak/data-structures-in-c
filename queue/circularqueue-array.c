#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity){
    //dynamic memory allocation for queue and its array
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = queue->capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isEmpty(struct Queue* queue){
    return (queue->size == 0);
}

int isFull(struct Queue* queue){
    return (queue->size == queue->capacity);
}

void enqueue(struct Queue* queue, int item){
    if(isFull(queue)){
        printf("Queue overflow!!!\n");
        return; //queue overflow handled
    }
    queue->rear = (queue->rear+1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size += 1;
}

int dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue underflow!!!\n");
        return INT_MIN; //queue underflow handled
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front+1) % queue->capacity;
    queue->size -= 1;
    return item;
}

int main(){
    struct Queue* queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    
    printf("%d dequeued from the queue.\n", dequeue(queue));
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);
    enqueue(queue, 70);

    while(!isEmpty(queue)){
        printf("%d ", dequeue(queue));
    }
    printf("\n");
    free(queue->array);
    free(queue);
    
    return 0;
}
