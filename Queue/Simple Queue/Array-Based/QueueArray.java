public class Queue{

    private int elements[];
    private int FRONT;
    private int REAR;

    //Initializing The Queue
    public Queue(int size){

        elements = new int[size];
        FRONT = REAR = -1;

    }

    //Check whether the Queue is Empty or not
    public boolean isEmpty(){
        return FRONT == -1;
    }

    //Check whether the Queue is Full or not
    public boolean isFull(){
        return REAR == (elements.length) - 1;
    }

    //Display The Queue
    public void display(){

        if(isEmpty()){

            System.out.println("Queue is Empty!");
            return;

        }

        for(int i = FRONT; i < REAR + 1; i++)
            System.out.print(elements[i] + " -> ");

        System.out.println();

    }

    //Peek
    public void peek(){

        if(isEmpty()){

            System.out.println("Queue is Empty!");
            return;

        }

        System.out.println(elements[FRONT]);

    }

    //Enqueue
    public void Enqueue(int x){

        if(isFull()){

            System.out.println("Queue is Full!");
            return;

        }

        if(isEmpty()){

            FRONT++;
            REAR++;

            elements[REAR] = x;

        } else {

            elements[++REAR] = x;

        }

    }

    //Dequeue
    int Dequeue(){

        if(isEmpty()){

            System.out.println("Queue is Empty!");
            return -1;

        }

        int value;

        if(FRONT != REAR && FRONT != (elements.length) - 1)
            value = elements[FRONT++];
        else {

            value = elements[FRONT];
            FRONT = REAR = -1;

        }

        return value;

    }



}
