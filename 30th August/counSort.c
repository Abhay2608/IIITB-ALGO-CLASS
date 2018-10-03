 #include<stdio.h>
 #include<stdlib.h>
 #include<limits.h>
 
 void countSort(int arr[],int b[],int count[],int n,int min,int max){
         int i,j;
         for(i=0;i<n;i++)        {
             count[arr[i]]++;
         }
         for(i=1;i<max;i++){
              count[i] += count[i-1];
         }   
         printf("--\n");
         for(j=n-1;j>=0;j--)     {
             b[--count[arr[j]]] = arr[j];
         }
         for(i=0;i<n;i++)        printf("%d ",b[i] = b[i] + min);
 }
 
 
 int main(){
         int i,max = INT_MIN,n,*arr,*count,*b,min = INT_MAX;
         scanf("%d",&n);
         arr = (int *)malloc(n * sizeof(int));
         b = (int *)malloc(n * sizeof(int));
 
         for(i=0;i<n;i++){
                 scanf("%d",&arr[i]);
                 if(max < arr[i])        max = arr[i];
                 if(min > arr[i])        min = arr[i];
         }
         if(min < 0){
                 max = max - min;
                 for(i=0;i<n;i++)        arr[i] += -min;
         }
         else    min = 0;
 
         count = (int *)malloc(max+1 * sizeof(int));
         countSort(arr,b,count,n,min,max+1);
 
 }

