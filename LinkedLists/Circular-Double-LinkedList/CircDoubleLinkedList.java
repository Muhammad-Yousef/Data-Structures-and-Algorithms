public class CircDoubleLinkedList {

    class Node {

        int data;
        Node next;
        Node previous;

    }

    private Node head;
    private int size;

    //Initialization
    CircDoubleLinkedList(){

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
            System.out.println("The list is Empty!");
            return;
        }

        Node currentNode = head;

        for(int i = 0; i < size; i++){
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

            if(isEmpty()){

                head = newNode;
                newNode.next = head;

            } else {

                newNode.next = head;

                Node temp = newNode.next;
                temp.previous = newNode;

                head = newNode;

                temp.next = head;

            }

        } else if(loc == size){

            Node currentNode = head;

            do currentNode = currentNode.next; while(currentNode.next != head);

            newNode.previous = currentNode;
            currentNode.next = newNode;

            newNode.next = head;

        } else {

            Node currentNode = head;

            for(int i = 0; i < loc - 1; i++)
                currentNode = currentNode.next;

            newNode.next = currentNode.next;

            currentNode.next = newNode;

            newNode.previous = currentNode;

            Node temp = newNode.next;
            temp.previous = newNode;

        }

        size++;

    }

    //Deleting Node(s)
    public void delete(int loc){

        if(isEmpty()){
            System.out.println("List is Empty!");
            return;
        }

        Node currentNode = head;
        Node previousNode = head;

        if(loc == size){

            if(size == 1)
                head = null;
            else {

                Node last = head;

                do last = last.next; while (last.next != head);

                head = head.next;

                Node temp = head;
                temp.previous = null;

                last.next = head;

            }

        } else if(loc == size){

            for(int i = 0; i < size - 1; i++){


                currentNode = currentNode.next;

                if(i == 0) continue;

                previousNode = previousNode.next;

            }

            previousNode.next = head;

            currentNode.next = null;
            currentNode.previous = null;

        } else {

            for(int i = 0; i < loc; i++){

                currentNode = currentNode.next;

                if(i == 0) continue;

                previousNode = previousNode.next;

            }

            previousNode.next = currentNode.next;

            Node temp = currentNode.next;
            temp.previous = previousNode;

        }

        size--;

    }

}
