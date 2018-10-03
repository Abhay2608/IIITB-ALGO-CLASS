//program to get fibonacci of a number using matrix multiplication 

#include<stdio.h>
#include<stdlib.h>

void matrix_multiply(int **O,int **P){
    int res[2][2],i,j,k;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < 2; k++)
                res[i][j] += O[i][k]*P[k][j];
        }
    
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            O[i][j] = res[i][j];
            
}

int main(){
    
    int length = 0;
    char c[3200];
    printf("Enter in decimal format:");
    scanf("%s",c);
    int i,j;
    for(i=0;c[i] != '\0';i++){
        length = i;
    }
    
    
    int **A = (int **)malloc(2 * sizeof(int *));
    int **X = (int **)malloc(2 * sizeof(int *));
    int **y = (int **)malloc(2 * sizeof(int *));

    for(j=0;j<2;j++){
        A[j] = (int *)malloc(2 * sizeof(int));
        y[j] = (int *)malloc(2 * sizeof(int));
        X[j] = (int *)malloc(2 * sizeof(int));
    }
    y[0][0] = 1; y[0][1] = 0;
    y[1][0] = 0; y[1][1] = 1;
    
    A[0][0] = 1; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 0;
    
    X[0][0] = 1; X[0][1] = 1;
    X[1][0] = 1; X[1][1] = 0;
    
    i = length;
    while(i >= 0){
        if(c[i] != '1')    {
            int x = c[i] - '0';
            while(x > 0){
                matrix_multiply(&*y,&*A);
                x = x - 1;
            }
            
        }
            matrix_multiply(&*A,&*A);
            matrix_multiply(&*A,&*A);
            matrix_multiply(&*A,&*A);
            matrix_multiply(&*A,&*X);
            matrix_multiply(&*A,&*X);
        i = i - 1;
    }
    printf("%d\n",y[0][1]);
    free(A);
    free(y);

return 0;
}