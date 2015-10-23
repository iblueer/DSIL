#include <stdio.h>
#include <stdlib.h>


//创建链表节点类型
typedef struct link_node{
	int data;
	struct link_node * next;
} link_node;


//定义删除链表中一个节点的函数
void delete_node(link_node ** node_point){
	link_node * p = *node_point;
	link_node * q;
	if ((*node_point)->next != *node_point){  //该链表中有两个以上的节点时的删除代码
		while (p->next != *node_point) p = p->next;
		p->next = p->next->next;
		q = *node_point;
		free(q);
	}  //该链表中只有一个节点时的删除代码
	else{
		q = *node_point;
		free(q);
		*node_point = NULL;  //当链表中没有节点是，让该节点指向NULL
	}
}


//初始化链表的函数，有两个参数（head_point：指向链表头部的指针，n：人数）
void init_link(link_node ** link_head, int n){
	link_node * end_point;
	*link_head = end_point = (link_node*)malloc(sizeof(link_node));
	end_point->data = 1;
	for (int i = 1; i < n; i++){
		end_point->next = (link_node*)malloc(sizeof(link_node));
		end_point = end_point->next;
		end_point->data = i + 1;
	}
	end_point->next = *link_head;  //让链表的最后一个节点的next指向链表的头节点，从而让链表可以循环
}


//解决约瑟夫问题的函数
void foo(link_node ** link_head, int k, int m){
	link_node * p = *link_head, ** q = link_head;
	link_node * head_point = *link_head;
	for (int i = 1; i < k; i++) head_point = head_point->next;
	while (*link_head){
		for (int i = 1; i < m; i++) p = p->next;
		printf("%d\n", p->data);
		*q = p;
		p = p->next;
		delete_node(q);
	}
}

int main(){
	int n, k, m;//分别定义n(人数)、k(起始位置)、m(间隔数)

	//分别给n、k、m赋值，可用scanf()代替
	n = 41;
	k = 1;
	m = 3;

	link_node * link_head;
	init_link(&link_head, n);
	printf("次序：\n");
	foo(&link_head, k, m);

	return 0;
}
