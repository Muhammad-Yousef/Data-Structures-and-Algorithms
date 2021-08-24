public class PQList {

    //Establishing Node
    class Node {

        int data;
        Node next;

    };

    private Node head;
    private int size;
    private int MAX;
    private int FRONT;
    private int REAR;

    //Initializing The List
    public PQList(int num){

        head = null;
        size = 0;
        MAX = num;
        FRONT = -1;
        REAR = -1;

    }

    //Check whether the Queue is Empty or not
    public boolean isEmpty(){
        return REAR == -1;
    }

    //Check whether the Queue is Full or not
    public boolean isFull(){
        return REAR == MAX - 1;
    }

    //Displaying The Queue
    public void display(){

        if(isEmpty()){
            System.out.println("Queue is Empty!");
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
            System.out.println("Queue is already Empty!");
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

    //Dequeue
    public void Dequeue(){

        if(isEmpty()){
            System.out.println("Queue is Empty!");
            return;
        }

        delete(REAR);

        REAR--;

    }

    //Enqueue
    public void Enqueue(int x){

        //Check whether the Queue is Full or not
        if(isFull()){
            System.out.println("Queue is Full!");
            return;
        }

        Node last = head;

        //Keeping Track of the last node
        if(last != null)
            for(int i = 1; i < size; i++) last = last.next;


        if(isEmpty()){ //Inserting as the first Node

            FRONT++;
            REAR++;

            insert(x, REAR);

        } else if(x < head.data){ //Inserting at first

            insert(x, FRONT);

            REAR++;

        } else if(x > last.data){ //Insertingg at last

            REAR++;

            insert(x, REAR);

        } else if(x > head.data && x < last.data){ //Inserting at location in between

            Node currentNode = head.next;

            int i = 1;

            while(x > currentNode.data){

                currentNode = currentNode.next;
                i++;

            }

            REAR++;

            insert(x, i);

        }

    }



}
