public class PriorityQArray{

    private int PriorityQ[]; //Establishing The Priority Queue
    private int FRONT;
    private int REAR;

    //Initializing
    public PriorityQArray(int num){

        PriorityQ = new int[num];
        FRONT = -1;
        REAR = -1;

    }

    //Check whether the Queue is Empty or not
    public boolean isEmpty(){
        return REAR == -1;
    }

    //Check whether the Queue is Full or not
    public boolean isFull(){
        return REAR == PriorityQ.length - 1;
    }

    //Displaying The Queue
    public void display(){

        if(isEmpty()){
            System.out.println("Queue is Empty!");
            return;
        }

        for(int i = FRONT; i <= REAR; i++)
            System.out.print(PriorityQ[i] + " <- ");

        System.out.println();

    }

    //Dequeue
    public void Dequeue(){

        if(isEmpty()){
            System.out.println("Queue is Empty!");
            return;
        }

        REAR--;

    }

    //Right Shifting
    void UnBoundedRshift(int a[], int n, int start){

        for(int i = n - 2; i >= start; i--)
            a[i + 1] = a[i];

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

            PriorityQ[REAR] = x;

        } else if(x < PriorityQ[FRONT]){

            UnBoundedRshift(PriorityQ, PriorityQ.length, FRONT);

            REAR++;

            PriorityQ[FRONT] = x;

        } else if(x > PriorityQ[REAR]){

            REAR++;

            PriorityQ[REAR] = x;

        } else {

            int i = FRONT + 1;

            while(x > PriorityQ[i]) i++;

            UnBoundedRshift(PriorityQ, PriorityQ.length, i);

            REAR++;

            PriorityQ[i] = x;

        }

    }
}
