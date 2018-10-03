/*variation 2:
	max: arr[j] - arr[i]
	Constraints:  j>i and j<i+l    or   j-l < i < j
	Description: Sell the stock by keeping it for almost l days i.e. sell the stock before l days
*/


#include <stdio.h>
#include <stdlib.h>

int main(){
	int t,i,j,n,l,max,*arr,*d;
	scanf("%d",&t);
	while(t-- > 0){
		scanf("%d %d",&n,&l);
		arr = (int *)malloc(n * sizeof(int));
		d = (int *)malloc(n * sizeof(int));
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		
		i = 0;
		max = 0;
		int head = 0;
		int tail = -1;
		d[0] = 0;

		for(j=1;j<n;j++){
			if(arr[j] - arr[i] > max)
				max = arr[j] - arr[i];

			while(arr[d[head]] > arr[j] && head >= tail)
				head--;

			d[++head] = j;

			if(j > i+l-1)
				i = d[++tail];
		}
		printf("%d\n",max);
	}
}
