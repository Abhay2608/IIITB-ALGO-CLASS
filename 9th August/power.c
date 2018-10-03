//fast exponentiation

#include<stdio.h>

int main(){
	unsigned long long int x = 123213;
	unsigned long long int y = 1;
	unsigned long long int n = 12234;
	while(n > 0){
		if(n % 2 == 1)	y = y*x;
		x = x*x;
		n = n/2;
	}
	printf("%llu",y);
}
