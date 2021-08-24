public class DLinkedList {

    //Establishing Node
    class Node {

        int data;
        Node previous;
        Node next;

    }

    private Node head;
    private int size;

    //Initialization
    DLinkedList(){

        head = null;
        size = 0;

    }

    //Check whether the list is Empty or not
    public boolean isEmpty(){
        return head == null;
    }

    //Traversing The List
    public void traverse(){

        if(isEmpty()){
            System.out.println("List is Empty!");
            return;
        }

        Node currentNode = head;

        while(currentNode != null){
            System.out.print(currentNode.data + " -> ");
            currentNode = currentNode.next;
        }

        System.out.println();

    }

    //Inserting Node(s)
    void insert(int x, int loc){

        Node newNode = new Node();
        newNode.data = x;

        if(loc == 0){

            newNode.previous = head;
            newNode.next = head;
            head = newNode;

        } else {

            if(loc > size){
                System.out.println("The list is only" + size + " nodes!");
                return;
            }

            Node currentNode = head;

            for(int i = 0; i < loc - 1; i++)
                currentNode = currentNode.next;

            newNode.next = currentNode.next;

            if(loc < size - 1){

                currentNode.next.previous = newNode; //

            }

            currentNode.next = newNode;
            newNode.previous = currentNode;

        }

        size++;

    }

    //Delete Node(s)
    void delete(int loc){

        if(isEmpty()){

            System.out.println("List is Already Empty!");
            return;

        }

        if(loc > size - 1){

            System.out.println("The list is only" + size + " nodes");
            return;

        }

        Node currentNode = head;

        if(loc == 0){

            head = currentNode.next;
            currentNode.previous = null;

        } else if(loc == size - 1){

            for(int i = 0; i < loc - 1; i++)
                currentNode = currentNode.next;

            currentNode.next = null;

        } else {

            for(int i = 0; i < loc; i++)
                currentNode = currentNode.next;

            currentNode.previous.next = currentNode.next;
            currentNode.next.previous = currentNode.previous;

        }

        size--;

    }

}
