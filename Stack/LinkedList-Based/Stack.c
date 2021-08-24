#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Establishing Node
typedef struct {

    int data;
    struct Node *next;

} Node;

Node *head = NULL; //Declared global for the sake of being accessible from whichever Stack function

int size = 0; //Keeping track the No. nodes in the Stack

//Check whether the Stack is Empty or not
bool isEmpty(){
    return head == NULL;
}

//Display Stack
void display(){

    if(isEmpty()){
        printf("Stack is Empty!\n");
        return;
    }

    Node *currentNode = head;

    while(currentNode != NULL){
        printf("[%d]\n", currentNode -> data);
        currentNode = currentNode -> next;
    }

    printf("\n");

}

//Peek
void peek(){

    if(isEmpty()){
        printf("Stack is Empty!\n");
        return;
    }

    printf("%d\n\n", head -> data);

}

//Pushing
void push(int x){

    Node *newNode = (Node*) malloc(sizeof(Node));

    newNode -> data = x;
    newNode -> next = head;

    head = newNode;

    size++;

}

//Popping
int pop(){

    int value;

    if(isEmpty()){

        printf("Stack is Empty!\n");
        value = -1;

    } else {

        Node *currentNode = head;

        head = currentNode -> next;
        value = currentNode -> data;

    }

    size--;

    return value;

}

int main(int argc, char *argv[]){

    display();

    push(3);
    display();

    push(2);
    display();

    push(1);
    display();

    peek();

    pop();
    display();

    pop();
    display();

    pop();
    display();

    pop();


    return 0;
}
