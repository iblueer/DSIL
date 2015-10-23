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

//定义线性表初始化时的大小和分配增量
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

//设置线性表的数据类型
typedef int elem_type;

//定义线性表类型
typedef struct{
	elem_type *elem;
	int length;
	int list_size;
} list;

//初始化线性表的函数
status init_list(list *list_point){
	//list_point为指向线性表的指针或线性表的地址
	list_point->elem = (elem_type *)malloc(LIST_INIT_SIZE * sizeof(elem_type));//给线性表分配储存空间
	if(!list_point->elem) return OVERFLOW;//如果空间分配失败，则返回ERROR
	list_point->length = 0;//新的线性表没有内容，所以长度为0
	list_point->list_size = LIST_INIT_SIZE;//线性表的大小等于默认的大小
	return OK;
}

//向线性表里插入数据，插入位置之后的元素均向后移动一位
status list_insert(list *list_point, int n, elem_type val){
	//n为插入位置（从1开始计数）；val为要插入的内容
	if(n < 1 || n > list_point->length + 1) return ERROR; //判断位置是否正确
	if(list_point->length >= list_point->list_size){  //如果线性表已满，则需重新分配空间
		elem_type * elem = (elem_type *)realloc(list_point->elem, (list_point->list_size + LISTINCREMENT) * sizeof(elem_type));//重新分配储存空间
		if(!elem) return ERROR;//如果分配失败，则返回ERROR
		list_point->elem = elem;//将线性表指向新的空间
		list_point->list_size += LISTINCREMENT;//增大线性表的大小
	}
	for(int i = list_point->length; i >= n; i--) //从要插入数据的位置开始，把后面每一个元素都向后移动一位
		*(list_point->elem + i) = *(list_point->elem + i - 1);
	*(list_point->elem + n - 1) = val;//插入元素
	list_point->length++;  //插入数据后线性表的长度+1
	return OK;
}

//修改线性表中某个元素的操作
status list_set(list *list_point, int n, elem_type val){
	if(n < 1 || n > list_point->length) return ERROR;
	*(list_point->elem + n - 1) = val;
	return OK;
}

//获取线性表某个位置的内容，并保存到一个变量中
status list_get(list *list_point, int n, elem_type * result){
	//result为存放元素内容的指针或地址
	if(n < 1 || n > list_point->length) return ERROR;
	*result = *(list_point->elem + n - 1);
	return OK;
}


//删除线性表某个位置的元素，之后所有元素向前移动一位
status list_delete(list * list_point, int n){
	if(n < 1 || n > list_point->length) return ERROR;
	for(int i = n; i < list_point->length; i++){
		*(list_point->elem + n - 1) = *(list_point->elem + n);	
	}
	list_point->length--;//删除成功，线性表长度-1
	return OK;
}


int main(){
	list my_list;//定义一个名为my_list的线性表
	init_list(&my_list);//初始化线性表
	for(int i = 0; i < 100; i++){//向线性表里插入0 - 99
		list_insert(&my_list, i + 1, i);
	}
	list_insert(&my_list, 2, 2);//在my_list的第二个位置插入2
	list_delete(&my_list, 4);//删除my_list中的第四个元素
	list_set(&my_list, 5, 10);//修改my_list中的第五个元素为10
	for(int i = 0; i < my_list.length; i++){//显示my_lsit中的所有元素
		printf("%d ", my_list.elem[i]);
	}
	elem_type n;
	list_get(&my_list, 5, &n);//获取my_list中的第五个元素，并保存到变量n中
	printf("\n%d\n", n);//输出n的值
	
	
	return 0;
}