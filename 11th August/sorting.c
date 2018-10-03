#include <stdio.h>
#include <stdlib.h>

void swap(int *xp,int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int *arr,int n){
    int i,j;
    for(i= 0;i<n-1;i++)
        for(j=0; j< n-1-i;j++)
            if(arr[j] > arr[j+1])
                swap(&arr[j],&arr[j+1]);
}

void insertionSort(int *arr,int n){
    int i,j,key;

    for(i = 1; i < n; i++){

        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j--];
        }
        arr[j+1] = key;
    }
}

void selectionSort(int *arr,int n){
    int i,j,min;
    for(i = 0; i < n; i++){
        min = i;
        for(j = i; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(arr[min] < arr[i]){
            swap(&arr[min],&arr[i]);
        }
        
    }
}

void merge(int *arr,int l,int m,int r){
        int *temp = (int *)malloc((r-l+1) * sizeof(int));
        int i = l;
        int j = m+1;
        int a = 0;
        
        while(i <= m && j <= r){
            if(arr[i] <= arr[j])    temp[a++] = arr[i++];
            else    temp[a++] = arr[j++];
        }
        
        while(i <= m)   temp[a++] = arr[i++];
        while(j <= r)   temp[a++] = arr[j++];
        
        a = 0;i = l;
        while(i <= r)   arr[i++] = temp[a++];
}

void mergeSort(int *arr,int i,int j){
    if(i < j){   //more than one element
        int k = (i+j)/2;
        mergeSort(arr,i,k);
        mergeSort(arr,k+1,j);
        merge(arr,i,k,j);
    }
}

int partition(int *arr,int i,int j,int pivot){
    int l = i;
    int r = j;
    while(l <= r){
        while(l <= r && arr[l] <= pivot)    l++;
        while(l <= r && arr[r] >= pivot)    r--;
        
        if(l <= r){
            swap(&arr[l],&arr[r]);
            l++;
            r--;
        } 
    }
    return r;
}

void quickSort(int *arr,int i,int j){
    if(i < j){  //more than one element
        int p = i + ( rand() % (j-i+1) );
        swap(&arr[i],&arr[p]);
        int k = partition(arr,i+1,j,arr[i]);
        swap(&arr[i],&arr[k]);
        
        quickSort(arr,i,k-1);
        quickSort(arr,k+1,j);
    }
}
void print(int *arr,int n){
    int i;
    for(i=0;i<n;i++)    
        printf("%d ",arr[i]);
    printf("\n");    
}

int main() {
    int t,n,*arr,i,j;
    scanf("%d",&t);
    while(t-- > 0){
        scanf("%d",&n);
        arr = (int *)malloc(n * sizeof(int));
        for(i=0;i<n;i++)    scanf("%d",&arr[i]);
        
//        bubbleSort(arr,n);
//        selectionSort(arr,n);
//        insertionSort(arr,n);
//        mergeSort(arr,0,n-1);
        quickSort(arr,0,n-1);
        print(arr,n);    
        
    }
	return 0;
}