#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Establishing Node
typedef struct Node {

  int data;
  struct Node *left;
  struct Node *right;
  
};

Node *Root = NULL;

//Check whether the tree is Empty or not
bool isEmpty(){
  return Root == NULL;
}

//Inorder Traversal
void traverseInorder(Node *root){

  if(isEmpty()){
    printf("Tree is Empty!\n");
    return;
  }

  if(root -> left) //For the sake of handling Segmentation Faults
    traverseInorder(root -> left);

  printf("%d -> ", root -> data);

  if(root -> right) //For the sake of handling Segmentation Faults
    traverseInorder(root -> right);
  
}

//Preorder Traversal
void traversePreorder(Node *root){

  if(isEmpty()){
    printf("Tree is Empty!\n");
    return;
  }

  printf("%d -> ", root -> data);

  if(root -> left)
    traversePreorder(root -> left);

  if(root -> right)
    traversePreorder(root -> right);
  
}

//Postorder Traversal
void traversePostorder(Node *root){

  if(isEmpty()){
    printf("Tree is Empty!\n");
    return;
  }

  if(root -> left)
    traversePostorder(root -> left);

  if(root -> right)
    traversePostorder(root -> right);

  printf("%d -> ", root -> data);
  
}

//Establishing Root
void rootNode(int x){

  //Creating New Node
  Node *newNode = (Node*) malloc(sizeof(Node));
  newNode -> data = x;

  Root = newNode;
  
}

//Inserting to the Left
void insertLeft(Node *root, int x){

  //Creating New Node
  Node *newNode = (Node*) malloc(sizeof(Node));
  newNode -> data = x;

  //Assigning Left Link
  root -> left = newNode;
  
}

//Inserting to the Right
void insertRight(Node *root, int x){

  //Creating New Node
  Node *newNode = (Node*) malloc(sizeof(Node));
  newNode -> data = x;

  //Assigning Right Link
  root -> right = newNode;
  
}

//Check Whether It Is A Full-Binary Tree
bool isFullBinaryTree(Node *root){

  if(root == NULL)
    return true;

  if(root -> left == NULL) && (root -> right == NULL)
    return true;

  if(root -> left && root -> right)
    return isFullBinaryTree(root -> left) && isFullBinaryTree(root -> right);

  return false;
}

//Driver Program
int main(int argc, char *argv[]){

  rootNode(1);
  insertLeft(Root, 2);
  insertRight(Root, 3);

  insertLeft(Root -> left, 4);
  insertRight(Root -> left, 5);

  printf("Inorder Traversal: ");
  traverseInorder(Root);

  printf("\nPreorder Traversal: ");
  traversePreorder(Root);

  printf("\nPostorder Traversal: ");
  traversePostorder(Root);

  return 0;
  
}
