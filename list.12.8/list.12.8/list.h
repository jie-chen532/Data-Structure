#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef int LDataType;

//������
typedef struct ListNode
{
	LDataType data;
	struct ListNode* next;
}ListNode;

//��������
typedef struct list
{
	//�����һ�����ĵ�ַ
	ListNode* head;
}list;

//��ʼ������
void InitList(list* lst);

//�������
ListNode* CreateLinkNode(LDataType val);

//β��
void listPushBack(list* lst, LDataType val);

//βɾ
void listPopBack(list* lst);

//ͷ��
void listPushFront(list* lst, LDataType val);


//ͷɾ
void listPopFront(list* lst);


//����λ�ú����
void listInsertAfter(ListNode* node, LDataType val);


//����λ�ú�ɾ��
void listEraseAfter(ListNode* node);


//��������
void listDestory(list* lst);


//��ӡ����
void listPrint(list* lst);