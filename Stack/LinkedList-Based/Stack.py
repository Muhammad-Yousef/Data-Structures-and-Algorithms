#Establishing Node
class Node:

    def __init__(self):
        self.data = None
        self.Next = None


#Establishing The Stack
class Stack:

    #Initialization
    def __init__(self):
        self.head = None
        self.size = 0


    #Check whether the Stack is Empty or not
    def isEmpty(self):
        return self.head == None

    #Display The Stack
    def display(self):

        if self.isEmpty():
            print("Stack is Empty!")
            return

        currentNode = self.head

        while currentNode != None:
            print("[{}]".format(currentNode.data))
            currentNode = currentNode.Next

        print()


    #Peek
    def peek(self):

        if self.isEmpty():
            print("Stack is Empty!")
            return

        print("{}".format(self.head.data))
        print()


    #Pushing
    def push(self, x):

        newNode = Node()

        newNode.data = x
        newNode.Next = self.head

        self.head = newNode

        self.size += 1


    #Popping
    def pop(self):

        if self.isEmpty():

            print("Stack is Empty!")
            value = -1

        else:

            currentNode = self.head

            self.head = currentNode.Next
            value = currentNode.data

        self.size -= 1

        return value
