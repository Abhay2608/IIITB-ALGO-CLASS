#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack{
	unsigned capacity;
	int top;
	int *array;
};

struct Stack* createStack(unsigned c){
	struct Stack* st = (struct Stack*)malloc(sizeof(struct Stack));
	st->capacity = c;
	st->top = -1;
	st->array = (int *)malloc(c * sizeof(int));
	return st;
}

int isFull(struct Stack* st){
	return st->top == (st->capacity - 1);
}

int isEmpty(struct Stack* st){
	return st->top == -1;
}

void push(struct Stack *st,int item){
	if(isFull(st))
		return;
	else
		st->array[++st->top] = item;
	return;
}

int pop(struct Stack *st){
	if(isEmpty(st))
		return INT_MIN;
	else	
		return st->array[st->top--];
}

int peek(struct Stack *st){
	return st->array[st->top];
}

int main(){
	struct Stack* st = createStack(5);
	push(st,10);
	push(st,20);
	printf("%d",peek(st));
return 0;
}
