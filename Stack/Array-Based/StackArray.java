public class StackArray{

    private int top;
    private int elements[];
    private int counter;

    //Initializing Stack
    StackArray(int size){

        top = -1;
        elements = new int[size];
        counter = 0;

    }


    //Check whether the stack is Empty or not
    public boolean isEmpty(){
        return top == -1;
    }


    //Check whether the stack is Full or not
    public boolean isFull(){
        return top == (elements.length) - 1;
    }


    //Display The Stack
    public void display(){

        if(isEmpty()){

            System.out.println("Stack is Empty!");
            return;

        }

        for(int i = counter - 1; i >= 0; i--)
            System.out.println("[" + elements[i] + "]");

        System.out.println();

    }


    //Peek
    public void peek(){

        if(isEmpty()){

            System.out.println("Stack is Empty!");
            return;

        }

        System.out.println(elements[top]);

    }


    //Pushing
    public void push(int x){

        if(isFull()){

            System.out.println("Stack is Full!");
            return;

        }

        elements[++top] = x;

        counter++;

    }

    //Popping
    public int pop(){

        if(isEmpty()){

            System.out.println("Stack is Empty!");
            return -1;

        }

        counter--;

        return elements[top--];

    }

}
