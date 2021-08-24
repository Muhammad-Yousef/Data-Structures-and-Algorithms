class Node:

    def __init__(self):
        self.data = None
        self.left = None
        self.right = None

class Tree:

    def __init__(self):
        self.Root = Node()

    #Check whether the tree is Empty or not
    def isEmpty(self):
        return self.Root == None

    #Inorder Traversal
    def traverseInorder(self, root):

        if self.isEmpty():
            print("Tree is Empty!")
            return

        if root.left:
            self.traverseInorder(root.left)

        print(f"{root.data} -> ", end = "")
            
        if root.right:
            self.traverseInorder(root.right)

    #Preorder Traversal
    def traversePreorder(self, root):

        if self.isEmpty():
            print("Tree is Empty!")
            return

        print(f"{root.data} -> ", end = "")

        if root.left:
            self.traversePreorder(root.left)

        if root.right:
            self.traversePreorder(root.right)

    #Preorder Traversal
    def traversePostorder(self, root):

        if self.isEmpty():
            print("Tree is Empty!")
            return

        if root.left:
            self.traversePreorder(root.left)

        if root.right:
            self.traversePreorder(root.right)

        print(f"{root.data} -> ", end = "")

    #Inserting To The Left
    def insertLeft(self, root, x):

        #Creating New Node
        newNode = Node()
        newNode.data = x

        #Assigning Left Link
        root.left = newNode

    #Inserting To The Left
    def insertRight(self, root, x):

        #Creating New Node
        newNode = Node()
        newNode.data = x

        #Assigning Right Link
        root.right = newNode


    #Check Whether It Is A Full-Binary Tree
    def isFullBinaryTree(self, root):

        if root == None:
            return True

        if root.left == None and root.right == None:
            return True

        if root.left and root.right:
            return self.isFullBinaryTree(root.left) and self.isFullBinaryTree(root.right)

        return False

#Driver Program
T = Tree()
T.Root.data = 1

T.insertLeft(T.Root, 2);
T.insertRight(T.Root, 3);
T.insertLeft(T.Root.left, 4);
T.insertRight(T.Root.left, 5);

print("Inorder Traversal: ");
T.traverseInorder(T.Root);

print("\nPreorder Traversal: ");
T.traversePreorder(T.Root);

print("\nPostorder Traversal: ");
T.traversePostorder(T.Root);
