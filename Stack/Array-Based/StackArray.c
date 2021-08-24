#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Set Stack Size
#define SIZE 5

int counter = 0; //Counting No. elements in the stack

//Establishing The Stack
typedef struct {

    int elements[SIZE];
    int top;

} Stack;

//Initializing Stack
void initStack(Stack *s){
    s -> top = -1;
}

//Check whether the stack is Empty or not
bool isEmpty(Stack *s){
    return s -> top == -1;
}

//Check whether the stack is Full or not
bool isFull(Stack *s){
    return s -> top == (SIZE - 1);
}

//Display The Stack
void display(Stack *s){

    if(isEmpty(s)){
        printf("Stack is Empty!\n");
        return;
    }

    for(int i = counter - 1; i >= 0; i--)
        printf("[%d]\n", s -> elements[i]);

    printf("\n");
}

//Peek
void peek(Stack *s){

    if(isEmpty(s)){
        printf("Stack is Empty!\n");
        return;
    }

    printf("%d\n", s -> elements[s -> top]);

}

//Pushing
void push(Stack *s, int x){

    if(isFull(s)){
        printf("Stack is Full!\n");
        return;
    }

    s -> elements[++(s -> top)] = x;

    counter++;

}

//Popping
int pop(Stack *s){

    if(isEmpty(s)){
        printf("Stack is Empty!\n");
        return -1;
    }

    counter--;

    return s -> elements[(s -> top)--];

}

int main(int argc, char *argv[]){

    Stack *s = (Stack*) malloc(sizeof(Stack));

    initStack(s);

    display(s);

    push(s, 3);
    display(s);

    push(s, 2);
    display(s);

    push(s, 1);
    display(s);

    peek(s);

    printf("[%d]\n\n", pop(s));
    display(s);

    printf("[%d]\n\n", pop(s));
    display(s);

    printf("[%d]\n\n", pop(s));
    display(s);

    return 0;

}
