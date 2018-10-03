//check

#include <stdio.h>
#include <stdlib.h>

int main(){
	int t,i,j,n,*arr,*p,max;
	scanf("%d",&t);
	while(t-- > 0){
		scanf("%d",&n);
		arr = (int *)malloc(n*sizeof(int));
		p = (int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);

		p[0] = arr[0];
		for(i=1;i<n;i++)
			p[i] = p[i-1] + arr[i];

		max = p[0];
		i = 0;
		for(j=1;j<n;j++){
			if(p[j] -p[i] > max)
				max = p[j] - p[i];
			if(p[j] < p[i])
				i = j;
		}
		printf("%d\n",max);

	}
}
