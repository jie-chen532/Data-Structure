#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>



 struct TreeNode {
   int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

//ǰ����� �ǵݹ�  ����+ջ
//typedef struct TreeNode* SDataType;
//
//typedef struct stack
//{
//	SDataType* data;
//	int size;
//	int capacity;
//}stack;
//
////ջ��ʼ��
//void initStack(stack* st)
//{
//	if (st == NULL)
//		return;
//	st->data = NULL;
//	st->size = 0;
//	st->capacity = 0;
//}
//
//
////�������
//void checkStack(stack* st)
//{
//	if (st->size == st->capacity)
//	{
//		int newLen = st->capacity == 0 ? 1 : 2 * st->capacity;
//		st->data = (SDataType*)realloc(st->data, sizeof(SDataType)*newLen);
//		st->capacity = newLen;
//	}
//}
//
//
////��ջ
//void stackPush(stack* st, SDataType val)
//{
//	if (st == NULL)
//		return;
//	checkStack(st);
//	st->data[st->size] = val;
//	st->size++;
//}
//
////��ջ
//void stackPop(stack* st)
//{
//	if (st == NULL || st->size == 0)
//		return;
//	st->size--;
//}
//
//
////ջ�����ݸ���
//int stackSize(stack* st)
//{
//	if (st == NULL)
//		return 0;
//	return st->size;
//}
//
//
////ջ�Ƿ�Ϊ��
//int checkEmpty(stack* st)
//{
//	if (st == NULL || st->size == 0)
//		return 1;
//	return 0;
//}
//
//
////ջ��Ԫ��
//SDataType stackTop(stack* st)
//{
//	return st->data[st->size - 1];
//}
//
//
//
////����
//void stackDestory(stack* st)
//{
//	if (st == NULL)
//		return;
//	free(st->data);
//	st->data = NULL;
//}
//
//int getSize(struct TreeNode* root)
//{
//	if (root == NULL)
//		return 0;
//	return getSize(root->left) + getSize(root->right) + 1;
//}
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize){
//	int sz = getSize(root);
//	int* arr = (int*)malloc(sizeof(int)* sz);
//	int index = 0;
//	stack s;
//	initStack(&s);
//	while (root || !checkEmpty(&s))
//	{
//		while (root)
//		{
//			arr[index++] = root->val;
//			stackPush(&s, root);
//			root = root->left;
//		}
//
//		struct TreeNode* node = stackTop(&s);
//		stackPop(&s);
//		root = node->right;
//	}
//	*returnSize = index;
//	return arr;
//}


//�Գƶ�����
//bool _isSymmetric(struct TreeNode* left, struct TreeNode* right)
//{
//	if (left == NULL && right == NULL)
//		return true;
//	if (left == NULL || right == NULL)
//		return false;
//	return left->val == right->val &&
//		_isSymmetric(left->left, right->right) &&
//		_isSymmetric(left->right, right->left);
//}
//
//bool isSymmetric(struct TreeNode* root){
//	if (root == NULL)
//		return true;
//	return _isSymmetric(root->left, root->right);
//}


//����������Ƿ���ͬ
//bool isSameTree(struct TreeNode* p, struct TreeNode* q){
//	if (p == NULL && q == NULL)
//		return true;
//	if (p == NULL || q == NULL)
//		return false;
//	return p->val == q->val &&
//		isSameTree(p->left, q->left) &&
//		isSameTree(p->right, q->right);
//}


//��ת������
//struct TreeNode* invertTree(struct TreeNode* root){
//	if (root)
//	{
//		struct TreeNode* tmp = root->left;
//		root->left = root->right;
//		root->right = tmp;
//
//		invertTree(root->left);
//		invertTree(root->right);
//		return root;
//	}
//	else
//		return NULL;
//}


//��ֵ������
//bool _isUnivalTree(struct TreeNode* node, int val)
//{
//	if (node == NULL)
//		return true;
//	return node->val == val &&
//		_isUnivalTree(node->left, val) &&
//		_isUnivalTree(node->right, val);
//}
//
//bool isUnivalTree(struct TreeNode* root){
//	if (root == NULL)
//		return true;
//	return  _isUnivalTree(root, root->val);
//}



//��һ����������
//bool isSame(struct TreeNode* p, struct TreeNode* q)
//{
//	if (p == NULL && q == NULL)
//		return true;
//	if (p == NULL || q == NULL)
//		return false;
//	return p->val == q->val &&
//		isSame(p->left, q->left) &&
//		isSame(p->right, q->right);
//}
//
//
//bool isSubtree(struct TreeNode* s, struct TreeNode* t){
//	if (t == NULL)
//		return true;
//	if (s == NULL)
//		return false;
//	return  isSame(s, t) ||
//		isSubtree(s->left, t) ||
//		isSubtree(s->right, t);
//}


//�ж�һ�����Ƿ���ƽ�������
//int BHeight(struct TreeNode* root)
//{
//	if (root == NULL)
//		return 0;
//	int left = BHeight(root->left);
//	int right = BHeight(root->right);
//	return left > right ? left + 1 : right + 1;
//}
//
//bool isBalanced(struct TreeNode* root){
//	if (root == NULL)
//		return true;
//	int left = BHeight(root->left);
//	int right = BHeight(root->right);
//	return abs(left - right) < 2 &&
//		isBalanced(root->left) &&
//		isBalanced(root->right);
//}