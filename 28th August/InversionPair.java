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
            sb.append(inversionPair(arr)).append('\n');
        }
        System.out.println(sb);
    }

    public static int inversionPair(int[] arr) {
        int temp[] = new int[arr.length];
        return mergeSort(arr,temp,0,arr.length-1);
    }

    static int mergeSort(int arr[], int temp[], int left, int right)
    {
        int mid, inv_count = 0;
        if (right > left) {
            mid = (right + left)/2;
            inv_count  = mergeSort(arr, temp, left, mid);
            inv_count += mergeSort(arr, temp, mid+1, right);
            inv_count += merge(arr, temp, left, mid+1, right);
        }
        return inv_count;
    }

    static int merge(int arr[], int temp[], int left, int mid, int right) {
        int i, j, k;
        int inv_count = 0;

        i = left;
        j = mid;
        k = left;
        while ((i <= mid - 1) && (j <= right)) {
            if (arr[i] <= arr[j])   temp[k++] = arr[i++];
            else {
                temp[k++] = arr[j++];
                inv_count = inv_count + (mid - i);
            }
        }
        while (i <= mid - 1)            temp[k++] = arr[i++];

        while (j <= right)            temp[k++] = arr[j++];

        for (i=left; i <= right; i++) arr[i] = temp[i];

        return inv_count;
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