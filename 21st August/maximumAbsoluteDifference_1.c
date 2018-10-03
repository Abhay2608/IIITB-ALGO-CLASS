/*variation 1
	max : arr[j]-arr[i]
	Constraints: 1. j>= i+l
		     2. 1<=l<=n-1
	Description: Sell the stock after keeping the stock for at least l days
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int t,i,n,j,max,*arr,l,min_so_far;
	scanf("%d",&t);
	while(t-- > 0){
		scanf("%d %d",&n,&l);
		arr = (int *)malloc(n * sizeof(int));
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		
		max = 0;
		min_so_far = 0;
		for(j=l;j<n;j++){
			if((arr[j] - arr[min_so_far]) > max)
				max = arr[j] -arr[min_so_far];

			if(arr[j-l+1] < arr[min_so_far])
				min_so_far = j-l+1;
		}
		printf("%d\n",max);
	}
}
