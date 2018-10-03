//O(N) space
//O(N) time


#include <stdio.h>
#include <stdlib.h>

void fib_dp(int n){
    int *f,i;
    f = (int *)malloc((n+1) * sizeof(int));
    f[0] = 0;
    f[1] = 1;
    for(i = 2;i<=n;i++){
        f[i] = ( f[i-1] + f[i-2] ) %(10000007);
    }
    printf("%d",f[n]);
}


int main()
{
    int n;
    scanf("%d",&n);
    fib_dp(n);
    return 0;
}
