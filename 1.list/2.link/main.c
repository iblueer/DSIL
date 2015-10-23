#include <stdio.h>
#include <stdlib.h>

//定义一些常见的常量
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//定义函数返回的状态类型为int
typedef int status;

//设置线性表的数据类型
typedef int elem_type;

//定义链表中的节点
typedef struct link_node{
	elem_type data;
	struct link_node *next;
} link_node;

//初始化链表
status init_link(link_node ** link_point){
	//link_point为指向链表头节点的指针的地址
	*link_point = NULL;//初始初始后链表指针指向空
	return OK;
}

//返回链表的长度
int link_length(link_node ** link_point){
	if(*link_point == NULL) return 0;
	int result = 1;
	link_node *p = *link_point;
	while(p->next != NULL){
		p = p->next;
		result++;
	}
	return result;
}

//在link_point指向的链表的第n个位置插入val， 
status link_insert(link_node ** link_point, int n, elem_type val){
	//n为要插入的位置（从1开始计数）；val为要插入的值
	if(n < 1 || n > link_length(link_point) + 1) return ERROR; //判断位置是否越界
	if(n == 1){//当n为1时的操作有点不同，所以单独写出来
		link_node * p = (link_node *)malloc(sizeof(link_node));
		p->data = val;
		p->next = *link_point;
		*link_point = p;
		return OK;
	}
	link_node * p = *link_point;
	for(int i = 1; i < n - 1; i++) p = p->next;
	link_node * q = (link_node *)malloc(sizeof(link_node));
	q->data = val;
	q->next = p->next;
	p->next = q;
	return OK; 
}

//修改link_point所指向的链表中第n个位置的值
status link_set(link_node ** link_point, int n, elem_type val){
	if(n < 1 || n > link_length(link_point)) return ERROR;
	link_node * p = *link_point;
	for(int i = 1; i < n; i++) p = p->next;
	p->data = val;
	return OK;
}

//获取链表中第n个位置的值，并保存到result中
status link_get(link_node ** link_point, int n, elem_type * result){
	//result为用于保存获取结果的指针或地址
	if(n < 1 || n > link_length(link_point)) return ERROR;
	link_node * p = *link_point;
	for(int i = 1; i < n; i++) p = p->next;
	*result = p->data;
	return OK; 
}

//删除链表中位于第n个位置的元素
status link_delete(link_node ** link_point, int n){
	if(n < 1 || n > link_length(link_point)) return ERROR;
	if(n == 1){
		link_node *q = *link_point;
		*link_point = (*link_point)->next;
		free(q);
		return OK;
	}
	link_node *p = *link_point;
	for(int i = 1; i < n - 1; i++) p = p->next;
	link_node *q = p->next;
	p->next = p->next->next;
	free(q);
	return OK;
}

int main(){
	link_node *link;
	init_link(&link);
	for(int i = 1; i < 11; i++){
		link_insert(&link, i, i);
	}
	link_set(&link, 1, 10);
	link_delete(&link, 2);
	int n = 0;
	for(int i = 1; i <= link_length(&link); i++){
		link_get(&link, i, &n);
		printf("%d ", n);
	}
	
	return 0;
}