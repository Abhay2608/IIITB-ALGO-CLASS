#include<stdio.h>
#include<math.h>

#define size_t 1000000
#define size_p 1000
#define xx 1000003

void main(){
	char t[size_t];
	char p[size_p];
	int i;
		
	scanf("%s",t);	//main string
	scanf("%s",p);	//pattern
	int n=0,m=0,k;
	int x = p[0] - '0';
	int pow = 1;	
	for(i=1;p[i] != '\0';i++){
		int temp = p[i] - '0';
		x = ((2*x) + temp) % xx;
		++m;
		pow = pow*2;
	}

	for(i=0;t[i] != '\0';i++)	++n;

	
	int y = t[0] - '0';
	for(i=1;i<m;i++){
		int temp = t[i] - '0';
		y = ((2*y) + temp) % xx;
	}
	
	int flag = 0;
	int index = 0;
	for(i=m;i<n;i++){
		if(x == y){
			flag = 1;
			index = i-m;
			break;
		}
		else{
			y = (2*y + (t[i] - '0') - pow*(t[i-m] - '0')) % xx; 
		}
	}
	if(flag == 1){
		printf("Pattern Found :%d\n",index);
	}
	else{
		printf("Pattern Not Found \n");
	}
}
