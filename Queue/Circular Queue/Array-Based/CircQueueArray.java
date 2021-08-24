public class CircQueueArray{

    private int elements[];
    private int FRONT;
    private int REAR;

    //Initialization
    CircQueueArray(int size){

        elements = new int[size];
        FRONT = -1;
        REAR = -1;

    }

    //Check whether the Queue is Full or not
    public boolean isFull(){
        return FRONT == REAR + 1 || FRONT == 0 && REAR == elements.length - 1;
    }

    //Check whether the Queue is Empty or not
    public boolean isEmpty(){
        return FRONT == -1 && REAR == -1;
    }

    public void display(){

        if(isEmpty()){
            System.out.println("Queue is Empty!");
            return;
        }

        for(int i = 0; i < elements.length; i++)
            if(i != elements.length - 1)
                System.out.print(elements[i] + " <- ");
            else
                System.out.print(elements[i]);

        System.out.println();
    }


    public void Enqueue(int x){

        System.out.println("\nBefore Enqueue: FRONT = " + FRONT + " and REAR = " + REAR);

        if(isFull()){
            System.out.println("Queue is Full!");
            return;
        }

        if(isEmpty()){

            FRONT++; REAR++;

            elements[FRONT] = x;

        } else {

            REAR = (REAR + 1) % elements.length;
            elements[REAR] = x;

        }

        System.out.println("\nAfter Enqueue: FRONT = " + FRONT + " and REAR = " + REAR);

    }

    //Dequeue
    public void Dequeue(){

        System.out.println("\nBefore Enqueue: FRONT = " + FRONT + " and REAR = " + REAR);

        if(isEmpty()){
            System.out.println("Queue is Empty!");
            return;
        }

        if(FRONT == REAR){

            elements[FRONT++] = 0;
            FRONT = -1;
            REAR = -1;

        } else

            elements[FRONT++] = 0;

        System.out.println("\nAfter Enqueue: FRONT = " + FRONT + " and REAR = " + REAR);

    }

    
}
