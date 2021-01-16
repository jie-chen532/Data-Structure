#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef char DataType;
//�������Ľ��
typedef struct BNode
{
	struct BNode* left;//����
	struct BNode* right;//�Һ���
	DataType data;
}Node;

//������
typedef struct BTree
{
	Node* root;//���ڵ�
}BTree;

//����������  ǰ��
Node* BTreeCreate(DataType arr[], int* index) 
{
	if (arr[*index] == '#')
	{
		(*index)++;
		return NULL;
	}
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = arr[*index];
	(*index)++;
	node->left = BTreeCreate(arr, index);
	node->right = BTreeCreate(arr, index);
	return node;
}

//ǰ�����  ��-��-��
void bTreePrevOrder(Node* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->data);
	bTreePrevOrder(root->left);
	bTreePrevOrder(root->right);
}


//�������  ��-��-��
void bTreeInOrder(Node* root)
{
	if (root)
	{
		bTreeInOrder(root->left);
		printf("%c ", root->data);
		bTreeInOrder(root->right);
	}
}


//�������  ��-��-��
void bTreePostOrder(Node* root)
{
	if (root)
	{
		bTreePostOrder(root->left);
		bTreePostOrder(root->right);
		printf("%c ", root->data);
	}
}


//�ڵ����  ������+������+1
int BTreeSize(Node* root)
{
	if (root == NULL)
		return 0;
	return BTreeSize(root->left) + BTreeSize(root->right) + 1;
}


//�������߶�  max(���������ĸ߶�) + 1
int BTreeHeight(Node* root)
{
	if (root == NULL)
		return 0;
	int left = BTreeHeight(root->left);
	int right = BTreeHeight(root->right);
	return left > right ? left + 1 : right + 1;
}


//Ҷ�ӽڵ���� 
int BTreeLeaf(Node* root)
{
	//�սڵ�
	if (root == NULL)
		return 0;
	//Ҷ�ӽڵ�
	if (root->left == NULL && root->right == NULL)
		return 1;
	//��Ҷ�ӽڵ�
	return BTreeLeaf(root->left) + BTreeLeaf(root->right); 
}


//��K��ڵ����   
int BTreeKSize(Node* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BTreeKSize(root->left, k - 1) + BTreeKSize(root->right, k - 1);
}


//����������ֵΪx�Ľڵ�
Node* BTreeFind(Node* root, char val)
{
	if (root)
	{
		Node* node;
		if (root->data == val)
			return root;
		node = BTreeFind(root->left, val);
		if (node)
			return node;
		else
			return BTreeFind(root->right, val); 
	}
	else
		return NULL;
}


//���ٶ�����
void BTreeDestory(Node** root)
{
	if (*root)
	{
		BTreeDestory(&((*root)->left));
		BTreeDestory(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}

void test()
{
	char arr[] = "ABD##E#H##CF##G##";
	int index = 0;
	Node* root = BTreeCreate(arr, &index);
	printf("ǰ�����--->");
	bTreePrevOrder(root); 
	printf("\n");
	printf("�������--->");
	bTreeInOrder(root);
	printf("\n");
	printf("�������--->");
	bTreePostOrder(root);
	printf("\n");

	printf("�ڵ����--->%d\n", BTreeSize(root));
	printf("�߶�------->%d\n", BTreeHeight(root));
	printf("Ҷ�ӽڵ���->%d\n", BTreeLeaf(root)); 
	printf("��3��ڵ����->%d\n", BTreeKSize(root, 3));

	BTreeDestory(&root);
}


int main()
{
	test();
	return 0;
}