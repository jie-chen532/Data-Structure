#define _CRT_SECURE_NO_WARNINGS 1



#include<stdio.h>
#include<stdlib.h>
#include"queue.h"


void queueInit(queue* q)
{
	if (q == NULL)
		return;
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
}

QNode* createQNode(QDataType val)
{
	struct QNode* node = (struct QNode*)malloc(sizeof(struct QNode));
	node->data = val;
	node->next = NULL;
	return node;
}


//尾插
void queuePush(queue* q, QDataType val)
{
	if (q == NULL)
		return;
	struct QNode* node = createQNode(val);
	//第一个节点
	if (q->head == NULL)
	{
		q->head = node;
		q->tail = node;
	}
	else
	{
		q->tail->next = node;
		q->tail = node;
	}
	++q->size;
}


//出队
void queuePop(queue* q)
{
	if (q == NULL || q->head == NULL)
		return;
	struct QNode* next = q->head->next;
	free(q->head);

	if (next == NULL)
		q->tail = NULL;
	q->head = next;
	--q->size;
}


//获取队头元素
QDataType queueFront(queue* q)
{
	return q->head->data;
}


//获取队尾元素
QDataType queueBack(queue* q)
{
	return q->tail->data;
}


//队列判空
int queueEmpty(queue* q)
{
	return q->head == NULL;
}


//队列元素个数
int queueSize(queue* q)
{
	if (q == NULL)
		return 0;
	return q->size;
}

//队列销毁
void queueDestory(queue* q)
{
	if (q == NULL || q->head == NULL)
		return;
	struct QNode* node = q->head;
	while (node != NULL)
	{
		struct QNode* next = node->next;
		free(node);
		node = next;
	}
	q->head = NULL;
	q->tail = NULL;
}
