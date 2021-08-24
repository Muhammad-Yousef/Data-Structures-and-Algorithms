#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5 //Setting The Size of the Queue

//Establishing The Queue
typedef struct {

    int elements[SIZE];
    int FRONT;
    int REAR;

} Queue;

//Initializing The Queue
void initQueue(Queue *q){
    q -> FRONT = q -> REAR = -1;
}

//Check whether the Queue is Empty or not
bool isEmpty(Queue *q){
    return q -> FRONT == -1 && q -> REAR == -1;
}

//Check whether the Queue is Full or not
bool isFull(Queue *q){
    return q -> FRONT == q -> REAR + 1 || q -> FRONT == 0 && q -> REAR == SIZE - 1;
}

//Display
void display(Queue *q){

    if(isEmpty(q)){
        printf("Queue is Empty!\n");
        return;
    }

    for(int i = 0; i < SIZE; i++)
        if(i != SIZE - 1)
            printf("%d <- ", q -> elements[i]);
        else
            printf("%d", q -> elements[i]);

    printf("\n");

}

//Enqueue
void Enqueue(Queue *q, int x){

    printf("\nBefore Enqueue: FRONT = %d and REAR = %d\n", q -> FRONT, q -> REAR);

    if(isFull(q)){
        printf("Queue is Full!\n");
        return;
    }

    if(isEmpty(q)){

        q -> FRONT++;
        q -> REAR++;

        q -> elements[q -> FRONT] = x;

    } else {

        q -> REAR = (q -> REAR + 1) % SIZE;
        q -> elements[q -> REAR] = x;

    }

    printf("After Enqueue: FRONT = %d and REAR = %d\n", q -> FRONT, q -> REAR);

}

//Dequeue
void Dequeue(Queue *q){

    printf("\nBefore Dequeue: FRONT = %d and REAR = %d\n", q -> FRONT, q -> REAR);

    if(isEmpty(q)){
        printf("Queue is Empty!\n");
        return;
    }

    if(q -> FRONT == q -> REAR){

        q -> elements[(q -> FRONT)++] = 0;
        q -> FRONT = -1;
        q -> REAR = -1;

    } else {

        q -> elements[(q -> FRONT)++] = 0;

    }

    printf("After Dequeue: FRONT = %d and REAR = %d\n", q -> FRONT, q -> REAR);

}

int main(int argc, char *argv[]){

    Queue *q = (Queue*) malloc(sizeof(Queue));

    initQueue(q);

    display(q);

    Enqueue(q, 1);
    display(q);

    Enqueue(q, 2);
    display(q);

    Enqueue(q, 3);
    display(q);

    Enqueue(q, 4);
    display(q);

    Enqueue(q, 5);
    display(q);

    Enqueue(q, 6); //OverFlow

    printf("\n");

    Dequeue(q);
    display(q);

    Dequeue(q);
    display(q);

    Enqueue(q, 6);
    display(q);

    Enqueue(q, 7);
    display(q);

    Enqueue(q, 8);
    display(q);

    return 0;
}
