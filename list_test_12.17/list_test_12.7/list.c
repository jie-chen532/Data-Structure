#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>

//1.
//相交链表
//编写一个程序，找到两个单链表相交的起始节点。


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
//环形链表
//给定一个链表，判断链表中是否有环。


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
//环形链表2
//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

//struct ListNode {
//     int val;
//     struct ListNode *next;
//};
//
//struct ListNode *detectCycle(struct ListNode *head) {
//	if (head == NULL)
//		return NULL;
//	//找相遇结点
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
//	//分别从相遇结点和头结点遍历
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
//复制带随机指针的链表
//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
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
//	//拷贝结点
//	struct Node* cur = head;
//	while (cur != NULL)
//	{
//		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//		newNode->val = cur->val;
//		newNode->next = cur->next;
//		cur->next = newNode;
//		cur = newNode->next;
//	}
//	//拷贝随机值
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
//	//分成两个链表
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
//对链表进行插入排序

//struct ListNode {
//     int val;
//     struct ListNode *next;
//};
//
//
//struct ListNode* insertionSortList(struct ListNode* head){
//	if (head == NULL || head->next == NULL)
//		return head;
//	//第一个排序的数
//	struct ListNode* cur = head->next;
//	//有序末尾数
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
//删除链表中的重复结点
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5


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