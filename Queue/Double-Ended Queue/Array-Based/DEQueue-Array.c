#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5 //Setting Maximum size of the Queue

//Establishing Queue
typedef struct {

    int elements[SIZE];
    int FRONT;
    int REAR;

} Queue;

//Initializing
void initQueue(Queue *q){
    q -> FRONT = -1;
    q -> REAR = -1;
}

//Check whether the Queue is Empty or not
bool isEmpty(Queue *q){
    return q -> FRONT == -1;
}

//Check whether the Queue is Full or not
bool isFull(Queue *q){
    return q -> REAR == q -> FRONT - 1 || q -> FRONT == 0 && q -> REAR == SIZE - 1;
}

//Displaying
void display(Queue *q){

    if(isEmpty(q)){
        printf("Queue is Empty!\n");
        return;
    }

    for(int i = 0; i < SIZE; i++)
        printf("%d <- ", q -> elements[i]);

    printf("\n");

}

//Insert At REAR
void insertREAR(Queue *q, int x){

    if(isFull(q)){
        printf("Queue is Full!\n");
        return;
    }

    printf("\nBefore Inserting At REAR: FRONT = %d and REAR = %d", q -> FRONT, q -> REAR);

    if(isEmpty(q)){

        q -> FRONT++;

        q -> elements[++(q -> REAR)] = x;

    } else if(q -> REAR == SIZE - 1){

        q -> REAR = 0;
        q -> elements[q -> REAR] = x;

    } else {

        q -> elements[++(q -> REAR)] = x;

    }

    printf("After Inserting At REAR: FRONT = %d and REAR = %d\n", q -> FRONT, q -> REAR);

}

//Insert AT FRONT
void insertFRONT(Queue *q, int x) {

    if (isFull(q)) {
        printf("Queue is Full!\n");
        return;
    }

    printf("\nBefore Inserting At FRONT: FRONT = %d and REAR = %d\n", q->FRONT, q->REAR);

    if (isEmpty(q)) {

        q->FRONT++;
        q->REAR++;

        q->elements[q->FRONT] = x;

    } else if (q->FRONT == 0) {

        q->FRONT = SIZE - 1;

        q->elements[q->FRONT] = x;

    } else {

        q->elements[--(q->FRONT)] = x;

    }

    printf("After Inserting At FRONT: FRONT = %d and REAR = %d\n", q -> FRONT, q -> REAR);

}

//Delete From FRONT
void deleteFRONT(Queue *q){

    if(isEmpty(q)){
        printf("Queue is Empty!\n");
        return;
    }

    printf("\nBefore Deleting From FRONT: FRONT = %d and REAR = %d\n", q -> FRONT, q -> REAR);

    q -> elements[q -> FRONT] = 0;

    if(q -> FRONT == q -> REAR){

        q -> FRONT = -1;
        q -> REAR = -1;

    } else if (q -> FRONT == SIZE - 1){

        q -> FRONT = 0;

    } else {

        q -> FRONT++;

    }

    printf("After Deleting From REAR: FRONT = %d and REAR = %d\n", q -> FRONT, q -> REAR);

}

//Delete Fron REAR
void deleteREAR(Queue *q) {

    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("\nBefore Deleting From REAR: FRONT = %d and REAR = %d\n", q->FRONT, q->REAR);

    q -> elements[q -> REAR] = 0;

    if (q -> FRONT == q -> REAR) {

        q -> FRONT = -1;
        q -> REAR = -1;

    } else if (q -> REAR == 0) {

        q -> REAR = SIZE - 1;

    } else {

        q -> REAR--;

    }

    printf("After Deleting From REAR: FRONT = %d and REAR = %d\n", q->FRONT, q->REAR);

}

int main(int argc, char *argv[]) {

    Queue *q = (Queue *) malloc(sizeof(Queue));

    initQueue(q);

    display(q);

    insertREAR(q, 1);
    display(q);

    insertREAR(q, 2);
    display(q);

    insertREAR(q, 3);
    display(q);

    insertREAR(q, 4);
    display(q);

    insertREAR(q, 5);
    display(q);

    //insertREAR(q, 6); //OverFlow

    deleteREAR(q);
    display(q);

    deleteREAR(q);
    display(q);

    insertFRONT(q, 4);
    display(q);

    insertFRONT(q, 5);
    display(q);

    //insertFRONT(q, 6); //OverFlow

    deleteFRONT(q);
    display(q);

    deleteFRONT(q);
    display(q);

    deleteFRONT(q);
    display(q);

    deleteFRONT(q);
    display(q);

    deleteFRONT(q);
    display(q);

    return 0;
}
