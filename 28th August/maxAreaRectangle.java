/*

Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.

 



Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. The elements of the array represents the height of the bars.


Output:
In each seperate line the maximum rectangular area possible from the contigous bars.


Constraints:
1<=T<=30
1<=N<=100
1<=A[i]<=1000


Example:
Input: 
1
7
6 2 5 4 5 1 6

Output:
12

*/


import java.lang.*;
import java.io.*;

public class GFG {
    public static void main(String[] args) {
        FastReader reader = new FastReader();
        StringBuilder sb = new StringBuilder();
        int t = reader.nextInt();
        int n;
        while(t-- > 0){
            n = reader.nextInt();
            int arr[] = new int[n];

            for(int i=0;i<n;i++)    arr[i] = reader.nextInt();
            sb.append(rectangleArea(arr)).append('\n');
        }
        System.out.println(sb);
    }

    public static int rectangleArea(int[] arr) {
        Stack<Integer> s = new Stack<Integer>();
        int i=0,area = 0,max = 0;
        while(i <arr.length){
            if(s.empty() || arr[i] >= arr[s.peek()]){
                s.push(i++);
            }
            else{
                int t = s.pop();

                if(s.empty()){
                    area = i*arr[t];
                }
                else{
                    area = arr[t]*(i-s.peek()-1);
                }
                max = Integer.max(area,max);
            }
        }
        while(!s.isEmpty()){
            int t = s.pop();

            if(s.empty()){
                area = i*arr[t];
            }
            else{
                area = arr[t]*(i-s.peek()-1);
            }
            max = Integer.max(area,max);
        }
        return max;
    }
}


class FastReader {
    BufferedReader br;
    StringTokenizer st;

    public FastReader(){
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    String next(){
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            }
            catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt(){        return Integer.parseInt(next());    }

    long nextLong()    {        return Long.parseLong(next());    }

    double nextDouble()    {        return Double.parseDouble(next());    }

    String nextLine(){
        String str = "";
        try{
            str = br.readLine();
        }
        catch (IOException e){
            e.printStackTrace();
        }
        return str;
    }
}