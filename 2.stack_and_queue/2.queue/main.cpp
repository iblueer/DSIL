#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1
#define OVERFLOW -1

typedef int Status;
typedef int ElemType;

typedef struct LinkNode{
	ElemType data;
	LinkNode * next;
} * LinkNodePoint;

typedef struct Queue{
	LinkNodePoint top;
	LinkNodePoint bottom;
	int length;
} * QueuePoint;

Status InitQueue(Queue &queue){
	queue.top = (LinkNodePoint) malloc(sizeof(LinkNode));
	if(!queue.top)
		exit(OVERFLOW);
	queue.bottom = queue.top;
	queue.length = 0;
	return OK;
}

Status EnQueue(Queue &queue, ElemType value){
	LinkNodePoint point = (LinkNodePoint) malloc(sizeof(LinkNode));
	if(!point)
		exit(OVERFLOW);
	queue.bottom->next = point;
	queue.bottom->data = value;
	queue.bottom = point;
	queue.length++;
	return OK;
}

Status DeQueue(Queue &queue, ElemType &value){
	LinkNodePoint point;
	if(queue.length == 0)
		return ERROR;
	value = queue.top->data;
	point = queue.top;
	queue.top = queue.top->next;
	free(point);
	queue.length--;
	return OK;
}

Status PrintQueue(Queue queue){
	ElemType value;
	while(DeQueue(queue,value))
		printf("%d ", value);
	printf("\n");
	return OK;
}

int main(){
	Queue queue;
	ElemType value;
	InitQueue(queue);
	printf("请输入要入队的数据(以0结束): ");
	scanf("%d", &value);
	while(value){
		EnQueue(queue, value);
		scanf("%d", &value);
	}
	printf("出对的次序为: ");
	PrintQueue(queue);
	return 0;
}

	


