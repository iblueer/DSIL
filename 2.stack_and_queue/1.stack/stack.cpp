#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char SelemType;
typedef struct{
	SelemType *base;
	SelemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S){
	S.base = (SelemType *) malloc(STACK_INIT_SIZE*sizeof(SelemType));
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Push(SqStack &S, SelemType e){
	if(S.top-S.base >= S.stacksize){
		S.base = (SelemType *)realloc(S.base, (S.stacksize+STACKINCREMENT)*sizeof(SelemType));
		if(!S.base) exit(OVERFLOW);
		S.top = S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*(S.top++) = e;
	return OK;
}

Status Pop(SqStack &S, SelemType &e){
	if(S.top == S.base) return ERROR;
	e = *(--S.top);
	return OK;
}

Status StackEmpty(SqStack S){
	if(S.top == S.base)
		return TRUE;
	else
		return FALSE;
}


