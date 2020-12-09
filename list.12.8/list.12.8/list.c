#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

//初始化链表
void InitList(list* lst)
{
	if (lst == NULL)
		return;
	lst->head = NULL;
}

//创建结点
ListNode* CreateLinkNode(LDataType val)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}

//尾插：o(n)
void listPushBack(list* lst, LDataType val)
{
	if (lst == NULL)
		return;
	if (lst->head == NULL)
	{
		//创建第一个结点
		lst->head = CreateLinkNode(val);
	}
	else
	{
		//先找到最后一个结点
		ListNode* tail = lst->head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = CreateLinkNode(val);
	}
}


//尾删:o(n)
void listPopBack(list* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct ListNode* pre = NULL;
	struct ListNode* tail = lst->head;
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
    struct ListNode* tail = CreateLinkNode(val);
	tail->next = lst->head;
	lst->head = tail;
}

//头删
void listPopFront(list* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct ListNode* tail = lst->head->next;
	free(lst->head);
	lst->head = tail;
}



//任意位置后插入
void listInsertAfter(ListNode* node, LDataType val)
{
	if (node == NULL)
		return; 
	struct ListNode* newNode = CreateLinkNode(val);
	newNode->next = node->next;
	node->next = newNode;
}


//任意位置后删除
void listEraseAfter(ListNode* node)
{
	if (node == NULL || node->next == NULL)
		return;
	struct ListNode* tail = node->next->next;
	free(node->next);
	node->next = tail;
}


//找某一个具体值
ListNode* listFind(list* lst, LDataType val)
{
	if (lst == NULL || lst->head == NULL)
		return NULL;
	struct ListNode* tail = lst->head;
	while (tail != NULL)
	{
		if (tail->data == val)
		{
			return tail;
		}
		tail = tail->next;
	}
	return NULL;
}


//链表销毁
void listDestory(list* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct ListNode* tail = lst->head;
	while (tail != NULL)
	{
		ListNode* cur = tail->next;
		free(tail);
		tail = cur;
	}
	lst->head = NULL;
}


//打印链表
void listPrint(list* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct ListNode* tail = lst->head;
	while (tail != NULL)
	{
		printf("%d ", tail->data);
		tail = tail->next;
	}
}


void test()
{
	list lst;
	InitList(&lst);
	listPushBack(&lst,1);
	listPushBack(&lst,2);
	listPushBack(&lst,3);
	listPushBack(&lst,4);
	listPopBack(&lst);
	listPopBack(&lst);
	listPushFront(&lst, 4); 
	listPushFront(&lst, 5);
	listPushFront(&lst, 6);
	listPushFront(&lst, 7);
	listPopFront(&lst);
	listPopFront(&lst);
	listPopFront(&lst);
	ListNode* cur = listFind(&lst, 1);
	ListNode* cur1 = listFind(&lst, 4);
	listInsertAfter(cur, 8);
	listEraseAfter(cur1);

	listDestory(&lst);
	listPrint(&lst);
}


int main()
{
	test();
	return 0;
}