#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Establishing Node
typedef struct {

    int data;
    struct Node *next;
    struct Node *previous;

} Node;

Node *head = NULL; //Declared global for the sake of being accessible from whichever function of the list

int size = 0; //Keeping Track of the No. nodes in the list

//Check whether the list is Emtpy of not
bool isEmpty(){
    return head == NULL;
}

//Traversing The List
void traverse(){

    if(isEmpty()){
        printf("The list is Empty!\n");
        return;
    }

    Node *currentNode = head;

    for(int i = 0; i < size; i++){

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

        if(isEmpty()){

            head = newNode;
            newNode -> next = head;

        } else {

            newNode -> next = head;

            Node *temp = newNode -> next;
            temp -> previous = newNode;

            head = newNode;

            temp -> next = head;

        }

    } else if(loc == size){

        Node *currentNode = head;

        do currentNode = currentNode -> next; while (currentNode -> next != head);

        newNode -> previous = currentNode;
        currentNode -> next = newNode;

        newNode -> next = head;

    } else {

        Node *currentNode = head;

        for(int i = 0; i < loc - 1; i++)
            currentNode = currentNode -> next;

        newNode -> next = currentNode -> next;

        currentNode -> next = newNode;

        newNode -> previous = currentNode;

        Node *temp = newNode -> next;
        temp -> previous = newNode;


    }

    size++;

}

//Deleting Node(s)
void delete(int loc){

    if(isEmpty()){
        printf("List is Empty!\n");
        return;
    }

    Node *currentNode = head;
    Node *previousNode = head;

    if(loc == 0){

        if(size == 1)
            head = NULL;
        else {

            Node *last = head;

            do last = last -> next; while (last -> next != head);

            head = head -> next;

            Node *temp = head;
            temp -> previous = NULL;

            last -> next = head;

        }

    } else if (loc == size) {

        for(int i = 0; i < size - 1; i++){

            currentNode = currentNode -> next;

            if(i == 0) continue;

            previousNode = previousNode -> next;

        }

        previousNode -> next = head;

        currentNode -> next = NULL;
        currentNode -> previous = NULL;

    } else {

        Node *currentNode = head;
        Node *previousNode = head;

        for(int i = 0; i <  loc; i++){

            currentNode = currentNode -> next;

            if(i == 0) continue;

            previousNode = previousNode -> next;

        }

        previousNode -> next = currentNode -> next;

        Node *temp = currentNode -> next;
        temp -> previous = previousNode;

    }

    size--;

}


int main(int argc, char *argv[]){

    traverse();

    insert(1, 0);
    traverse();

    insert(0, 0);
    traverse();

    insert(5, 2);
    traverse();

    insert(6, 3);
    traverse();

    insert(2, 2);
    traverse();

    insert(4, 3);
    traverse();

    insert(3, 3);
    traverse();

    delete(6);
    traverse();

    delete(5);
    traverse();

    delete(0);
    traverse();

    delete(0);
    traverse();

    delete(1);
    traverse();

    delete(1);
    traverse();

    delete(0);
    traverse();

    return 0;
}
