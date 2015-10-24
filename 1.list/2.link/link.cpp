#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

Status CreatLinkL1(LinkList &L, int n, ElemType *E){
	int i;
	LinkList p;
	L = (LinkList) malloc(sizeof(LNode));
	if(!L) return ERROR;
	L->next = NULL;
	for(i = n - 1; i>=0; --i){
		if(!(p = (LinkList) malloc(sizeof(LNode))))
			return ERROR;
		p->data = E[i];
		p->next = L->next;//----
		L->next = p;//----
	}
	return OK;
}

Status CreatLinkL2(LinkList &L, int n, ElemType *E){
	int i;
	LinkList p, r;
	L = (LinkList) malloc(sizeof(LNode));
	if(!L) return ERROR;
	r = L;
	for(i = 0; i < n; i++){
		if(!(p=(LinkList)malloc(sizeof(LNode))))
			return ERROR;
		p->data = E[i];
		r->next = p;//----
		r = p;//----
	}
	r->next = NULL;
	return OK;
}

Status InsertLinkL(LinkList &L, int i, ElemType e){
	LinkList s, p = L;
	int k = 0;
	while(p->next!= NULL && k<i-1){
		p = p->next;
		++k;
	}
	if(!p->next || k>i-1) return ERROR;
	if(!(s = (LinkList) malloc(sizeof(LNode))))
		return OVERFLOW;
	s->data = e;
	s->next = p->next;//---- 
	p->next = s;//----
	return OK;
}

Status Del_LinkL1(LinkList L, int i, ElemType &e){
	int k = 0;
	LinkList q, p = L;
	while(p->next != NULL && k < i-1){
		p = p->next; ++k;
	}
	if(!p->next || k > i-1) return ERROR;
	q = p->next;
	p->next = p->next->next;//----
	e = q->data;
	free(q);
	return OK;
}

Status Del_LinkL2(LinkList L, ElemType e){
	LinkList p, q;
	p = L;
	q = L->next;
	while(q->next != NULL && q->data != e){//----
		p = q;
		q = q->next;
	}
	if(q == NULL)
		return OK;
	p->next = q->next;
	free(q);
	return OK;
}

Status Del_LinkL3(LinkList &L, ElemType e){
	LinkList p, q;
	int tag = FALSE;
	p = L;
	q = L->next;
	while(q != NULL){
		if(q->data == e){
			p->next = p->next->next;
			free(q);
			tag = TRUE;
		}else{
			p = q;
		}
		q = p->next;
	}
	return tag;
}

void PrintLinkL(LinkList L){
	LinkList p = L->next;
	while(p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void FreeLinkL(LinkList &L){
	LinkList p, q;
	p = L;
	while( p!= NULL){
		q = p;//----
		p = p->next;
		free(q);
	}
	L = NULL;
}


