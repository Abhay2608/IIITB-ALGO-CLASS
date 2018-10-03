//O(1) space
//O(N) time


#include <stdio.h>
#include <stdlib.h>

void fib_3variables(int n){
    int a=0,b=1,c=n,i;
    for(i=2;i<=n;i++){
        c = (a+b)% (10000007);
        a = b;
        b = c;
    }
    printf("%d",c);
}


int main()
{
    int n;
    scanf("%d",&n);
    fib_3variables(n);
    return 0;
}
