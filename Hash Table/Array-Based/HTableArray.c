#include <stdio.h>

#define SIZE 7 //Setting Max Size of the array

//Establishing Array
int a[SIZE];

//Initializing Array
void initArray(){
  for(int i = 0; i < SIZE; i++)
    a[i] = -1;
}

//Display
void display(){

  for(int i = 0; i < SIZE; i++)
    printf("a[%d] = %d\n", i, a[i]);

}

//Searching
void search(int x){

  int key = x % SIZE;

  if(a[key] == x)
    printf("Found!\n");
  else
    printf("Does Not Exist!\n");

}

//Inserting
void insert(int x){

  int key = x % SIZE;

  if(a[key] == -1){

    a[key] = x;

  } else {

    printf("Collision: a[%d] has element %d already!\n", key, a[key]);

  }

}

//Deleting
void delete(int x){

  int key = x % SIZE;

  if(a[key] == x)
    a[key] = -1;
  else
    printf("%d does not exist!", x);

}

int main(int argc, char *argv[]){

    initArray();

    insert(24);
    insert(8);
    insert(14);

    display();

    search(8);
    search(19);

    delete(24);

    display();

    return 0;
}
