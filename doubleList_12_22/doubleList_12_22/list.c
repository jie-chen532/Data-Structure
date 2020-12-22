#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//˫���ͷѭ������

typedef int LDataType;

//˫����
typedef struct ListNode
{
	LDataType val;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

typedef struct List
{
	struct ListNode* head;
}List;

//��ʼ������
void initList(List* lst)
{
	//����ͷ���
	lst->head = (struct ListNode*)malloc(sizeof(struct ListNode));
	//����ѭ���ṹ
	lst->head->next = lst->head;
	lst->head->prev = lst->head;
}

//�������
struct ListNode* createNode(LDataType val)
{
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newNode->val = val;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

//β��
void listPushBack(List* lst,LDataType val)
{
	if (lst == NULL)
		return;
	struct ListNode* cur = lst->head->prev;
	struct ListNode* newNode = createNode(val);

	cur->next = newNode;
	newNode->prev = cur;
	newNode->next = lst->head;
	lst->head->prev = newNode;
}

//βɾ
void listPopBack(List* lst)
{
	if (lst == NULL || lst->head == lst->head->prev)
		return;
	struct ListNode* tail = lst->head->prev;

	lst->head->prev = tail->prev;
	tail->prev->next = lst->head;
	free(tail);
}

//ͷ��
void listPushFront(List* lst, LDataType val)
{
	struct ListNode* next = lst->head->next;
	struct ListNode* newNode = createNode(val);

	lst->head->next = newNode;
	newNode->prev = lst->head;
	newNode->next = next;
	next->prev = newNode;
}


//ͷɾ
void listPopFront(List* lst)
{
	if (lst == NULL || lst->head->prev == lst->head)
		return;
	struct ListNode* next = lst->head->next;
	struct ListNode* nextnext = next->next;

	free(next);
	lst->head->next = nextnext;
	nextnext->prev = lst->head;

}


//��������֮ǰ����
void listInsert(ListNode* node, LDataType val)
{
	struct ListNode* newNode = createNode(val);
	struct ListNode* prev = node->prev;

	prev->next = newNode;
	newNode->prev = prev;
	newNode->next = node;
	node->prev = newNode;
}

//ɾ��ĳһ���
void listErase(ListNode* node)
{
	struct ListNode* next = node->next;
	struct ListNode* prev = node->prev;

	free(node);
	prev->next = next;
	next->prev = prev;
}

//����
struct ListNode* listFind(List* lst, LDataType val)
{
	struct ListNode* cur = lst->head->next;
	while (cur != lst->head)
	{
		if (cur->val == val)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//��ӡ
void listPrint(List* lst)
{
	struct ListNode* cur = lst->head->next;
	while (cur != lst->head)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

//����
void listDestory(List* lst)
{
	struct ListNode* cur = lst->head->next;
	while (cur != lst->head)
	{
		struct ListNode* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	free(lst->head);
	lst->head = NULL;
}


void test()
{
	struct List lst;
	initList(&lst);
	
	//β��
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPushBack(&lst, 5);
	listPushBack(&lst, 6);
	listPushBack(&lst, 7);//1 2 3 4 5 6 7
	//βɾ
	listPopBack(&lst);
	listPopBack(&lst);
	listPopBack(&lst);
	listPopBack(&lst);//1 2 3
	//ͷ��
	listPushFront(&lst, 5);
	listPushFront(&lst, 6);
	listPushFront(&lst, 7);//7 6 5 1 2 3
	//ͷɾ
	listPopFront(&lst);
	listPopFront(&lst);//5 1 2 3
	//��������ǰ����
	struct ListNode* tmp = listFind(&lst, 2);
	listInsert(tmp, 4);
	listInsert(tmp, 6);//5 1 4 6 2 3
	//ɾ��������
	tmp = listFind(&lst, 2);
	listErase(tmp);//5 1 4 6 3

	listDestory(&lst);
	listPrint(&lst);
}

int main()
{
	test();
	return 0;
}