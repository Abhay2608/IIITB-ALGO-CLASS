#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
	return a>b?a:b;
}
int main(){
	int t,i,n,*arr,g_max,l_max;
	scanf("%d",&t);
	while(t-- > 0){
		scanf("%d",&n);
		arr = (int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);

		l_max = arr[0];
		g_max = arr[0];

		for(i=1;i<n;i++){
			l_max = max(arr[i]+l_max,arr[i]);
			g_max = max(l_max,g_max);
		}
		printf("%d\n",g_max);
	}
return 0;
}
