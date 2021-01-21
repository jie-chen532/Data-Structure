#define _CRT_SECURE_NO_WARNINGS 1



#include<stdio.h>
#include<stdlib.h>

typedef int QDataType;
//队列 带有尾指针的单链表
typedef struct QNode
{
	QDataType data;
	struct QNode* next;
}QNode;


typedef struct queue
{
	struct QNode* head;
	struct QNode* tail;
	int size;
}queue;


void queueInit(queue* q);

QNode* createQNode(QDataType val);


//尾插
void queuePush(queue* q, QDataType val);


//出队
void queuePop(queue* q);


//获取队头元素
QDataType queueFront(queue* q);


//获取队尾元素
QDataType queueBack(queue* q);


//队列判空
int queueEmpty(queue* q);


//队列元素个数
int queueSize(queue* q);

//队列销毁
void queueDestory(queue* q);
