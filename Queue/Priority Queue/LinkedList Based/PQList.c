#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 //Setting Max No. Elements permitted in the Queue

//Establishing Node
typedef struct {

    int data;
    struct Node *next;

} Node;

Node *head = NULL; //Declared global for the sake of being accessible from whichever LinkedList function

int size = 0; //Keeping track the No. nodes in the Queue

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

//Displaying the Queue
void display(){

    if(isEmpty()){
        printf("Queue is Empty!\n");
        return;
    }

    Node *currentNode = head;

    while (currentNode != NULL){
        printf("%d -> ", currentNode -> data);
        currentNode = currentNode -> next;
    }

    printf("\n");

}

//Inserting Node(s)
void insert(int x, int loc){

    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode -> data = x;

    if(loc == 0){

        newNode -> next = head;
        head = newNode;

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
        printf("List is Already Empty!\n");
        return;
    }

    if(loc > size - 1){
        printf("The list is only %d nodes\n", size);
        return;
    }

    Node *currentNode = head;
    Node *previousNode = head;

    if(loc == 0){

        head = currentNode -> next;

    } else if(loc == size - 1) {

        for(int i = 0; i < loc - 1; i++)
            currentNode = currentNode -> next;

        currentNode -> next = NULL;

    } else {

        for(int i = 0; i < loc; i++){
            currentNode = currentNode -> next;

            if(i == 0)
                continue;

            previousNode = previousNode -> next;

        }

        previousNode -> next = currentNode -> next;

    }

    size--;

}

//Dequeue
void Dequeue(){

    if(isEmpty()){
        printf("Queue is Empty!\n");
        return;
    }

    delete(REAR);

    REAR--;

}

//Enqueue
void Enqueue(int x){

    //Check whether the Queue is is Full or not
    if(isFull()){
        printf("Queue is Full!\n");
        return;
    }

    Node *last = head;

    //Keeping Track of the last node
    if(last)
        for(int i = 1; i < size; i++) last = last -> next;

    
    if(isEmpty()){ //Inserting as the first node

        FRONT++;
        REAR++;

        insert(x, REAR);

    } else if(x < head -> data){ //Inserting at first

        insert(x, FRONT);

        REAR++;

    } else if(x > last -> data){ //Inserting at last

        REAR++;

        insert(x, REAR);

    } else if(x > head -> data && x < last -> data) { //Inserting at location in between

        Node *currentNode = head -> next;

        int i = 1;

        while(x > currentNode -> data){
            currentNode = currentNode -> next;
            i++;
        }

        REAR++;

        insert(x, i);

    }

}


int main(int argc, char *argv[]){

    display();

    Enqueue(3);
    display();

    Enqueue(2);
    display();

    Enqueue(5);
    display();

    Enqueue(4);
    display();

    Enqueue(1);
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
