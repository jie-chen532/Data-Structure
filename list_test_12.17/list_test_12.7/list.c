#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>

//1.
//�ཻ����
//��дһ�������ҵ������������ཻ����ʼ�ڵ㡣


//struct ListNode {
//     int val;
//     struct ListNode *next;
//};
//
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//	if (headA == NULL || headB == NULL)
//		return NULL;
//	int lenA = 0;
//	int lenB = 0;
//	struct ListNode *cur1 = headA;
//	struct ListNode *cur2 = headB;
//	while (cur1 != NULL)
//	{
//		lenA++;
//		cur1 = cur1->next;
//	}
//	while (cur2 != NULL)
//	{
//		lenB++;
//		cur2 = cur2->next;
//	}
//	int gap = abs(lenA - lenB);
//	cur1 = headA;
//	cur2 = headB;
//	if (lenA > lenB)
//	{
//		while (gap--)
//		{
//			cur1 = cur1->next;
//		}
//	}
//	if (lenA < lenB)
//	{
//		while (gap--)
//		{
//			cur2 = cur2->next;
//		}
//	}
//	while (cur1 != NULL && cur2 != NULL)
//	{
//		if (cur1 == cur2)
//		{
//			return cur1;
//		}
//		cur1 = cur1->next;
//		cur2 = cur2->next;
//	}
//	return NULL;
//}


//2.
//��������
//����һ�������ж��������Ƿ��л���


//struct ListNode {
//	int val;
//	struct ListNode *next;
//};
//
//bool hasCycle(struct ListNode *head)
//{
//	if (head == NULL)
//		return false;
//	struct ListNode* fast = head;
//	struct ListNode* slow = head;
//	while (fast != NULL && fast->next != NULL)
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//		if (fast == slow)
//			return true;
//	}
//	return false;
//}


//3.
//��������2
//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��

//struct ListNode {
//     int val;
//     struct ListNode *next;
//};
//
//struct ListNode *detectCycle(struct ListNode *head) {
//	if (head == NULL)
//		return NULL;
//	//���������
//	struct ListNode* fast = head;
//	struct ListNode* slow = head;
//	while (fast != NULL && fast->next != NULL)
//	{
//		fast = fast->next->next;
//		slow = slow->next;
//		if (slow == fast)
//			break;
//	}
//	if (fast == NULL || fast->next == NULL)
//		return NULL;
//	//�ֱ����������ͷ������
//	struct ListNode* cur = head;
//	while (1)
//	{
//		if (cur == slow)
//			return cur;
//		cur = cur->next;
//		slow = slow->next;
//	}
//}


//4.
//���ƴ����ָ�������
//����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
//struct Node {
//     int val;
//     struct Node *next;
//     struct Node *random;
//};
//
//
//struct Node* copyRandomList(struct Node* head) {
//	if (head == NULL)
//		return head;
//	//�������
//	struct Node* cur = head;
//	while (cur != NULL)
//	{
//		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//		newNode->val = cur->val;
//		newNode->next = cur->next;
//		cur->next = newNode;
//		cur = newNode->next;
//	}
//	//�������ֵ
//	cur = head;
//	while (cur != NULL)
//	{
//		struct Node* copy = cur->next;
//		if (cur->random == NULL)
//			copy->random = NULL;
//		else
//		{
//			copy->random = cur->random->next;
//		}
//		cur = copy->next;
//	}
//	//�ֳ���������
//	cur = head;
//	struct Node* newHead = head->next;
//	while (cur != NULL)
//	{
//		struct Node* copy = cur->next;
//		struct Node* end = copy->next;
//
//		cur->next = end;
//		if (end != NULL)
//			copy->next = end->next;
//		cur = end;
//	}
//	return newHead;
//}


//5.
//��������в�������

//struct ListNode {
//     int val;
//     struct ListNode *next;
//};
//
//
//struct ListNode* insertionSortList(struct ListNode* head){
//	if (head == NULL || head->next == NULL)
//		return head;
//	//��һ���������
//	struct ListNode* cur = head->next;
//	//����ĩβ��
//	struct ListNode* tail = head;
//	while (cur != NULL)
//	{
//		if (cur->val < tail->val)
//		{
//			struct ListNode* start = head;
//			struct ListNode* prev = NULL;
//			struct ListNode* next = cur->next;
//			while (start && start->val < cur->val)
//			{
//				prev = start;
//				start = start->next;
//			}
//
//			if (prev == NULL)
//			{
//				cur->next = head;
//				head = cur;
//			}
//			else
//			{
//				prev->next = cur;
//				cur->next = start;
//			}
//			tail->next = next;
//			cur = next;
//		}
//		else
//		{
//			tail = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}


//6.
//ɾ�������е��ظ����
//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5


//struct ListNode {
//int val;
//struct ListNode *next;
//ListNode(int x) :
//val(x), next(NULL) {
//}
//};
//
//class Solution {
//public:
//	ListNode* deleteDuplication(ListNode* pHead)
//	{
//		if (pHead == NULL || pHead->next == NULL)
//			return pHead;
//		struct ListNode* cur = pHead;
//		struct ListNode* prev = NULL;
//		while (cur != NULL)
//		{
//			struct ListNode* next = cur->next;
//			if (next && cur->val == next->val)
//			{
//				while (next && cur->val == next->val)
//				{
//					next = next->next;
//				}
//
//				while (cur != next)
//				{
//					struct ListNode* tmp = cur->next;
//					free(cur);
//					cur = tmp;
//				}
//
//				if (prev == NULL)
//					pHead = cur;
//				else
//					prev->next = cur;
//			}
//			else
//			{
//				prev = cur;
//				cur = next;
//			}
//		}
//		return pHead;
//	}
//};