#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 //Setting Max No. Elements permitted in the Queue

//Establishing The Priority Queue
int PriorityQ[MAX];

//Keeping Track of the start and end
int FRONT = -1;
int REAR = -1;

//Check whether the Queue is Empty or not
bool isEmpty(){
    return REAR == -1;
}

//Check whether the Queue is Full or not
bool isFull(){
    return REAR == MAX - 1;
}

//Displaying The Queue
void display(){

    if(isEmpty()){
        printf("Queue is Empty!\n");
        return;
    }

    for(int i = FRONT; i <= REAR; i++)
        printf("%d <- ", PriorityQ[i]);

    printf("\n");

}

//Dequeue
void Dequeue(){

    if(isEmpty()){
        printf("Queue is Empty!\n");
        return;
    }

    REAR--;

}

//Right Shift
void UnBoundedRshift(int a[], int n, int start){

    for(int i = n - 2; i >= start; i--)
        a[i + 1] = a[i];

}

//Enqueue
void Enqueue(int x){

    if(isFull()){
        printf("Queue is Full!\n");
        return;
    }

    if(isEmpty()){

        FRONT++;
        REAR++;

        PriorityQ[REAR] = x;

    } else if(x < PriorityQ[FRONT]){

        UnBoundedRshift(PriorityQ, MAX, FRONT);

        REAR++;

        PriorityQ[FRONT] = x;

    } else if(x > PriorityQ[REAR]){

        REAR++;

        PriorityQ[REAR] = x;

    } else {

        int i = FRONT + 1;

        while(x > PriorityQ[i]) i++;

        UnBoundedRshift(PriorityQ, MAX, i);

        REAR++;

        PriorityQ[i] = x;

    }

}

int main(int argc, char *argv[]){

    display();

    Enqueue(3);
    display();

    Enqueue(5);
    display();

    Enqueue(9);
    display();

    Enqueue(1);
    display();

    Enqueue(12);
    display();

    Dequeue();
    display();

    Dequeue();
    display();

    Dequeue();
    display();

    Dequeue();
    display();

    Dequeue();
    display();


    return 0;
}
