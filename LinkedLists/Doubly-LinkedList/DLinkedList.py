#Establishing Node
class Node:

    def __init__(self):
        self.data = None
        self.Previous = None
        self.Next = None

#Establishing List
class LinkedList:

    #Initializing List
    def __init__(self):
        self.head = None
        self.size = 0


    #Check whether the list is Empty or not
    def isEmpty(self):
        return self.head == None


    #Traversing The List
    def traverse(self):

        if(self.isEmpty()):
            print("List is Empty!")
            return

        currentNode = self.head
        
        while(currentNode != None):
            print(currentNode.data, end = " -> ")
            currentNode = currentNode.Next;

        print()


    #Inserting Node(s)
    def insert(self, x, loc):

        newNode = Node()
        newNode.data = x

        if loc == 0:

            newNode.Previous = self.head
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

            if loc < self.size - 1:
                currentNode.Next.Previous = newNode

            currentNode.Next = newNode
            newNode.Previous = currentNode

        self.size += 1


    #Deleting Node(s)
    def delete(self, loc):

        if(self.isEmpty()):

            print("List is Already Empty!")
            return

        if(loc > self.size - 1):
            print("The list is only {} nodes!".format(self.size))
            return

        currentNode = self.head

        if loc == 0:

            self.head = currentNode.Next
            currentNode.Previous = None

        elif loc == self.size - 1:
            
            for i in range(loc - 1):
                currentNode = currentNode.Next

            currentNode.Next = None
            
        else:

            for i in range(loc):

                currentNode = currentNode.Next

                
            currentNode.Previous.Next = currentNode.Next
            currentNode.Next.Previous = currentNode.Previous

        self.size -= 1
