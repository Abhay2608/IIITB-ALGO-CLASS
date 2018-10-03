//no restriction on i and j
//basic variation
//description: maximum difference between the elements such that the larger number appears after the smaller number

#include <stdio.h>
#include <stdlib.h>

int main(){
	int t,n,*arr,i,j,max,min_so_far;
	scanf("%d",&t);
	while(t-- >0){
		scanf("%d",&n);
		arr = (int *)malloc(n * sizeof(int));
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);

		max = 0;
		i=0;
		for(j=1;j<n;j++){
			if((arr[j] - arr[min_so_far]) > max)
				max = arr[j] - arr[min_so_far];

			if(arr[j] < arr[min_so_far])
				min_so_far = j;
		}
		printf("%d\n",max);
	}
	return 0;
}
