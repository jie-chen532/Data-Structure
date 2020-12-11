#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

//初始化链表
void initList(list* lst)
{
	if (lst == NULL)
		return;
	lst->head = NULL;
}

//创建一个结点
listNode* createListNode(LDataType val)
{
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}

//尾插
void listPushBack(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	if (lst->head == NULL)
	{
		//创建第一个结点
		lst->head = createListNode(val);
	}
	else
	{
		//先遍历找到最后一个结点
		listNode* tail = lst->head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = createListNode(val);
	}
}


//尾删
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
		//只有一个结点
		lst->head = NULL;
	}
	else
	{
		pre->next = NULL;
	}
}


//头插
void listPushFront(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	struct listNode* newNode = createListNode(val);
	newNode->next = lst->head;
	lst->head = newNode;
}


//头删
void listPopFront(list* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct listNode* tail = lst->head->next;
	free(lst->head);
	lst->head = tail;
}


//在任意位置后插入
void listInsertAfter(listNode* node, LDataType val)
{
	if (node == NULL)
		return;
	struct listNode* newNode = createListNode(val);
	newNode->next = node->next;
	node->next = newNode;
}


//在任意位置后删除
void listEraseAfter(listNode* node)
{
	if (node == NULL || node->next == NULL)
		return;
	struct listNode* tail = node->next->next;
	free(node->next);
	node->next = tail;
}


//找到某值的位置
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


//销毁
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

//打印
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