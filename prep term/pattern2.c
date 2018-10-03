#include<stdio.h>
#include<math.h>
#include<string.h>
#define size_t 1000000
#define xx 1000003


int length(char p[],int n,int l,int k){
	int hash[xx];
//	memset(hash,0,sizeof(hash));
	int pow = 1;
	int i,temp;
	int x = p[0] - '0';
	
	for(i=1;i<l;i++){
		temp = p[i] - '0';
		x = ((2*x) + temp) % xx;
		pow = pow*2;
	}	
	++hash[x];

	for(i=l;i<n;i++){
		x = (2*x + (p[i] - '0') - pow*(p[i-l] - '0')) % xx;
		++hash[x];

	}
	for(i=0;i<10;i++){
		/*if(hash[i] >= k){
			printf("\n hash: %d Length: %d",hash[i],l);
			return l;
		}*/
		printf("\n i = %d,hash[i] =  %d",i,hash[i]);
	}
	return -1;
}
void main(){
	
	char t[size_t];
	int i,k,l,n,q;
	scanf("%s",t);	//main string
	scanf("%d",&k);

	for(i=0;t[i] != '\0';i++){
		n = i;
	}
	++n;
	q = length(t,n,1,k);
	printf("\n%d",q);
	/*l = 1;
	for(l=n;l > 0;){
		if(length(t,n,l,k) == -1){
			//printf("\nAns : %d",l);
			break;
		}
		else{
			--l;
		}
	}
	printf("%d",l);*/
	
}
