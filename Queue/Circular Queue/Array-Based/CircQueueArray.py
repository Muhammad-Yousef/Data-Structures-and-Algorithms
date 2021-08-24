class CircQueueArray:

    def __init__(self, size):
        self.MAX = size
        self.elements = [0] * size
        self.FRONT = -1
        self.REAR = -1


    #Check whether the Queue is Empty or not
    def isEmpty(self):
        return self.FRONT == -1 and self.REAR == -1

    #Check whether the Queue is Full or not
    def isFull(self):
        return self.FRONT == self.REAR + 1 or self.FRONT == 0 and self.REAR == self.MAX - 1;

    #Display
    def display(self):
        print(self.elements)


    #Enqueue
    def Enqueue(self, x):

        print("\nBefore Enqueue: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))

        if self.isFull():
            print("Queue is Full!")
            return

        if self.isEmpty():

            self.FRONT += 1
            self.REAR += 1

            self.elements[self.FRONT] = x

        else:

            self.REAR = (self.REAR + 1) % self.MAX
            self.elements[self.REAR] = x
        
        print("\nAfter Enqueue: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))


    #Dequeue
    def Dequeue(self):

        print("\nBefore Dequeue: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))

        if self.isEmpty():
            print("Queue is Empty!")
            return

        if self.FRONT == self.REAR:

            self.FRONT += 1
            self.elements[self.FRONT] = 0
            self.FRONT = -1
            self.REAR = -1

        else:

            self.elements[self.FRONT] = 0
            self.FRONT += 1
        
        print("\nAfter Dequeue: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))
