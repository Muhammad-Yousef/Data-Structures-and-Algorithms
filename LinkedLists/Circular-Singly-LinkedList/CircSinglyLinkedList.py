class Node:

    def __init__(self):
        self.data = None
        self.Next = None

class CircSinglyLinkedList:

    def __init__(self):
        self.head = None
        self.size = 0

    #Check whether the list is Empty or not
    def isEmpty(self):
        return self.head == None

    #Traversing The List
    def traverse(self):

        if self.isEmpty():
            print("List is Empty!");
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

                print("The list is only ", size, " nodes")
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

            print("List is Empty!")
            return

        if loc > self.size - 1:

            print("The list is only ", self.size, "nodes")
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


c = CircSinglyLinkedList()

c.traverse();

c.insert(1, 0);
c.traverse();

c.insert(2, 1);
c.traverse();

c.insert(3, 2);
c.traverse();

c.insert(5, 3);
c.traverse();

c.insert(4, 3);
c.traverse();

#c.insert(-1, 0);
#c.traverse();

c.delete(0);
c.traverse();

c.delete(3);
c.traverse();

c.delete(1);
c.traverse();

c.delete(0);
c.traverse();

c.delete(1);
c.traverse();

c.delete(0);
c.traverse();
