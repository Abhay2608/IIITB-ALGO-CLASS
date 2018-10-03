#include<stdio.h>
#include<stdlib.h>

void matrix_multiply(int **A,int **B){
//	int C[2][2];
	A[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0]; 
	A[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
	A[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
	A[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][0];
}

int main(){
	int k;
	scanf("%d",&k);

	int *N = (int *)malloc(k * sizeof(int));
	int i,j;
	for(i=0;i<k;i++){
		scanf("%d",&N[i]);
	}
	int **A = (int **)malloc(2 * sizeof(int *));
	int **y = (int **)malloc(2 * sizeof(int *));

	for(j=0;j<2;j++){
		A[j] = (int *)malloc(2 * sizeof(int));
		y[j] = (int *)malloc(2 * sizeof(int));
	}
 
	while(i<k){
		if(N[i] == 1)	matrix_multiply(&*y,&*A);
		matrix_multiply(&*A,&*A);
		i = i + 1;
	}
	printf("%d",A[0][0] + A[0][1]);

return 0;
}
