#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Establishing Node
typedef struct {

    int data;
    struct Node *next;

} Node;

Node *head = NULL; //Declared global for the sake of being accessible from whichever Queue function

int size = 0; //Keeping track the No. nodes in the Queue

//Check whether the Queue is Empty or not
bool isEmpty(){
    return head == NULL;
}

//Displaying Queue
void display(){

    if(isEmpty()){
        printf("Queue is Empty!\n");
        return;
    }

    Node *currentNode = head;

    while (currentNode != NULL){
        printf("%d <- ", currentNode -> data);
        currentNode = currentNode -> next;
    }

    printf("\n");

}

//Enqueue
void Enqueue(int x){

    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode -> data = x;

    Node *currentNode = head;

    if(isEmpty()){

        newNode -> next = head;
        head = newNode;

    } else {

        for(int i = 0; i < size - 1; i++)
            currentNode = currentNode -> next;

        newNode -> next = currentNode -> next;
        currentNode -> next = newNode;

    }

    size++;

}

//Dequeue
int Dequeue(){

    int value;

    if(isEmpty()){

        printf("Queue is Empty!\n");
        return -1;

    } else {

        Node *currentNode = head;

        value = currentNode -> data;
        head = currentNode -> next;

    }

    size--;

    return value;
}

int main(int argc, char *argv[]){

    display();

    Enqueue(1);
    display();

    Enqueue(2);
    display();

    Enqueue(3);
    display();

    Dequeue();
    display();

    Dequeue();
    display();

    Dequeue();
    display();

    return 0;
}
