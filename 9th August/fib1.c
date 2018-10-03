#include<stdio.h>
#include<stdlib.h>


//this is a simple recursion technique which takes O(2^n/2) time complexity and O(n) space complexity. Worst algo for fibonacci max n =36
int fib_recursion(int n){
	if(n == 0)	return 0;
	if(n == 1) 	return 1;
	else	return fib_recursion(n-1) + fib_recursion(n-2);

}



//this is a dynamic programming technique which takes O(n) time and space complexity. max n = 10^6
unsigned long long int fib_dp(int n){
	unsigned long long int *a = (unsigned long long int *)malloc((n+1) * sizeof(unsigned long long int));
	unsigned long long int i;
	a[0] = 0;
	a[1] = 1;
	for(i = 2;i<=n;i++){
		a[i] = a[i-1] + a[i-2];
		printf("%llu\n",a[i]);
	}
	return a[n];
}
int main(){
	int n;
	scanf("%d",&n);
	//printf("%d",fib_recursion(n));
	printf("%llu",fib_dp(n));
}
