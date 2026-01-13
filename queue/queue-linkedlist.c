#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct QueueNode{
    int data;
    struct QueueNode* next;
};

struct Queue{
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct QueueNode* newNode(int data){
    //dynamic memory allocation for each node
    struct QueueNode* node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Queue* createQueue(){
    //dynamic memory allocation for queue
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int item){
    struct QueueNode* node = newNode(item);
    /*if queue is empty, then the node is both front and rear*/
    if(queue->rear == NULL){
        queue->front = node;
        queue->rear = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
}

void dequeue(struct Queue* queue){
    /*if queue is empty*/
    if(queue->front == NULL){
        printf("Queue underflow!!!\n");
        return;
    }
    struct QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    /*if front becomes NULL, then change rear to NULL too*/
    if(queue->front == NULL){
        queue->rear = NULL;
    }
    free(temp);
}

int main(){
    struct Queue* queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    enqueue(queue, 10);
    enqueue(queue, 20);

    printf("Queue front: %d\n", queue->front->data);
    printf("Queue rear: %d\n", queue->rear->data);

    while(queue->front != NULL){
        dequeue(queue);
    }
    free(queue);

    return 0;
}