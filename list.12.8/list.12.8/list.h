#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef int LDataType;

//定义结点
typedef struct ListNode
{
	LDataType data;
	struct ListNode* next;
}ListNode;

//定义链表
typedef struct list
{
	//保存第一个结点的地址
	ListNode* head;
}list;

//初始化链表
void InitList(list* lst);

//创建结点
ListNode* CreateLinkNode(LDataType val);

//尾插
void listPushBack(list* lst, LDataType val);

//尾删
void listPopBack(list* lst);

//头插
void listPushFront(list* lst, LDataType val);


//头删
void listPopFront(list* lst);


//任意位置后插入
void listInsertAfter(ListNode* node, LDataType val);


//任意位置后删除
void listEraseAfter(ListNode* node);


//链表销毁
void listDestory(list* lst);


//打印链表
void listPrint(list* lst);