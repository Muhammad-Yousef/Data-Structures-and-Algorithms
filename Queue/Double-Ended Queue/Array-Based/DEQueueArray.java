public class DEQueueArray{

    private int SIZE;
    private int elements[];
    private int FRONT;
    private int REAR;

    //Inieialization
    DEQueueArray(int num){
        SIZE = num;
        elements = new int[SIZE];
        FRONT = -1;
        REAR = -1;
    }

    //Check whether the Queue is Empty or not
    public boolean isEmpty(){
        return FRONT == -1;
    }

    //Check whether the Queue is Full or not
    public boolean isFull(){
        return REAR == FRONT - 1 || FRONT == 0 && REAR == SIZE - 1;
    }

    //Displaying
    public void display(){

        if(isEmpty()){
            System.out.println("Queue is Empty!");
            return;
        }

        for(int i = 0; i < SIZE; i++)
            System.out.print(elements[i] + " <- ");

        System.out.println();

    }

    //Insert At REAR
    public void insertREAR(int x){

        if(isFull()){
            System.out.println("Queue is Full!");
            return;
        }

        System.out.println("\nBefore Inserting At REAR: FRONT = " + FRONT + " and REAR = " + REAR);

        if(isEmpty()){

            FRONT++;
            elements[++REAR] = x;

        } else if (REAR == SIZE - 1){

            REAR = 0;
            elements[REAR] = x;

        } else {

            elements[++REAR] = x;

        }

        System.out.println("After Inserting At REAR: FRONT = " + FRONT + " and REAR = " + REAR);

    }

    //Insert At Front
    public void insertFRONT(int x){

        if(isFull()){
            System.out.println("Queue is Full!");
            return;
        }

        System.out.println("\nBefore Inserting At FRONT: FRONT = " + FRONT + " and REAR = " + REAR);

        if(isEmpty()){

            FRONT++;
            REAR++;

            elements[FRONT] = x;

        } else if(FRONT == 0){

            FRONT = SIZE - 1;

            elements[FRONT] = x;

        } else {

            elements[--FRONT] = x;

        }

        System.out.println("After Inserting At FRONT: FRONT = " + FRONT + " and REAR = " + REAR);

    }

    //Deletting From FRONT
    public void deleteFRONT(){

        if(isEmpty()){
            System.out.println("Queue is Empty!");
            return;
        }

        System.out.println("Before Deleting From FRONT: FRONT = " + FRONT + " and REAR = " + REAR);

        elements[FRONT] = 0;

        if(FRONT == REAR){

            FRONT = -1;
            REAR = -1;

        } else if(FRONT == SIZE - 1){

            FRONT = 0;

        } else {

            FRONT++;

        }

        System.out.println("After Deleting From FRONT: FRONT = " + FRONT + " and REAR = " + REAR);

    }

    //Deleting FROM REAR
    public void deleteREAR(){

        if(isEmpty()){
            System.out.println("Queue is Empty!");
            return;
        }

        System.out.println("Before Deleting FROM REAR: FRONT = " + FRONT + " and REAR = " + REAR);

        elements[REAR] = 0;

        if(FRONT == REAR){

            FRONT = -1;
            REAR = -1;

        } else if(REAR == 0){

            REAR = SIZE - 1;

        } else {

            REAR--;

        }

        System.out.println("Before Deleting FROM REAR: FRONT = " + FRONT + " and REAR = " + REAR);

    }

}
