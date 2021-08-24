public class LinkedList {

    //Establishing Node
    class Node {

        int data;
        Node next;

    };

    private Node head;
    private int size;

    //Initializing The List
    LinkedList(){

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

        while (currentNode != null){
            System.out.print(currentNode.data + " -> ");
            currentNode = currentNode.next;
        }

        System.out.println();

    }

    //Inserting Node(s)
    public void insert(int x, int loc){

        Node newNode = new Node();
        newNode.data = x;

        if(loc == 0){

            newNode.next = head;
            head = newNode;

        } else {

            if(loc > size){
                System.out.println("The list is only " + size + " nodes!");
                return;
            }

            Node currentNode = head;

            for(int i = 0; i < loc - 1; i++)
                currentNode = currentNode.next;

            newNode.next = currentNode.next;
            currentNode.next = newNode;

        }

        size++;
    }

    //Deleting Node(s)
    public void delete(int loc){

        if(isEmpty()){
            System.out.println("List is already Empty!");
            return;
        }

        if(loc > size - 1){
            System.out.println("The list is only " + size + " node");
            return;
        }

        Node currentNode = head;
        Node previousNode = head;

        if(loc == 0){

            head = currentNode.next;

        } else if (loc == size - 1){

            for(int i = 0; i < loc - 1; i++)
                currentNode = currentNode.next;

            currentNode.next = null;

        } else {

            for(int i = 0; i < loc; i++) {
                currentNode = currentNode.next;

                if(i == 0)
                    continue;

                previousNode = previousNode.next;

            }

            previousNode.next = currentNode.next;

        }

        size--;

    }



}
