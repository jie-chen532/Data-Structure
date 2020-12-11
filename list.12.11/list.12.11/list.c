#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

//��ʼ������
void initList(list* lst)
{
	if (lst == NULL)
		return;
	lst->head = NULL;
}

//����һ�����
listNode* createListNode(LDataType val)
{
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}

//β��
void listPushBack(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	if (lst->head == NULL)
	{
		//������һ�����
		lst->head = createListNode(val);
	}
	else
	{
		//�ȱ����ҵ����һ�����
		listNode* tail = lst->head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = createListNode(val);
	}
}


//βɾ
void listPopBack(list* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct listNode* pre = NULL;
	struct listNode* tail = lst->head;
	while (tail->next != NULL)
	{
		pre = tail;
		tail = tail->next;
	}
	free(tail);
	if (pre == NULL)
	{
		//ֻ��һ�����
		lst->head = NULL;
	}
	else
	{
		pre->next = NULL;
	}
}


//ͷ��
void listPushFront(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	struct listNode* newNode = createListNode(val);
	newNode->next = lst->head;
	lst->head = newNode;
}


//ͷɾ
void listPopFront(list* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct listNode* tail = lst->head->next;
	free(lst->head);
	lst->head = tail;
}


//������λ�ú����
void listInsertAfter(listNode* node, LDataType val)
{
	if (node == NULL)
		return;
	struct listNode* newNode = createListNode(val);
	newNode->next = node->next;
	node->next = newNode;
}


//������λ�ú�ɾ��
void listEraseAfter(listNode* node)
{
	if (node == NULL || node->next == NULL)
		return;
	struct listNode* tail = node->next->next;
	free(node->next);
	node->next = tail;
}


//�ҵ�ĳֵ��λ��
struct listNode* listFind(list* lst, LDataType val)
{
	if (lst == NULL || lst->head == NULL)
		return NULL;
	struct listNode* tail = lst->head;
	while (tail != NULL)
	{
		if (tail->data == val)
			return tail;
		tail = tail->next;
	}
	return NULL;
}


//����
void listDestory(list* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct listNode* tail = lst->head;
	while (tail != NULL)
	{
		struct listNode* cur = tail->next;
		free(tail);
		tail = cur;
	}
	lst->head = NULL;
}

//��ӡ
void listPrint(list* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct listNode* tail = lst->head;
	while (tail != NULL)
	{
		printf("%d ", tail->data);
		tail = tail->next;
	}
}


void test()
{
	list lst;
	initList(&lst);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPushBack(&lst, 5);
	listPushBack(&lst, 6);
	listPopBack(&lst);
	listPopBack(&lst);
	listPopBack(&lst);
	listPushFront(&lst, 4);
	listPushFront(&lst, 5);
	listPushFront(&lst, 6);
	listPushFront(&lst, 7);
	listPopFront(&lst);
	listPopFront(&lst);
	listPopFront(&lst);
	listNode* findNode = listFind(&lst, 4);
	listInsertAfter(findNode, 5);
	listNode* findNode2 = listFind(&lst, 1);
	listEraseAfter(findNode2);

	listDestory(&lst);
	listPrint(&lst);
}


int main()
{
	test();
	return 0;
}