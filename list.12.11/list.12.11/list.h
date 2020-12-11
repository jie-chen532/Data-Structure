#include<stdio.h>
#include<stdlib.h>

typedef int LDataType;

//定义结点
typedef struct listNode
{
	LDataType data;
	struct listNode* next;
}listNode;

//定义链表
typedef struct list
{
	listNode* head;
}list;


//初始化链表
void initList(list* lst);


//创建一个结点
listNode* createListNode(LDataType val);


//尾插
void listPushBack(list* lst, LDataType val);


//尾删
void listPopBack(list* lst);


//头插
void listPushFront(list* lst, LDataType val);


//头删
void listPopFront(list* lst);


//在任意位置后插入
void listInsertAfter(listNode* node, LDataType val);


//在任意位置后删除
void listEraseAfter(listNode* node);


//找到某值的位置
listNode* listFind(list* lst, LDataType val);


//销毁
void listDestory(list* lst);


//打印
void listPrint(list* lst);