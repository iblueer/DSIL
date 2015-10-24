#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define MAXSIZE 6
#define INCREMENT 10

typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType *elem;
	int length;
	int listsize;
} SqList;

Status InitList(SqList &L){
	L.elem = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
	if( !L.elem ) exit(OVERFLOW); //
	L.length  = 0;
	L.listsize = MAXSIZE; //  
	return OK;
}

Status InsertList(SqList &L, int i, ElemType e){
	if( i < 1 || i > L.length + 1) return ERROR;//
	ElemType *p;
	int j;
	if( L.length >= L.listsize ){//
		p = (ElemType *)realloc(L.elem, (L.listsize + INCREMENT)*sizeof(ElemType));
		if(!p) exit(OVERFLOW);
		L.elem = p;
		L.listsize += INCREMENT;
	}
	for(j = L.length - 1; j >= i-1; --j) L.elem[j + 1] = L.elem[j];
	L.elem[i-1] = e;//
	L.length++;
	return OK;
}

void PrintList(SqList L){
	int i;
	for(i = 0; i < L.length ; i++)//
		printf("%d ", L.elem[i]);
	printf("\n");
}

int SearchList(SqList L, ElemType e){
	int i;
	for(i = 0; i < L.length; i++)
		if( L.elem[i] == e ) return i;
	return -1;
}

int Del_List1(SqList &L, ElemType e){
	int i, j;
	for(i = 0; i < L.length; i++)
		if(L.elem[i] == e)
			break;
	if(i < L.length){
		for( j = i; j < L.length - 1; j++)
			L.elem[j] = L.elem[j + 1];
		L.length--;
		return i;
	}
	return -1;
}

Status Del_List2(SqList &L, int i, ElemType &e){
	if( i < 1 || i > L.length ) return ERROR;
	int j;
	e = L.elem[i-1];
	for(j = i; j < L.length; j++)
		L.elem[j - 1] = L.elem[j];
	--L.length;
	return OK;
}

