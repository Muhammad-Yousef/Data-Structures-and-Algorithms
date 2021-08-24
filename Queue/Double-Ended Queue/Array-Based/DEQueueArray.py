class DEQueueArray:

    def __init__(self, n):
        self.SIZE = n
        self.elements = [0] * self.SIZE
        self.FRONT = -1
        self.REAR = -1

    #Check whether the Queue is Empty or not
    def isEmpty(self):
        return self.FRONT == -1

    #check whether the Queue is Full or not
    def isFull(self):
        return self.REAR == self.FRONT - 1 or self.FRONT == 0 and self.REAR == self.SIZE - 1

    #Insert At REAR
    def insertREAR(self, x):

        if self.isFull():
            printf("Queue is Full!")
            return

        print("\nBefore Inserting At REAR: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))

        if self.isEmpty():

            self.FRONT += 1
            self.REAR += 1
            self.elements[self.REAR] = x

        elif self.REAR == self.SIZE - 1:

            self.REAR = 0
            self.elements[self.REAR] = x

        else:

            self.REAR += 1
            self.elements[self.REAR] = x
        
        print("After Inserting At REAR: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))


    #Insert At FRONT
    def insertFRONT(self, x):

        if self.isFull():
            print("Queue is Full!")
            return

        print("\nBefore Inserting At FRONT: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))

        if self.isEmpty():

            self.FRONT += 1
            self.REAR += 1

            self.elements[self.FRONT] = x

        elif self.FRONT == 0:

            self.FRONT = self.SIZE - 1
            self.elements[self.FRONT] = x

        else:

            self.FRONT -= 1
            self.elements[self.FRONT] = x
        
        print("After Inserting At FRONT: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))


    #Deleting From Front
    def deleteFRONT(self):

        if self.isEmpty():
            print("Queue is Empty!")
            return

        print("\nBefore Deleting FROM FRONT: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))
        self.elements[self.FRONT] = 0

        if self.FRONT == self.REAR:

            self.FRONT = -1
            self.REAR = -1

        elif self.FRONT == self.SIZE - 1:

            self.FRONT = 0

        else:

            self.FRONT += 1
        
        print("After Deleting FROM FRONT: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))


    #Deleting From REAR
    def deleteREAR(self):

        if self.isEmpty():
            print("Queue is Empty!")
            return

        print("\nBefore Deleting FROM REAR: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))
        self.elements[self.REAR] = 0

        if self.FRONT == self.REAR:

            self.FRONT = -1
            self.REAR = -1

        elif self.REAR == 0:

            sel.REAR = self.SIZE - 1

        else:

            self.REAR -= 1
        
        print("\nBefore Deleting FROM REAR: FRONT = {} and REAR = {}".format(self.FRONT, self.REAR))
