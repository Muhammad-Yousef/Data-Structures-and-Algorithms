class Node:

    def __init__(self):
        self.data = None
        self.Previous = None
        self.Next = None

class CircDoubleLinkedList:

    def __init__(self):
        self.head = None
        self.size = 0

    #Check whether the list is Empty or not
    def isEmpty(self):
        return self.head == None

    #Traversing The List
    def traverse(self):

        if self.isEmpty():
            print("The list is Empty!")
            return

        currentNode = self.head

        for i in range(self.size):
            print(currentNode.data, end = " -> ")
            currentNode = currentNode.Next;

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

                temp = newNode.Next
                temp.Previous = newNode

                self.head = newNode

                temp.Next = self.head

        elif (loc == size):

            currentNode = self.head.Next

            while currentNode.Next != self.head:
                currentNode = currentNode.Next

            newNode.Previous = currentNode
            currentNode.Next = newNode

            newNode.Next = self.head

        else:

            currentNode = self.head

            for i in range(loc - 1):
                currentNode = currentNode.Next

            newNode.Next = currentNode.Next

            currentNode.Next = newNode

            newNode.Previous = currentNode

            temp = newNode.Next
            temp.Previous = newNode

        self.size += 1


    #Deleting Node(s)
    def delete(self, loc):

        if self.isEmpty():
            print("List is Empty!")
            return

        currentNode = self.head
        previousNode = self.head

        if loc == 0:

            if self.size == 1:
                self.head = None
            else:

                last = self.head.Next

                while last.Next != self.head:
                    last = last.Next

                self.head = self.head.Next

                temp = self.head
                temp.Previous = None

                last.Next = self.head

        elif loc == size:

            for i in range(size - 1):

                currentNode = currentNode.Next
                if i == 0: continue
                previousNode = previousNode.Next

            previousNode.Next = self.head

            currentNode.Next = None
            currentNode.Previous = None

        else:

            currentNode = self.head
            previousNode = self.head

            for i in range(loc):

                currentNode = currenNode.Next
                if i == 0: continue
                previousNode = previousNode.Next


            previousNode.Next = previousNode.Next

            temp = currentNode.Next
            temp.Previous = previousNode

        self.size -= 1

            
            
