#include<stdio.h>
#include<math.h>
#include<string.h>

#define size_t 1000000
#define size_p 1000
#define xx 1000003

int length(char[], int,int,int);

void main(){
	char t[size_t];
	int i;		
	int n,m,k,temp,q,l=2;
	scanf("%s",t);	//main string
	scanf("%d",&k); //k times
	
	for(i=0;t[i] != '\0';i++)	n = i;

	++n;
	l=n-k;
	int r = n-k;
	int mid;
	while(l > 0){
		//mid = l +(r-l)/2;
		q = length(t,n,l,k);
		if(q == 1)	--l;
		else		break;
		
	}
//	q = length(t,n,l,k);
	printf("\n%d",l);
}

int length(char t[],int n,int l,int k)
{
	int hash[xx];
	memset(hash,0,sizeof(hash));	
	int y = t[0] - '0';
	int pow,i;
	pow = 2;
	for(i=1; i < l ;i++){
		int temp = t[i] - '0';
		y = ((2*y) + temp ) % xx;
		pow = pow*2;
	}
	++hash[y];
	for(i=l;i<n;i++){
		y = ((2*y + (t[i] - '0')) - pow*(t[i-l] - '0')) % xx;
		++hash[y];	
	}
	for(i=0;i<xx;i++){
		if(hash[i] >= k){
			return 1;
		}
	}
	return -1;
}
