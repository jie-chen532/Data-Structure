#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//1.
//移除链表元素
//删除链表中等于给定值 val 的所有节点。

//struct ListNode {
//     int val;
//     struct ListNode *next;
//};
//
//
//struct ListNode* removeElements(struct ListNode* head, int val){
//	struct ListNode* prev = NULL;
//	struct ListNode* tail = head;
//	while (tail != NULL)
//	{
//		if (tail->val == val)
//		{
//			if (prev == NULL)
//			{
//				head = tail->next;
//				free(tail);
//				tail = head;
//			}
//			else
//			{
//				prev->next = tail->next;
//				free(tail);
//				tail = prev->next;
//			}
//		}
//		else
//		{
//			prev = tail;
//			tail = tail->next;
//		}
//	}
//	return head;
//}


//2.
//反转一个单链表
//struct ListNode {
//     int val;
//     struct ListNode *next;
//};
//
//
//struct ListNode* reverseList(struct ListNode* head)
//{
//	/*
//	if(head == NULL || head->next == NULL)
//	  return head;
//	//头插
//	struct ListNode* newHead = NULL;
//	struct ListNode* cur = head;
//	while(cur != NULL)
//	{
//	struct ListNode* tmp = cur->next;
//	cur->next = newHead;
//	newHead = cur;
//	cur = tmp;
//	}
//	return newHead;
//	*/
//
//	//用三个变量
//	if (head == NULL || head->next == NULL)
//		return head;
//	struct ListNode* n1 = NULL;
//	struct ListNode* n2 = head;
//	struct ListNode* n3 = head->next;
//	while (n3 != NULL)
//	{
//		n2->next = n1;
//		n1 = n2;
//		n2 = n3;
//		n3 = n3->next;
//	}
//	n2->next = n1;
//	return n2;
//}



//3.
//链表的中间结点


//struct ListNode {
//     int val;
//     struct ListNode *next;
//};
//
//
//struct ListNode* middleNode(struct ListNode* head){
//	//fast走两步，slow走一步，当fast走完时，slow就是中间结点
//	/*
//	struct ListNode* fast = head;
//	struct ListNode* slow = head;
//	while(fast != NULL && fast->next != NULL)
//	{
//	fast = fast->next->next;
//	slow = slow->next;
//	}
//	return slow;
//	*/
//
//	//先遍历链表，找出链表有多少结点
//	//然后再遍历到中间结点
//	struct ListNode* tail = head;
//	int count = 0;
//	while (tail != NULL)
//	{
//		tail = tail->next;
//		count++;
//	}
//	count = count / 2;
//	tail = head;
//	while (count--)
//	{
//		tail = tail->next;
//	}
//	return tail;
//}


//4.
//输入一个链表，输出该链表中倒数第k个结点。

//struct ListNode {
//	int val;
//	struct ListNode *next;
// };
//
//
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
//	/*
//	if(pListHead == NULL)
//	return NULL;
//	struct ListNode* cur = pListHead;
//	while(k--)
//	{
//	if(cur == NULL)
//	{
//	return NULL;
//	}
//	cur = cur->next;
//	}
//	struct ListNode* start = pListHead;
//	while(cur != NULL)
//	{
//	cur = cur->next;
//	start = start->next;
//	}
//	return start;
//	*/
//	if (pListHead == NULL)
//		return NULL;
//	int count = 0;
//	struct ListNode* cur = pListHead;
//	while (cur != NULL)
//	{
//		count++;
//		cur = cur->next;
//	}
//	int tmp = count - k;
//	if (tmp < 0)
//		return NULL;
//	cur = pListHead;
//	while (tmp--)
//	{
//		cur = cur->next;
//	}
//	return cur;
//}


//5.合并两个有序链表


