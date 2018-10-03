/*
                                    
The cost of stock on each day is given in an array A. Find all the days on which you buy and sell the stock so that in between those days you shouldn't have any loss.

Input: 
First line contains number of test cases T. Each test case contains the integer value N denoting days followed by an array of stock prices of N days. 

Output:
For each testcase, output all the days with profit in a single line. And if there is no profit then print "No Profit".

Constraints:
1 <= T <= 100
2 <= N <= 103
1 <= Ai <= 104

Example
Input:
2
7
100 180 260 310 40 535 695
10
23 13 25 29 33 19 34 45 65 67

Output:
(0 3) (4 6)
(1 4) (5 9)


*/

#include <stdlib.h>
#include <stdio.h>

struct Interval
{
    int buy;
    int sell;
};

int main() {
    int t,i,j,n,*arr,counter;
    struct Interval *sol;
    scanf("%d",&t);
    while(t-- > 0){
      scanf("%d",&n);
      counter = 0;
      arr = (int *)malloc(n * sizeof(int));
      sol = (struct Interval *)malloc((n/2 + 1) * sizeof(struct Interval));
      for(i=0;i<n;i++)  scanf("%d",&arr[i]);
      
      if(n == 1)    printf("No Profit\n");
      else{
            int max=0;
            i=0;
            for(j=1;j<n;j++){
                if(arr[i] > arr[j]) i = j;
                while((j+1) < n && arr[j] < arr[j+1])   j++;
                    if(i != j){
                        sol[counter].buy = i;
                        sol[counter++].sell = j;
                    }
                i = j;
            }
            if(counter == 0)    printf("No Profit");
            else{
                for(i=0;i<counter;i++){
                    printf("(%d %d) ",sol[i].buy,sol[i].sell);
                }
            }
            printf("\n");
        }
    }
	return 0;
}