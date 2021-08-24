# Establishing Stack
class StackArray:

    # Initialization
    def __init__(self):
        self.elements = []

    # Display The Stack
    def display(self):
        print(self.elements)

    # Peek
    def peek(self):
        print("{}".format(self.elements[-1]))

    # Pushing
    def push(self, x):
        self.elements.append(x)

    # Popping
    def pop(self):
        return self.elements.pop()
