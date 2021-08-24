class DEQueueList{

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
    DEQueueList(int num){

        head = null;
        size = 0;
        MAX = 5;
        FRONT = -1;
        REAR = -1;

    }

    //Check whether the Queue is Empty or not
    public boolean isEmpty(){
        return head == null;
    }

    //Check whether the Queue is Full or not
    public boolean isFull(){
        return size == MAX;
    }


    //Displaying The Queue
    public void display(){

        if(isEmpty()){
            System.out.println("Queue is Empty!\n");
            return;
        }

        Node currentNode = head;

        do {

            System.out.print(currentNode.data + " -> ");
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

                System.out.println("The Queue is only " + size + " nodes!");
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

            System.out.println("Queue is Empty!\n");
            return;

        }

        if(loc > size - 1){

            System.out.println("The Queue is only " + size + " nodes!");
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

    public void insertREAR(int x){

        if(isFull()){
            System.out.println("Queue is Full!");
            return;
        }

        System.out.println("\nBefore Inserting At REAR: FRONT = " + FRONT + " and REAR = " + REAR);

        if(isEmpty()){
            FRONT++;
            REAR++;

            insert(x, REAR);

        } else if(REAR == MAX - 1){

            REAR = 0;
            insert(x, REAR);

        } else {

            REAR++;
            insert(x, REAR);

        }

        System.out.println("\nAfter Inserting At REAR: FRONT = " + FRONT + " and REAR = " + REAR);

    }

    //Deleting From REAR
    public void deleteREAR(){

        if(isEmpty()){
            System.out.println("Queue is Full!");
            return;
        }

        System.out.println("\nBefore Deleting From REAR: FRONT = " + FRONT + " and REAR = " + REAR);
        delete(REAR);

        if(FRONT == REAR){

            FRONT = -1;
            REAR = -1;

        } else if(REAR == 0)
            REAR = size - 1;
        else
            REAR--;

        System.out.println("After Deleting From REAR: FRONT = " + FRONT + " and REAR = " + REAR);


    }

    //Inserting At FRONT
    public void insertFRONT(int x){

        if(isFull()){
            System.out.println("Queue is Full!");
            return;
        }

        System.out.println("\nBefore Inserting At FRONT: FRONT = " + FRONT + " and REAR = " + REAR);

        if(isEmpty()){

            FRONT++;
            REAR++;

            insert(x, FRONT);

        } else if(FRONT == 0){

            FRONT = size;

            insert(x, FRONT);

        } else {

            int temp = FRONT;

            insert(x, ++temp);

        }

        System.out.println("\nAfter Inserting At FRONT: FRONT = " + FRONT + " and REAR = " + REAR);

    }

    //Deleting From FRONT
    public void deleteFRONT(){

        if(isEmpty()){
            System.out.println("Queue is Empty!");
            return;
        }

        System.out.println("\nBefore Deleting From FRONT: FRONT = " + FRONT + " and REAR = " + REAR);
        if(FRONT == REAR){

            delete(FRONT);

            FRONT = -1;
            REAR = -1;

        } else if(FRONT == size - 1){

            delete(FRONT);
            FRONT = 0;

        } else if(FRONT > REAR && FRONT < size){

            delete(FRONT);

        } else {

            delete(FRONT);
            REAR--;

        }

        System.out.println("After Deleting From FRONT: FRONT = " + FRONT + " and REAR = " + REAR);

    }

}
