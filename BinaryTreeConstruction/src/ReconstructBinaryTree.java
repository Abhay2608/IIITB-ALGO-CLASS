public class ReconstructBinaryTree {

    public  static  void main(String[] args){
        int[] pre = {1,2,3,4,5};
        int[] in = {4, 8, 2, 5, 1, 6, 3, 7};
        int[] post = {8, 4, 5, 2, 6, 7, 3, 1};
        /*BinaryTree root = constructInPre(pre,0,pre.length-1,in,0,in.length-1);
        root.preOrder();
        System.out.println("\n");
        root.inOrder();*/
        int[] postEnd = new int[1];
        postEnd[0] = post.length-1;
        BinaryTree root = constructInPost(in,post,0,in.length-1,postEnd);
        //root.inOrder();
        root.postOrder();
    }

    public static BinaryTree constructInPost(int[] inorder, int[] postorder, int inStart, int inEnd, int[] postEnd){
        if(postEnd[0] < 0 || inStart > inEnd) return null;

        int val = postorder[postEnd[0]];

        int rootIndex = 0;
        for(int i=inStart;i<=inEnd;i++){
            if(inorder[i] == val){
                rootIndex = i;
                break;
            }
        }
        BinaryTree root = new BinaryTree(postorder[postEnd[0]]);
        postEnd[0] = postEnd[0] - 1;

        //root.left = construct1(inorder,postorder,inStart,inStart+rootIndex-1,postEnd-1+rootIndex-inEnd);
        root.right = constructInPost(inorder,postorder,rootIndex+1,inEnd,postEnd);
        root.left = constructInPost(inorder,postorder,inStart,rootIndex-1,postEnd);
        return root;
    }
    public static BinaryTree constructInPre(int[] pre,int preStart,int preEnd,int[] in,int inStart,int inEnd){
        if(preStart>preEnd || inStart > inEnd)  return  null;

        int val = pre[preStart];

        int rootIndex = 0;
        for(int i=inStart;i<inEnd;i++){
            if(in[i] == val){
                rootIndex = i;
                break;
            }
        }
        BinaryTree tree = new BinaryTree(val);
        tree.left = constructInPre(pre,preStart+1,preStart+(rootIndex-inStart),in,inStart,(rootIndex-1));
        tree.right = constructInPre(pre,preStart+(rootIndex-inStart)+1,preEnd,in,rootIndex+1,inEnd);
        return tree;
    }
}
