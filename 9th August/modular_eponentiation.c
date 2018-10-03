//(m * n) % p =((m % p) * (n % p)) % p

//if b is even (a ^ b) % c = ((a ^ b/2) * (a ^ b/2))%c
//if b is odd   (a ^ b) % c = (a * (a ^( b-1))%c


  //(a^b) % c
#include <stdio.h>
#include <stdlib.h>

int modular_exponentiation(int a,int b,int c){
    int i;
    if(a == 0)  return 0;
    if(b == 0)  return 1;

    //if b is even
    long y;
    if(b%2 == 0){
        y = modular_exponentiation(a,b/2,c);
        y = (y*y) % c;
    }

    //if b is odd
    else{
        y = a % c;
        y = (y * modular_exponentiation(a,b-1,c) % c) % c;
    }

    return (int)((y + c) % c);
}


int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    printf("%d",modular_exponentiation(a,b,c));
    return 0;
}
