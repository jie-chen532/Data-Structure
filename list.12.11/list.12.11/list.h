#include<stdio.h>
#include<stdlib.h>

typedef int LDataType;

//������
typedef struct listNode
{
	LDataType data;
	struct listNode* next;
}listNode;

//��������
typedef struct list
{
	listNode* head;
}list;


//��ʼ������
void initList(list* lst);


//����һ�����
listNode* createListNode(LDataType val);


//β��
void listPushBack(list* lst, LDataType val);


//βɾ
void listPopBack(list* lst);


//ͷ��
void listPushFront(list* lst, LDataType val);


//ͷɾ
void listPopFront(list* lst);


//������λ�ú����
void listInsertAfter(listNode* node, LDataType val);


//������λ�ú�ɾ��
void listEraseAfter(listNode* node);


//�ҵ�ĳֵ��λ��
listNode* listFind(list* lst, LDataType val);


//����
void listDestory(list* lst);


//��ӡ
void listPrint(list* lst);