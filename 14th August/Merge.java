
import java.util.*;
import java.io.*;
class Merge{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
			int n = sc.nextInt();
			int[][] a = new int[n][n];
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					a[i][j] = sc.nextInt();
			GfG g = new GfG();
			ArrayList<Integer> arr= g.mergeKArrays(a, n);
			printArray(arr,n*n);
		}
	}
	public static void printArray(ArrayList<Integer> arr, int size){
		for(int i = 0; i < size ; i++)
			System.out.print(arr.get(i)+" ");
		System.out.println();
	}
}

class GfG
     {
        public static ArrayList<Integer> mergeKArrays(int[][] arrays,int k) 
          {
           ArrayList<Integer> arr = new ArrayList<Integer>();
               for(int i=0; i<k; i++){
                   for(int j=0; j<k; j++){
                       arr.add(arrays[i][j]);
                   }
               }
               Collections.sort(arr);
               return arr;
          }
}