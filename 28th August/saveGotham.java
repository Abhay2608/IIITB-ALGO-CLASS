/*
find nextbigger element

findnext smaller


stack.push(0);
for(j=1;j<n;j++){
	while(!stack.empty() && a[j] <a [i]){
		min[i] = j;
		stack.pop();
		i = stack.top();
	}
	stack.push(j);
}

while(!stack.empty()){
	min[stack.pop()] = 0;
}

*/
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    int n = sc.nextInt();
		    Stack<Integer> st = new Stack<Integer>();
		    int tower[] = new int[n];
		    int S[] = new int[n];
		    for(int i=0;i<n;i++)
		        tower[i] = sc.nextInt();
		    
		    st.push(0);
		    
		    for(int i=1;i<n;i++){
		        while(!st.empty() &&  tower[i] > tower[st.peek()]){
		            S[st.peek()] = tower[i];
		            st.pop();
		        }
		        st.push(i);
		    }
		    long sum = 0;
		    long mod = 1000000001;
		    for(int i=0;i<n;i++)
		        sum = (sum + S[i]) % mod;
		    
		    System.out.println(sum);
	    }
	    
	}
}