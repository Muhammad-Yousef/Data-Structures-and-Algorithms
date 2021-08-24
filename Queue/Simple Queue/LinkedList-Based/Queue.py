# Establishing Node
class Node:

    def __init__(self):
        self.data = None
        self.Next = None


# Establishing Queue
class Queue:

    # Initialization
    def __init__(self):
        self.head = None
        self.size = 0

    # Check whether the Queue is Empty or not
    def isEmpty(self):
        return self.head == None

    # Displaying The Queue
    def display(self):

        if self.isEmpty():
            print("Queue is Empty!")
            return

        currentNode = self.head

        while (currentNode != None):
            print("{} <- ".format(currentNode.data), end = "")
            currentNode = currentNode.Next

        print()

    # Enqueue
    def Enqueue(self, x):

        newNode = Node()

        newNode.data = x

        currentNode = self.head

        if self.isEmpty():

            newNode.Next = self.head
            self.head = newNode

        else:

            for i in range(self.size - 1):
                currentNode = currentNode.Next

            newNode.Next = currentNode.Next
            currentNode.Next = newNode

        self.size += 1

    # Dequeue
    def Dequeue(self):

        if self.isEmpty():

            print("Queue is Empty!")
            return -1

        else:

            currentNode = self.head

            value = currentNode.data
            self.head = currentNode.Next

        self.size -= 1

        return value