//struct ListNode {
//     int val;
//     struct ListNode *next;
//};
//
//
//
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
//	if (l1 == NULL)
//		return l2;
//	if (l2 == NULL)
//		return l1;
//	//无头结点
//	
//	//struct ListNode* newHead = NULL;
//	//struct ListNode* cur1 = l1;
//	//struct ListNode* cur2 = l2;
//	//struct ListNode* cur = NULL;
//	//if(l1->val <= l2->val)
//	//{
//	//	newHead = l1;
//	//    cur1 = l1->next;
//	//    cur = l1;
//	//}
//	//else
//	//{
//	//	newHead = l2;
//	//    cur2 = l2->next;
//	//    cur = l2;
//	//}
//
//	//while(cur1 != NULL && cur2 != NULL)
//	//{
//	//	if(cur1->val <= cur2->val)
//	//	{
//	//		cur->next = cur1;
//	//        cur = cur1;
//	//        cur1 = cur1->next;
//	//    }
//	//    else
//	//   {
//	//		cur->next = cur2;
//	//        cur = cur2;
//	//        cur2 = cur2->next;
//	//	}
//	//}
//	//if(cur1 != NULL)
//	//{
//	//	cur->next = cur1;
//	//}
//	//if(cur2 != NULL)
//	//{
//	//	cur->next = cur2;
//	//}
//	//return newHead;
//	//
//
//	//有头结点
//	struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* newTail = newHead;
//	struct ListNode* cur1 = l1;
//	struct ListNode* cur2 = l2;
//
//
//	while (cur1 != NULL && cur2 != NULL)
//	{
//		if (cur1->val <= cur2->val)
//		{
//			newTail->next = cur1;
//			newTail = cur1;
//			cur1 = cur1->next;
//		}
//		else
//		{
//			newTail->next = cur2;
//			newTail = cur2;
//			cur2 = cur2->next;
//		}
//	}
//	if (cur1 != NULL)
//	{
//		newTail->next = cur1;
//	}
//	if (cur2 != NULL)
//	{
//		newTail->next = cur2;
//	}
//	struct ListNode* cur = newHead->next;
//	free(newHead);
//	return cur;
//}


//6.
//链表分割
//现有一链表的头指针 ListNode* pHead，给一定值x
//编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。


//struct ListNode 
//{
//	int val;
//	struct ListNode *next;
//};
//
//struct ListNode* partition(struct ListNode* pHead, int x) {
//		//无头结点
//
//		if (pHead == NULL)
//			return pHead;
//		/*
//		struct ListNode *lessHead = NULL;
//		struct ListNode *lessTail = lessHead;
//		struct ListNode *moreHead = NULL;
//		struct ListNode *moreTail = moreHead;
//
//		struct ListNode* cur = pHead;
//		while(cur != NULL)
//		{
//		if(cur->val < x)
//		{
//		if(lessHead == NULL)
//		{
//		lessHead = cur;
//		lessTail = cur;
//		}
//		else
//		{
//		lessTail->next = cur;
//		lessTail = cur;
//		}
//		cur = cur->next;
//		}
//		else
//		{
//		if(moreHead == NULL)
//		{
//		moreHead = cur;
//		moreTail = cur;
//		}
//		else
//		{
//		moreTail->next = cur;
//		moreTail = cur;
//		}
//		cur = cur->next;
//		}
//		}
//		if(moreHead != NULL)
//		moreTail->next = NULL;
//		//小链表为空，返回大链表
//		if(lessHead == NULL)
//		return moreHead;
//		//大链表为空
//		if(moreHead == NULL)
//		{
//		lessTail->next = NULL;
//		return lessHead;
//		}
//		//大小链表都不为空
//		lessTail->next = moreHead;
//		return lessHead;
//		*/
//
//
//		//有头结点
//		struct ListNode *lessHead, *lessTail, *moreHead, *moreTail;
//		lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//		moreHead = moreTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//		struct ListNode *cur = pHead;
//		while (cur != NULL)
//		{
//			if (cur->val < x)
//			{
//				lessTail->next = cur;
//				lessTail = cur;
//				cur = cur->next;
//			}
//			else
//			{
//				moreTail->next = cur;
//				moreTail = cur;
//				cur = cur->next;
//			}
//		}
//		moreTail->next = NULL;
//		lessTail->next = moreHead->next;
//		struct ListNode* tmp = lessHead->next;
//		free(lessHead);
//		free(moreHead);
//		return tmp;
//}



//7.链表的回文结构

//struct ListNode {
//	int val;
//    struct ListNode *next;
//};
//
//
//bool chkPalindrome(struct ListNode* A) 
//{
//		struct ListNode* slow = A;
//		struct ListNode* fast = A;
//		while (fast != NULL && fast->next != NULL)
//		{
//			fast = fast->next->next;
//			slow = slow->next;
//		}
//		struct ListNode* head = slow;
//		struct ListNode* cur = slow->next;
//		struct ListNode* tail = slow;
//		head->next = NULL;
//		while (cur != NULL)
//		{
//			head = cur;
//			cur = cur->next;
//			head->next = tail;
//			tail = head;
//		}
//		cur = head;
//		head = A;
//		while (cur != NULL)
//		{
//			if (cur->val == head->val)
//			{
//				cur = cur->next;
//				head = head->next;
//			}
//			else
//			{
//				return false;
//			}
//		}
//		return true;
//}