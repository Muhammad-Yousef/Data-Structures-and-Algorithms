class Queue:

    # Initializing The Queue
    def __init__(self):
        self.elements = []

    # Display The Queue
    def display(self):
        print(self.elements)

    # Peek
    def peek(self):
        print(self.elements[0]) if not len(self.elements) == 0 else print("Queue is Empty")

    # Enqueue
    def Enqueue(self, x):
        self.elements.append(x)

    # Dequeue
    def Dequeue(self):
        return self.elements.pop(0) if not len(self.elements) == 0 else print("Queue is Empty")
