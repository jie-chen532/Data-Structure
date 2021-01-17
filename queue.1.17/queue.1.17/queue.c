#define _CRT_SECURE_NO_WARNINGS 1


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


//β��
void queuePush(queue* q, QDataType val)
{
	if (q == NULL)
		return;
	struct QNode* node = createQNode(val);
	//��һ���ڵ�
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


//����
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


//��ȡ��ͷԪ��
QDataType queueFront(queue* q)
{
	return q->head->data;
}


//��ȡ��βԪ��
QDataType queueBack(queue* q)
{
	return q->tail->data;
}


//�����п�
int queueEmpty(queue* q)
{
	return q->head == NULL;
}


//����Ԫ�ظ���
int queueSize(queue* q)
{
	if (q == NULL)
		return 0;
	return q->size;
}

//��������
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


void test()
{
	struct queue q;
	queueInit(&q);
	queuePush(&q, 1);
	queuePush(&q, 2);
	queuePush(&q, 5);
	queuePush(&q, 12);
	queuePush(&q, 7);
	queuePush(&q, 6);
	queuePop(&q);
	queuePop(&q);
	queuePop(&q);
	printf("��ͷԪ��:%d\n", queueFront(&q));
	printf("��βԪ��:%d\n", queueBack(&q));
	printf("����Ԫ�ظ���:%d\n", queueSize(&q));
	queueDestory(&q);
	while (!queueEmpty(&q))
	{
		printf("%d ", queueFront(&q));
		queuePop(&q);
	}
	printf("\n");
}

int main()
{
	test();
	return 0;
}