#include<stdio.h>
#include<math.h>

#define size_t 25
#define size_p 3

void main(){
	char t[size_t];
	char p[size_p];
	int i;
		
	scanf("%s",t);	//main string
	scanf("%s",p);	//pattern

	int x = p[0] - '0';
	for(i=1;i<size_p;i++){
		int temp = p[i] - '0';
		x = (2*x) + temp;
	}

	
	int y = t[0] - '0';
	for(i=1;i<size_p;i++){
		int temp = t[i] - '0';
		y = (2*y) + temp;
	}
	
	int flag = 0;
	int index = 0;
	for(i=size_p; t[i] != '\0';i++){
		if(x == y){
			flag = 1;
			index = i-size_p;
			break;
		}
		else{
			y = 2*y + (t[i] - '0') - (int)pow(2,size_p)*(t[i-size_p] - '0'); 
		}
	}
	if(flag == 1){
		printf("Pattern Found :%d\n",index+1);
	}
	else{
		printf("Pattern Not Found \n");
	}
}
