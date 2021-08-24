#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Establishing Node
typedef struct {

    int data;
    struct Node *next;

} Node;

Node *head = NULL; //Declared global for the sake of being accessible from whichever LinkedList function

int size = 0;  //Keeping track the No. nodes in the list

//Check whether the list is Empty or not
bool isEmpty(){
    return head == NULL;
}

//Traversing The List
void traverse(){

    if(isEmpty()){
        printf("List is Empty!\n");
        return;
    }

    Node *currentNode = head;

    do {

        printf("%d -> ", currentNode -> data);
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


int main(int argc, char *argv[]){

    traverse();

    insert(1, 0);
    traverse();

    insert(2, 1);
    traverse();

    insert(3, 2);
    traverse();

    insert(5, 3);
    traverse();

    insert(4, 3);
    traverse();

    /*insert(-1, 0);
    traverse();*/

    delete(0);
    traverse();

    delete(3);
    traverse();

    delete(1);
    traverse();

    delete(0);
    traverse();

    delete(1);
    traverse();

    delete(0);
    traverse();

    return 0;
}

