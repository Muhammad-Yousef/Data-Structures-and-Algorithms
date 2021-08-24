#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Establishing Node
typedef struct {

    int data;
    struct Node *previous;
    struct Node *next;

} Node;

Node *head = NULL; //Declared global for the sake of being accessible from whichever LinkedList function

int size = 0; //Keeping track the No. nodes in the list
    
//Check whether the list is Empty or not
bool isEmpty(){
    return head == NULL;
}

//Traversing the list
void traverse(){

    if(isEmpty()){
        printf("List is Empty!\n");
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

        newNode -> previous = head;
        newNode -> next = head;
        head = newNode;


    } else {


        if(loc > size){
            printf("The list is only %d nodes!\n", size);
            return;
        }

        Node *currentNode = head;

        for(int i = 0; i < loc - 1; i++)
            currentNode = currentNode -> next;

        newNode -> next = currentNode -> next;

        if(loc < size - 1){

            currentNode = currentNode -> next;
            currentNode -> previous = newNode;
            currentNode = currentNode -> previous;

        }


        currentNode -> next = newNode;
        newNode -> previous = currentNode;


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

    if(loc == 0){

        head = currentNode -> next;
        currentNode -> previous = NULL;

    } else if (loc == size - 1){

        for(int i = 0; i < loc - 1; i++)
            currentNode = currentNode -> next;

        currentNode -> next = NULL;


    } else {

        for(int i = 0; i < loc; i++)
            currentNode = currentNode -> next;

        Node *temp;

        temp = currentNode -> next;

        temp -> previous = currentNode -> previous;

        currentNode = temp;

        temp = currentNode -> previous;

        temp -> next = currentNode -> next;

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
