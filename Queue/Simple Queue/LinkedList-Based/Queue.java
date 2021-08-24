public class Queue{

    //Establishing Node
    class Node{

        int data;
        Node next;

    }

    private Node head;
    private int size;

    //Initialization
    Queue(){
        head = null;
        size = 0;
    }

    //Check whether the Queue is Empty or not
    public boolean isEmpty(){
        return head == null;
    }

    //Displaying The Queue
    public void display(){

        if(isEmpty()){
            System.out.println("Queue is Empty!");
            return;
        }

        Node currentNode = head;

        while(currentNode != null){
            System.out.print(currentNode.data + " <- ");
            currentNode = currentNode.next;
        }

        System.out.println();

    }

    //Enqueue
    public void Enqueue(int x){

        Node newNode = new Node();

        newNode.data = x;

        Node currentNode = head;

        if(isEmpty()){

            newNode.next = head;
            head = newNode;

        } else {

            for(int i = 0; i < size - 1; i++)
                currentNode = currentNode.next;

            newNode.next = currentNode.next;
            currentNode.next = newNode;

        }

        size++;

    }

    //Dequeue
    public int Dequeue(){

        int value;

        if(isEmpty()){

            System.out.println("Queue is Empty!");
            return -1;

        } else {

            Node currentNode = head;
            value = currentNode.data;

            head = currentNode.next;

        }

        size--;

        return value;

    }

}
