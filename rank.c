#include <stdio.h>
#include <stdlib.h>
int val = 0;
void swap(int *xp,int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int *arr, int i,int j,int pivot){
    int l = i;
    int r = j;
    
    while(l <= r){
        while(l <= r && arr[l] < pivot) l++;
        while(l <= r && arr[r] > pivot) r--;
        
        if(l <= r){
            swap(&arr[l],&arr[r]);
            l++;
            r--;
        }
    }
    return r;
}

int FindRank(int *arr,int i,int j,int r){
    if(i < j){
        int p = i + rand() % (j-i+1);
        int k = partition(arr,i,j,arr[p]);
        swap(&arr[i],&arr[k]);
        
        
        if(r == j-k+1)  return arr[k];
        else if(r > j-k+1)  FindRank(arr,i,k-1,r-(j-k+1));
        else FindRank(arr,k+1,j,r);
    }
}

int main()
{
    int n,i,*arr,r,k;
    scanf("%d",&n);
    scanf("%d",&r);
    arr = (int *)malloc(n * sizeof(int));
    
    for(i = 0; i < n; i++ )
        scanf("%d",&arr[i]);
    
    k = FindRank(arr,0,n-1,r);
    
    printf("\nValue: %d",k);
    
    return 0;
}
