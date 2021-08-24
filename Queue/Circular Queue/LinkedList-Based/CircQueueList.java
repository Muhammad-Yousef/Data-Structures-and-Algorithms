class CircQueueList{

    //Establishing Node
    class Node {
        int data;
        Node next;
    }

    private Node head;
    private int size;
    private int MAX;
    private int FRONT;
    private int REAR;

    //Initialization
    CircQueueList(int max){

        head = null;
        size = 0;
        MAX = max;
        FRONT = -1;
        REAR = -1;

    }

    //Check whether the list is Empty or not
    public boolean isEmpty(){
        return head == null;
    }

    //Traversing The List
    public void display(){

        if(isEmpty()){
            System.out.println("Queue is Empty!\n");
            return;
        }

        Node currentNode = head;

        do {

            System.out.print(currentNode.data + " <- ");
            currentNode = currentNode.next;

        } while(currentNode != head);

        System.out.println();

    }

    //Inserting Node(s)
    void insert(int x, int loc){

        Node newNode = new Node();
        newNode.data = x;

        if(loc == 0){

            if(isEmpty()){

                head = newNode;
                newNode.next = head;

            } else {

                newNode.next = head;
                head = newNode;

                Node currentNode = head;

                for(int i = 0; i < size; i++)
                    currentNode = currentNode.next;

                currentNode.next = head;

            }

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
    void delete(int loc){

        if(isEmpty()){

            System.out.println("List is Empty!\n");
            return;

        }

        if(loc > size - 1){

            System.out.println("The list is only " + size + " nodes!");
            return;

        }

        Node currentNode = head;
        Node previousNode = head;

        if(loc == 0){

            if(size == 1)
                head = null;
            else {

                head = currentNode.next;

                for(int i = 0; i < size - 1; i++)
                    currentNode = currentNode.next;

                currentNode.next = head;

            }

        } else if(loc == size - 1){

            for(int i = 0; i < loc - 1; i++)
                currentNode = currentNode.next;

            currentNode.next = head;

        } else {

            for(int i = 0; i < loc; i++){

                currentNode = currentNode.next;

                if(i == 0)
                    continue;

                previousNode = previousNode.next;

            }

            previousNode.next = currentNode.next;

        }

        size--;

    }

    //Enqueue
    void Enqueue(int x){

        System.out.println("Before Enqueue: FRONT = " + FRONT + " and REAR = " + REAR);

        if(isEmpty()){

            FRONT++;
            REAR++;

            insert(x, REAR);

        } else if(size == MAX){

            System.out.println("Queue is Full");

        } else {

            REAR = (REAR + 1) % MAX;

            insert(x, REAR);

        }

        System.out.println("After Enqueue: FRONT = " + FRONT + " and REAR = " + REAR);

    }

    //Dequeue
    void Dequeue(){

        System.out.println("\nBefore Dequeue: FRONT = " + FRONT + " and REAR = " + REAR);

        delete(0);

        if(FRONT == REAR){
            FRONT = -1; REAR = -1;
        } else
            FRONT++;

        System.out.println("\nAfter Dequeue: FRONT = " + FRONT + " and REAR = " + REAR);

    }

}
