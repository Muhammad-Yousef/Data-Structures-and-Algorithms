class Node:

    def __init__(self):
        self.data = None
        self.Next = None

class DEQueueList:

    def __init__(self, num):
        self.head = None
        self.size = 0
        self.MAX = num
        self.FRONT = -1
        self.REAR = -1

    #Check whether the Queue is Empty or not
    def isEmpty(self):
        return self.head == None

    #Check whether the Queue is Full or not
    def isFull(self):
        return self.size == self.MAX

    #Displaying The Queue
    def display(self):

        if self.isEmpty():
            print("Queue is Empty!");
            return

        currentNode = self.head

        for i in range(self.size):
            print(currentNode.data, end = " -> ")
            currentNode = currentNode.Next

        print()


    #Inserting Node(s)
    def insert(self, x, loc):

        newNode = Node()
        newNode.data = x

        if loc == 0:

            if self.isEmpty():

                self.head = newNode
                newNode.Next = self.head

            else:

                newNode.Next = self.head
                self.head = newNode

                currentNode = self.head

                for i in range(self.size):
                    currentNode = currentNode.Next

                currentNode.Next = self.head

        else:

            if loc > self.size:

                print("The Queue is only ", size, " nodes")
                return

            currentNode = self.head

            for i in range(loc - 1):
                currentNode = currentNode.Next

            newNode.Next = currentNode.Next
            currentNode.Next = newNode

        self.size += 1


    #Deleting Node(s)
    def delete(self, loc):

        if self.isEmpty():

            print("Queue is Empty!")
            return

        if loc > self.size - 1:

            print("The Queue is only ", self.size, "nodes")
            return

        currentNode = self.head
        previousNode = self.head

        if loc == 0:

            if self.size == 1:

                self.head = None

            else:

                self.head = currentNode.Next

                for i in range(self.size - 1):
                    currentNode = currentNode.Next

                currentNode.Next = self.head

        elif loc == self.size - 1:

            for i in range(loc - 1):
                currentNode = currentNode.Next

            currentNode.Next = self.head

        else:

            for i in range(loc):

                currentNode = currentNode.Next

                if i == 0:
                    continue

                previousNode = previousNode.Next

            previousNode.Next = currentNode.Next

        self.size -= 1

    #Insert At REAR
    def insertREAR(self, x):

        if self.isFull():
            print("Queue is Full!")
            return

        print("\nBefore Inserting At REAR: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))

        if self.isEmpty():

            self.FRONT += 1
            self.REAR += 1

            self.insert(x, self.REAR)

        elif self.REAR == self.MAX - 1:

            self.REAR = 0

            self.insert(x, self.REAR)

        else:

            self.REAR += 1

            self.insert(x, self.REAR)

        print("After Inserting At REAR: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))


    #Delete From REAR
    def deleteREAR(self):

        if self.isEmpty():
            print("Queue is Empty!")
            return

        print("\nBefore Deleting From REAR: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))

        self.delete(self.REAR)

        if self.FRONT == self.REAR:

            self.FRONT = -1
            self.REAR = -1

        elif self.REAR == 0:

            self.REAR = self.size - 1

        else:

            self.REAR -= 1

        print("After Deleting From REAR: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))

     #Insert At FRONT
    def insertFRONT(self, x):

        if self.isFull():
            print("Queue is Full!")
            return

        print("\nBefore Inserting At FRONT: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))

        if self.isEmpty():

            self.FRONT += 1
            self.REAR += 1

            self.insert(x, self.FRONT)

        elif self.FRONT == 0:

            self.FRONT = self.size

            self.insert(x, self.FRONT)

        else:

            self.insert(x, self.FRONT + 1)

        print("After Inserting At FRONT: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))


    #Delete From FRONT
    def deleteFRONT(self):

        if self.isEmpty():
            print("Queue is Empty!")
            return

        print("\nBefore Deleting From FRONT: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))

        if self.FRONT == self.REAR:

            self.delete(self.FRONT)

            self.FRONT = -1
            self.REAR = -1

        elif self.FRONT == self.size - 1:

            self.delete(self.FRONT)
            self.FRONT = 0

        elif self.FRONT > self.REAR and self.FRONT < self.size:

            self.delete(self.FRONT)

        else:

            self.delete(self.FRONT)
            self.REAR -= 1

        print("After Deleting From FRONT: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))


D = DEQueueList(5)

D.display()

D.display();

D.insertREAR(1);
D.display();

D.insertREAR(2);
D.display();

D.insertREAR(3);
D.display();

D.insertREAR(4);
D.display();

D.insertREAR(5);
D.display();

#insertREAR(q, 6); //OverFlow

D.deleteREAR();
D.display();

D.deleteREAR();
D.display();

D.insertFRONT(4);
D.display();

D.insertFRONT(5);
D.display();

#insertFRONT(q, 6); //OverFlow

D.deleteFRONT();
D.display();

D.deleteFRONT();
D.display();

D.deleteFRONT();
D.display();

D.deleteFRONT();
D.display();

D.deleteFRONT();
D.display();
