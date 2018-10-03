#include <stdlib.h>
#include <stdio.h>
int compare_ints (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

void keyPair(int *arr,int n,int x){
    int l = 0;
    int r = n-1;
    while(l <= r){
        if(arr[l] + arr[r] == x)    {
            printf("Yes\n");
            return;
        }
        else if(arr[l] + arr[r] < x)    l++;
        else    r--;
    }
    printf("No\n");
    return;
}

void printArray(int *arr, int n){
    int i;
    for(i=0;i<n;i++)    
        printf("%d ",arr[i]);
    
    printf("\n");
}
int main() {
	int t,n,*arr,i,l,r,x;
	scanf("%d",&t);
	while(t-- > 0){
	    scanf("%d %d",&n,&x);
	    arr = (int *)malloc(n * sizeof(int));
	    
	    for(i = 0; i < n; i++)  
	        scanf("%d",&arr[i]);
	    
	    qsort(arr, n, sizeof(int), compare_ints);
	   // printArray(arr,n);
	    keyPair(arr,n,x);
	}
	return 0;
}