#include <stdio.h>
#include <stdlib.h>

//定义一些常用常量
#define YES 1
#define OK 1
#define NO 0
#define ERROR 0

//定义栈大小
#define SIZE 20

//定义函数返回状态类型
typedef int status;


char str[SIZE]; //定义一个字符串用于存放栈里的内容

//定义栈类型
typedef struct stack{
	char * base;
	int top;
} stack;

//初始化操作
status init(stack *s){
	s->base = str;
	s->top = 0;
	return OK;
}

//压入操作
status push(stack *s, char v){
	if (s->top > SIZE - 1) return ERROR;//如果栈已满，则不能再压入
	*((s->base) + (s->top)) = v;
	(s->top)++;
	return OK;
}

//弹出操作
status pop(stack *s, char * v){
	if (s->top <= 0) return ERROR;//如果栈是空栈，则不能再弹出
	(s->top)--;
	*v = *(s->base + s->top); 
	*(s->base + s->top) = '\0';
	return OK;
}

//判断栈是否为空
status is_empty(stack *s){
	return s->top == 0 ? YES : NO;
}

//实现括号匹配
status foo(char * v){
	stack s;
	char t;
	init(&s);
	while (*v != '\0'){
		if (*v == '{' || *v == '[' || *v == '(')
			push(&s, *v);
		if (*v == '}'){
			pop(&s, &t);
			if (t != '{')
				return NO;
		}
		if (*v == ']'){
			pop(&s, &t);
			if (t != '[')
				return NO;
		}
		if (*v == ')'){
			pop(&s, &t);
			if (t != '(')
				return NO;
		}
		v++;
	}
	if (!is_empty(&s))
		return NO;
	return YES;
}

int main(){

	if (foo("{[(1+2)*5+2]*[(8+5)*(2+9)]*2}*10")){
		printf("Yes");
	} else {
		printf("No");
	}

	return 0;
}