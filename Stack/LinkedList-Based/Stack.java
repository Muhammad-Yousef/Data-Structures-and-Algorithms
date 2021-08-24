public class Stack{

    //Establishing Node
    class Node{

        int data;
        Node next;

    }

    private Node head;
    private int size;

    //Initializiation
    Stack(){
        head = null;
        size = 0;
    }

    //Check whether the Stack is Empty or not
    public boolean isEmpty(){
        return head == null;
    }

    //Display Stack
    public void display(){

        if(isEmpty()){
            System.out.println("Stack is Empty!");
            return;
        }

        Node currentNode = head;

        while(currentNode != null){
            System.out.println("[" + currentNode.data + "]");
            currentNode = currentNode.next;
        }

        System.out.println();

    }

    //Peek
    public void peek(){

        if(isEmpty()){
            System.out.println("Stack is Empty!");
            return;
        }

        System.out.println(head.data);
        System.out.println();
    }

    //Pushing
    public void push(int x){

        Node newNode = new Node();

        newNode.data = x;
        newNode.next = head;

        head = newNode;

        size++;

    }

    //Popping
    int pop(){

        int value;

        if(isEmpty()){

            System.out.println("Stack is Empty!");
            value = -1;

        } else {

            Node currentNode = head;

            head = currentNode.next;
            value = currentNode.data;

        }

        size--;

        return value;

    }

}
