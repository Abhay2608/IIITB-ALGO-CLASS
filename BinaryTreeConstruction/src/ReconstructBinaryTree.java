import java.util.*;

class Node {
    int data;
    Node left, right;
    public Node(int item){
        data = item;
        left = right = null;
    }
}

public class ReconstructBinaryTree {
    Node root;
    static int preIndex = 0;

    Node buildTreeInPre(int[] in, int[] pre, int inStrt, int inEnd, HashMap<Integer, Integer> map) {
        if (inStrt > inEnd)            return null;

        Node tNode = new Node(pre[preIndex++]);

        if (inStrt == inEnd)            return tNode;

        //int inIndex = search(in, inStrt, inEnd, tNode.data);
        int inIndex = map.get(tNode.data);

        tNode.left = buildTreeInPre(in, pre, inStrt, inIndex - 1, map);
        tNode.right = buildTreeInPre(in, pre, inIndex + 1, inEnd, map);

        return tNode;
    }

    Node buildTreeInPost(int[] in, int[] post, int inStrt, int inEnd, int[] pIndex, HashMap<Integer, Integer> map) {

        if (inStrt > inEnd)            return null;

        Node node = new Node(post[pIndex[0]]);
        pIndex[0] = pIndex[0] - 1;

        if (inStrt == inEnd)            return node;

        //int iIndex = search(in, inStrt, inEnd, node.data);
        int inIndex = map.get(node.data);

        node.right = buildTreeInPost(in, post, inIndex + 1, inEnd, pIndex, map);
        node.left = buildTreeInPost(in, post, inStrt, inIndex - 1, pIndex, map);

        return node;
    }

    int search(int arr[], int strt, int end, int value){
        int i;
        for (i = strt; i <= end; i++) {
            if (arr[i] == value)
                return i;
        }
        return i;
    }

    void printInorder(Node node) {
        if (node == null) return;
        printInorder(node.left);
        System.out.print(node.data + " ");
        printInorder(node.right);
    }

    public static void main(String args[]) {
        ReconstructBinaryTree tree = new ReconstructBinaryTree();
        int in[] = new int[] {4,2,5,1,6,3};
        int pre[] = new int[] {1,2,4,5,3,6};
        int post[] = new int[] {4,5,2,6,3,1};
        int len = in.length;
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();

        for(int i=0;i<in.length;i++)
            map.put(in[i],i);

        Node root = tree.buildTreeInPre(in, pre, 0, len - 1,map);
        System.out.println("Inorder traversal of constructed tree is : ");
        tree.printInorder(root);


        /*int[] postEnd = new int[1];
        postEnd[0] = post.length-1;
        Node root = tree.buildTreeInPost(in,post,0,len-1,postEnd,map);
        tree.printInorder(root);*/
    }
}