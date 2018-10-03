#include<stdio.h>
#include<stdlib.h>
#define m 1000003



struct node{
	int data;
	struct node *next;
};

struct node *hash[m];

void search();
void add();
void delete();
void searchInList(struct node **,int n);
void addInList(struct node**,int n);
void deleteInList(struct node**,int n);

int main(){
//	struct node *hash[m];
	int choice;
	int flag = 0;
	int data;
	while(1){
		if(flag == 1)
			break;
		printf("\n 1.Search");
		printf("\n 2.Add");
		printf("\n 3.delete");

	scanf("%d",&choice);

	switch(choice){
	case 1: search();
	case 2: add();
	case 3: delete();
	default: flag = 1;
	}
}


return 0;
}

void search(){
	struct node *head;
	int d;
	scanf("%d",&d);
	head = hash[d % m];
	int y = searchInList(&head,d % m);

return;
}

void add(){
	struct node *head;
	int d;
	scanf("%d",&d);
	head = hash[d % m];
	addInList(&head,d % m);
return;
}

void delete(){
	struct node *head;
	int d;
	scanf("%d",&d);
	head = hash[d % m];
	deleteInList(&head,d % m);
return;
}

int  searchInList(struct node *head,int x){
	struct node *temp = head;
	if(head == NULL){
		printf("\n%d not present",x);
		return 0;
	}
	else{
		while(head != NULL){
			if(temp->data == x){
				printf("\n%d present",x);
				return 1;
			}
		temp = temp->next;
		}
	printf("\n%d not present",x);
	return 0;
	}
	
}

void addInList(struct node **head,int x){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = *head;
	*head = temp;
}

void deleteInList(struct node *head,int x){
	int y = searchInList(&head,x);
	if(y == 1){
		struct node *temp = head;
		if(temp->data == x){
			*head = temp->next;
			printf("\n%d deleted",x);
			return;
		}
		else{	
			struct node *prev = head;
			temp = temp->next;
			while(temp != NULL){
				if(temp->data == x){
					prev->next = temp->next;
					printf("\n %d deleted",x);
					return;
				}
			prev = prev->next;
			temp = temp->next;
			}
		
		}
	return;
	}
	else{
		printf("\n%d not deleted",x);
		return;
	}
return;
}

