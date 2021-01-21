#define _CRT_SECURE_NO_WARNINGS 1



#include<stdio.h>
#include<stdlib.h>

typedef int QDataType;
//���� ����βָ��ĵ�����
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


//β��
void queuePush(queue* q, QDataType val);


//����
void queuePop(queue* q);


//��ȡ��ͷԪ��
QDataType queueFront(queue* q);


//��ȡ��βԪ��
QDataType queueBack(queue* q);


//�����п�
int queueEmpty(queue* q);


//����Ԫ�ظ���
int queueSize(queue* q);

//��������
void queueDestory(queue* q);
