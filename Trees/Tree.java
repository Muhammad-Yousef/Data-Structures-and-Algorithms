class Tree {

    class Node {

        int data;
        Node left;
        Node right;

    }

    private Node Root = new Node();

    Tree(int x){
        Root.data = x;
    }

    Node getRoot(){
        return this.Root;
    }

    //Check whether the tree is Empty or not
    public boolean isEmpty(){
        return Root == null;
    }

    //Inorder Traversal
    public void traverseInorder(Node root){

        if(isEmpty()){
            System.out.println("Tree is Empty!");
            return;
        }

        if(root.left != null) //For the sake of handling Segmentation Faults
            traverseInorder(root.left);

        System.out.print(root.data + " -> ");

        if(root.right != null) //For the sake of handling Segmentation Faults
            traverseInorder(root.right);

    }

    //Preorder Traversal
    public void traversePreorder(Node root){

        if(isEmpty()){

            System.out.println("Tree is Empty!");
            return;
        }

        System.out.print(root.data + " -> ");

        if(root.left != null)
            traversePreorder(root.left);

        if(root.right != null)
            traversePreorder(root.right);

    }

    //Postorder Traversal
    public void traversePostorder(Node root){

        if(isEmpty()){
            System.out.println("Tree is Empty!\n");
            return;
        }

        if(root.left != null)
            traversePostorder(root.left);

        if(root.right != null)
            traversePostorder(root.right);

        System.out.print(root.data + " -> ");

    }

    //Inserting to the Left
    void insertLeft(Node root, int x){

        //Creating New Node
        Node newNode = new Node();
        newNode.data = x;

        //Assigning Left Link
        root.left = newNode;

    }

    //Inserting To The Right
    public void insertRight(Node root, int x){

        //Creating New Node
        Node newNode = new Node();
        newNode.data = x;

        //Assigning Right Link
        root.right = newNode;

    }

    //Check Whether It Is A Full-Binary Tree
    public boolean isFullBinaryTree(Node root){

	if(root == null)
	    return true;

	if(root.left == null && root.right == null)
	    return true;

	if(root.left && root.right)
	    return isFullBinaryTree(root.left) && isFullBinaryTree(root.right);

	return false;
	
    }

}
