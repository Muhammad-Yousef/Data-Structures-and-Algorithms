#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5 // Setting The Size of the Queue

int counter = 0; //Counting No. elements in the Queue

//Establishing The Queue
typedef struct {

    int elements[SIZE];
    int FRONT;
    int REAR;

} Queue;

//Initializating The Queue
void initQueue(Queue *q){
    q -> FRONT = q -> REAR = -1;
}

//Check whether the Queue is Empty or not
bool isEmpty(Queue *q){
    return q -> FRONT == -1;
}

//Check whether the Queue is Full or not
bool isFull(Queue *q){
    return q -> REAR == (SIZE - 1);
}

//Display Queue
void display(Queue *q){

    if(isEmpty(q)){

        printf("Queue is Empty!\n");
        return;

    }

    for(int i = q -> FRONT; i < q -> REAR + 1; i++)
        printf("%d -> ", q -> elements[i]);

    printf("\n");

}

//Peek
void peek(Queue *q){

    if(isEmpty(q)){

        printf("Queue is Empty!\n");
        return;

    }

    printf("%d\n", q -> elements[q -> FRONT]);

}

//Enqueue
void Enqueue(Queue *q, int x){

    if(isFull(q)){

        printf("Queue is Full!\n");
        return;

    }

    if(isEmpty(q)){

        q -> FRONT++;
        q -> REAR++;

        q -> elements[q -> REAR] = x;

    } else {

        q -> elements[++(q -> REAR)] = x;

    }

    counter++;

}

//Dequeue
int Dequeue(Queue *q){

    if(isEmpty(q)){

        printf("Queue is Empty!\n");
        return -1;

    }

    int value;

    if(q -> FRONT != q -> REAR != SIZE - 1)
        value = q -> elements[(q -> FRONT)++];
    else {

        value = q -> elements[q -> FRONT];

        q -> FRONT = q -> REAR = -1;

    }

    counter--;

    return value;

}

int main(int argc, char *argv[]){

    Queue *Q = (Queue*) malloc(sizeof(Queue));

    initQueue(Q);

    display(Q);

    Enqueue(Q, 1);
    display(Q);

    Enqueue(Q, 2);
    display(Q);

    Enqueue(Q, 3);
    display(Q);

    Dequeue(Q);
    display(Q);

    Dequeue(Q);
    display(Q);

    Dequeue(Q);
    display(Q);

    Dequeue(Q);
    display(Q);

    Dequeue(Q);

    return 0;
}
