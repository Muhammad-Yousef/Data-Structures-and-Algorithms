# Establishing Node
class Node:

    def __init__(self):
        self.data = None
        self.Next = None


# Establishing List
class PQList:

    # Initializing List
    def __init__(self, num):
        self.head = None
        self.size = 0
        self.MAX = num
        self.FRONT = -1
        self.REAR = -1

    # Check whether the Queue is Empty or not
    def isEmpty(self):
        return self.REAR == -1

    #Check whether the Queue is Full or not
    def isFull(self):
        return self.REAR == self.MAX - 1

    # Displaying The Queue
    def display(self):

        if (self.isEmpty()):
            print("Queue is Empty!")
            return

        currentNode = self.head

        while (currentNode != None):
            print(currentNode.data, end=" -> ")
            currentNode = currentNode.Next;

        print()

    # Inserting Node(s)
    def insert(self, x, loc):

        newNode = Node()
        newNode.data = x

        if loc == 0:

            newNode.Next = self.head
            self.head = newNode;

        else:

            if loc > self.size:
                print("The list is only {} nodes".format(self.size))
                return

            currentNode = self.head

            for i in range(loc - 1):
                currentNode = currentNode.Next

            newNode.Next = currentNode.Next
            currentNode.Next = newNode

        self.size += 1

    # Deleting Node(s)
    def delete(self, loc):

        if (self.isEmpty()):
            print("Queue is Already Empty!")
            return

        if (loc > self.size - 1):
            print("The list is only {} nodes!".format(self.size))
            return

        currentNode = self.head
        previousNode = self.head

        if loc == 0:

            self.head = currentNode.Next

        elif loc == self.size - 1:

            for i in range(loc - 1):
                currentNode = currentNode.Next

            currentNode.Next = None

        else:

            for i in range(loc):

                currentNode = currentNode.Next

                if i == 0:
                    continue

                previousNode = previousNode.Next

            previousNode.Next = currentNode.Next

        self.size -= 1

    # Dequeue
    def Dequeue(self):

        if self.isEmpty():
            print("Queue is Empty!")
            return

        self.delete(self.REAR)
        self.REAR -= 1

    # Enqueue
    def Enqueue(self, x):

        # check whether the Queue is Full or not
        if self.isFull():
            print("Queue is Full!")
            return

        last = self.head

        # Keeping track of the last node
        if last != None:
            for i in range(1, self.size, 1):
                last = last.Next

        if self.isEmpty():  # Inserting as the first node

            self.FRONT += 1
            self.REAR += 1

            self.insert(x, self.REAR)

        elif x < self.head.data:  # Inserting at First

            self.insert(x, self.FRONT)
            self.REAR += 1

        elif x > last.data:  # Inserting at last

            self.REAR += 1
            self.insert(x, self.REAR)

        elif x > self.head.data and x < last.data:  # Inserting at location in between

            currentNode = self.head.Next

            i = 1

            while x > currentNode.data:
                currentNode = currentNode.Next
                i += 1

            self.REAR += 1

            self.insert(x, i)


p = PQList(5);

p.display();

p.Enqueue(3);
p.display();

p.Enqueue(2);
p.display();

p.Enqueue(5);
p.display();

p.Enqueue(4);
p.display();

p.Enqueue(1);
p.display();

p.Dequeue();
p.display();

p.Dequeue();
p.display();

p.Dequeue();
p.display();

p.Dequeue();
p.display();

p.Dequeue();
p.display();
