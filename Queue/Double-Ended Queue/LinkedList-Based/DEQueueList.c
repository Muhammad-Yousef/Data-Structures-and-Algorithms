#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

//Establishing Node
typedef struct {

    int data;
    struct Node *next;

} Node;

Node *head = NULL; //Declared global for the sake of being accessible from whichever Queue function

int size = 0;  //Keeping track the No. nodes in the Queue

//Keeping Track the FRONT and the REAR of the Queue
int FRONT = -1;
int REAR = -1;

//Check whether the Queue is Empty or not
bool isEmpty(){
    return head == NULL;
}

//Check whether the Queue is Full or not
bool isFull(){
    //return REAR == FRONT - 1 || FRONT == 0 && REAR == MAX - 1;
    return size == MAX;
}

//Displaying The Queue
void display(){

    if(isEmpty()){
        printf("Queue is Empty!\n");
        return;
    }

    Node *currentNode = head;

    do {

        printf("%d <- ", currentNode -> data);
        currentNode = currentNode -> next;

    } while (currentNode != head);

    printf("\n");

}


//Inserting Node(s)
void insert(int x, int loc){

    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode -> data = x;

    if(loc == 0){

        if(isEmpty()){

            head = newNode;
            newNode -> next = head;

        } else {

            newNode -> next = head;
            head = newNode;

            Node *currentNode = head;

            for(int i = 0; i < size; i++)
                currentNode = currentNode -> next;

            currentNode -> next = head;

        }

    } else {

        if(loc > size){
            printf("The list is only %d nodes\n", size);
            return;
        }


        Node *currentNode = head;

        for(int i = 0; i < loc - 1; i++)
            currentNode = currentNode -> next;

        newNode -> next = currentNode -> next;
        currentNode -> next = newNode;


    }

    size++;

}


//Deleting Node(s)
void delete(int loc){

    if(isEmpty()){
        printf("Queue is Empty!\n");
        return;
    }

    if(loc > size - 1){
        printf("The Queue is only %d nodes\n", size);
        return;
    }

    Node *currentNode = head;
    Node *previousNode = head;

    if(loc == 0){

        if(size == 1)
            head = NULL;
        else {

            head = currentNode -> next;

            for(int i = 0; i < size - 1; i++)
                currentNode = currentNode -> next;

            currentNode -> next = head;

        }

    } else if(loc == size - 1){

        for(int i = 0; i < loc - 1; i++)
            currentNode = currentNode -> next;

        currentNode -> next = head;

    } else {

        for(int i = 0; i < loc; i++){

            currentNode = currentNode -> next;

            if(i == 0)
                continue;

            previousNode = previousNode -> next;

        }

        previousNode ->next = currentNode -> next;

    }

    size--;

}

//Inserting At REAR
void insertREAR(int x){

    if(isFull()){
        printf("Queue is Full!\n");
        return;
    }

    printf("\nBefore Inserting At REAR: FRONT = %d and REAR = %d\n", FRONT, REAR);

    if(isEmpty()){

        FRONT++;
        REAR++;

        insert(x, REAR);

    } else if(REAR == MAX - 1){

        REAR = 0;

        insert(x, REAR);

    } else {

        REAR++;

        insert(x, REAR);

    }

    printf("After Inserting At REAR: FRONT = %d and REAR = %d\n", FRONT, REAR);

}

//Deleting From REAR
void deleteREAR(){

    if(isEmpty()){
        printf("Queue is Empty!\n");
        return;
    }

    printf("\nBefore Deleting Fromt REAR: FRONT = %d and REAR = %d\n", FRONT, REAR);

    delete(REAR);

    if(FRONT == REAR){

        FRONT = -1;
        REAR = -1;

    } else if(REAR == 0){

        REAR = size - 1; //Skeptical MAX - 1

    } else {

        REAR--;

    }

    printf("After Deleting Fromt REAR: FRONT = %d and REAR = %d\n", FRONT, REAR);

}

//Inerting At FRONT
void insertFRONT(int x){

    if(isFull()){
        printf("Queue is Full!\n");
        return;
    }

    printf("\nBefore Inserting At FRONT: FRONT = %d and REAR = %d\n", FRONT, REAR);

    if(isEmpty()){

        FRONT++;
        REAR++;

        insert(x, FRONT);

    } else if(FRONT == 0){

        FRONT = size;

        insert(x, FRONT);

    } else {

        int temp = FRONT;

        insert(x, ++temp);

    }

    printf("After Inserting At FRONT: FRONT = %d and REAR = %d\n", FRONT, REAR);

}

//Deleting From FRONT
void deleteFRONT(){

    if(isEmpty()){
        printf("Queue is Empty!\n");
        return;
    }

    printf("\nBefore Deleting FROM FRONT: FRONT = %d and REAR = %d\n", FRONT, REAR);

    if(FRONT == REAR){
        delete(FRONT);
        FRONT = -1;
        REAR = -1;
    } else if(FRONT == size - 1){
        delete(FRONT);
        FRONT = 0;
    } else if (FRONT > REAR && FRONT < size){
        delete(FRONT);
    } else{
        delete(FRONT);
        REAR--;
    }

    printf("After Deleting FROM FRONT: FRONT = %d and REAR = %d\n", FRONT, REAR);

}


int main(int argc, char *argv[]){

    display();

    insertREAR(1);
    display();

    insertREAR(2);
    display();

    insertREAR(3);
    display();

    insertREAR(4);
    display();

    insertREAR(5);
    display();

    //insertREAR(6); //OverFlow

    deleteREAR();
    display();

    deleteREAR();
    display();

    insertFRONT(4);
    display();

    insertFRONT(5);
    display();

    insertFRONT(6); //OverFlow

    deleteFRONT();
    display();

    deleteFRONT();
    display();

    deleteFRONT();
    display();

    deleteFRONT();
    display();

    deleteFRONT();
    display();

    return 0;
}
