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


typedef Node* QDataType;
 

typedef Node* QDataType;
//���� ����βָ��ĵ�����
typedef struct QNode
{
	QDataType data;
	struct QNode* next;
}QNode;


typedef struct queue
{
	struct QNode* head;
	struct QNode* tail;
	int size;
}queue;

void queueInit(queue* q)
{
	if (q == NULL)
		return;
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
}

QNode* createQNode(QDataType val)
{
	struct QNode* node = (struct QNode*)malloc(sizeof(struct QNode));
	node->data = val;
	node->next = NULL;
	return node;
}


//β��
void queuePush(queue* q, QDataType val)
{
	if (q == NULL)
		return;
	struct QNode* node = createQNode(val);
	//��һ���ڵ�
	if (q->head == NULL)
	{
		q->head = node;
		q->tail = node;
	}
	else
	{
		q->tail->next = node;
		q->tail = node;
	}
	++q->size;
}


//����
void queuePop(queue* q)
{
	if (q == NULL || q->head == NULL)
		return;
	struct QNode* next = q->head->next;
	free(q->head);

	if (next == NULL)
		q->tail = NULL;
	q->head = next;
	--q->size;
}


//��ȡ��ͷԪ��
QDataType queueFront(queue* q)
{
	return q->head->data;
}


//��ȡ��βԪ��
QDataType queueBack(queue* q)
{
	return q->tail->data;
}


//�����п�
int queueEmpty(queue* q)
{
	return q->head == NULL;
}


//����Ԫ�ظ���
int queueSize(queue* q)
{
	if (q == NULL)
		return 0;
	return q->size;
}



//��������
void queueDestory(queue* q)
{
	if (q == NULL || q->head == NULL)
		return;
	struct QNode* node = q->head;
	while (node != NULL)
	{
		struct QNode* next = node->next;
		free(node);
		node = next;
	}
	q->head = NULL;
	q->tail = NULL;
}


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



//�������   �ö��е�������
void bTreeLevelOrder(Node* root)
{
	struct queue q;
	queueInit(&q);
	if (root)
		queuePush(&q, root);
	while (!queueEmpty(&q))
	{
		 Node* node = queueFront(&q);
		queuePop(&q);
		printf("%c ", node->data);
		if (node->left)
			queuePush(&q, node->left);
		if (node->right)
			queuePush(&q, node->right);
	}
}


//�ж��Ƿ�����ȫ������
int isBTreeComplete(Node* root)
{
	queue q;
	queueInit(&q);
	if (root)
		queuePush(&q, root);
	while (!queueEmpty(&q))
	{
		Node* node = queueFront(&q);
		queuePop(&q);
		if (node)
		{
			queuePush(&q, node->left);
			queuePush(&q, node->right);
		}
		else
			break;
	}
	while (!queueEmpty(&q))
	{
		Node* node = queueFront(&q);
		queuePop(&q);
		if (node != NULL)
			return 0;
	}
	return 1;
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
	printf("�������--->");
	bTreeLevelOrder(root);
	printf("\n");

	printf("�ڵ����--->%d\n", BTreeSize(root));
	printf("�߶�------->%d\n", BTreeHeight(root));
	printf("Ҷ�ӽڵ���->%d\n", BTreeLeaf(root)); 
	printf("��3��ڵ����->%d\n", BTreeKSize(root, 3));
	printf("�Ƿ�Ϊ��ȫ������->%d\n", isBTreeComplete(root));

	BTreeDestory(&root);
}


int main()
{
	test();
	return 0;
}