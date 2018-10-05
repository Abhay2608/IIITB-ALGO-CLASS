import java.util.*;
import java.lang.*;
import java.io.*;
class GfG {
    void printKdistance(Node root, int k){
        StringBuilder sb = new StringBuilder();
        if(k == 0){
            System.out.print(root.data);
            return;
        }
        else {
            if (root != null) {
                stackDS d;
                Queue<stackDS> q = new LinkedList<stackDS>();
                int level = 0;
                Node current = root;
                q.add(new stackDS(current, 0));
                while (!q.isEmpty()) {
                    d = q.poll();
                    current = d.n;
                    level = d.level;
                    if (level == k) {
                        System.out.print(current.data + " ");
                        //sb.append(current.data).append(" ");
                        if (current.left != null) q.add(new stackDS(current.left, level + 1));
                        if (current.right != null) q.add(new stackDS(current.right, level + 1));
                    }
                }
            }
        }
    }
}
