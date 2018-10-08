public class BinaryTree {
    int value;
    BinaryTree left;
    BinaryTree right;
    public BinaryTree(int val){
        this.value = val;
        this.left = null;
        this.right = null;
    }

    public void inOrder(){
        if(this != null){
            if(this.left != null)
                left.inOrder();
            System.out.print(this.value + " ");
            if(this.right != null)
                right.inOrder();
        }
    }

    public void preOrder(){
        if(this != null){
            System.out.print(this.value + " ");
            if(this.left != null)
                left.preOrder();
            if(this.right != null)
                right.preOrder();
        }
    }

    public void postOrder(){
        if(this != null){
            if(this.left != null)
                left.postOrder();
            if(this.right != null)
                right.postOrder();
            System.out.print(this.value + " ");
        }
    }
}
