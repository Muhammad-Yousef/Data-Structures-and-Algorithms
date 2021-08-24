#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 //Setting Max Nodes in The Queue

int FRONT = -1;
int REAR = -1;

//Establishing Node
typedef struct {

    int data;
    struct Node *next;

} Node;

Node *head = NULL; //Declared global for the sake of being accessible from whichever Queue function

int size = 0;  //Keeping track the No. nodes in the Queue

//Check whether the queue is Empty or not
bool isEmpty(){
    return head == NULL;
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

    printf("\n\n");

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

//Enqueue
void Enqueue(int x){

    printf("Before Enqueue: FRONT = %d and REAR = %d\n", FRONT, REAR);

    if(isEmpty()){

        FRONT++;
        REAR++;

        insert(x, REAR);

    } else if(size == MAX){

        printf("Queue is Full\n");

    } else {

        REAR = (REAR + 1) % MAX;

        insert(x, REAR);

    }

    printf("After Enqueue: FRONT = %d and REAR = %d\n", FRONT, REAR);

}

//Deleting Node(s)
void delete(int loc){

    if(isEmpty()){
        printf("List is Empty!\n");
        return;
    }

    if(loc > size - 1){
        printf("The list is only %d nodes\n", size);
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

void Dequeu(){

    printf("\nBefore Dequeue: FRONT = %d and REAR = %d\n", FRONT, REAR);

    delete(0);

    if(FRONT == REAR){
        FRONT = -1; REAR = -1;
    } else
        FRONT++;

    printf("After Dequeue: FRONT = %d and REAR = %d\n", FRONT, REAR);
}


int main(int argc, char *argv[]){

    display();

    printf("\n");

    Enqueue(1);
    display();

    Enqueue(2);
    display();

    Enqueue(3);
    display();

    Enqueue(4);
    display();

    Enqueue(5);
    display();

    Enqueue(6);

    Dequeu();
    display();

    Dequeu();
    display();

    Enqueue(6);
    display();

    Enqueue(7);
    display();

    Enqueue(8);



    return 0;
}

