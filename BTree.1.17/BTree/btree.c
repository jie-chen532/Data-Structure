#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef char DataType;

//二叉树的结点
typedef struct BNode
{
	struct BNode* left;//左孩子
	struct BNode* right;//右孩子
	DataType data;
}Node;


typedef Node* QDataType;
 

typedef Node* QDataType;
//队列 带有尾指针的单链表
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


//尾插
void queuePush(queue* q, QDataType val)
{
	if (q == NULL)
		return;
	struct QNode* node = createQNode(val);
	//第一个节点
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


//出队
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


//获取队头元素
QDataType queueFront(queue* q)
{
	return q->head->data;
}


//获取队尾元素
QDataType queueBack(queue* q)
{
	return q->tail->data;
}


//队列判空
int queueEmpty(queue* q)
{
	return q->head == NULL;
}


//队列元素个数
int queueSize(queue* q)
{
	if (q == NULL)
		return 0;
	return q->size;
}



//队列销毁
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


//二叉链
typedef struct BTree
{
	Node* root;//根节点
}BTree;

//创建二叉链  前序
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

//前序遍历  根-左-右
void bTreePrevOrder(Node* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->data);
	bTreePrevOrder(root->left);
	bTreePrevOrder(root->right);
}


//中序遍历  左-根-右
void bTreeInOrder(Node* root)
{
	if (root)
	{
		bTreeInOrder(root->left);
		printf("%c ", root->data);
		bTreeInOrder(root->right);
	}
}


//后序遍历  左-右-根
void bTreePostOrder(Node* root)
{
	if (root)
	{
		bTreePostOrder(root->left);
		bTreePostOrder(root->right);
		printf("%c ", root->data);
	}
}


//节点个数  左子树+右子树+1
int BTreeSize(Node* root)
{
	if (root == NULL)
		return 0;
	return BTreeSize(root->left) + BTreeSize(root->right) + 1;
}


//二叉树高度  max(左右子树的高度) + 1
int BTreeHeight(Node* root)
{
	if (root == NULL)
		return 0;
	int left = BTreeHeight(root->left);
	int right = BTreeHeight(root->right);
	return left > right ? left + 1 : right + 1;
}


//叶子节点个数 
int BTreeLeaf(Node* root)
{
	//空节点
	if (root == NULL)
		return 0;
	//叶子节点
	if (root->left == NULL && root->right == NULL)
		return 1;
	//非叶子节点
	return BTreeLeaf(root->left) + BTreeLeaf(root->right); 
}


//第K层节点个数   
int BTreeKSize(Node* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BTreeKSize(root->left, k - 1) + BTreeKSize(root->right, k - 1);
}


//二叉树查找值为x的节点
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



//层序遍历   用队列当作容器
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


//判断是否是完全二叉树
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

//销毁二叉树
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
	printf("前序遍历--->");
	bTreePrevOrder(root); 
	printf("\n");
	printf("中序遍历--->");
	bTreeInOrder(root);
	printf("\n");
	printf("后序遍历--->");
	bTreePostOrder(root);
	printf("\n");
	printf("层序遍历--->");
	bTreeLevelOrder(root);
	printf("\n");

	printf("节点个数--->%d\n", BTreeSize(root));
	printf("高度------->%d\n", BTreeHeight(root));
	printf("叶子节点数->%d\n", BTreeLeaf(root)); 
	printf("第3层节点个数->%d\n", BTreeKSize(root, 3));
	printf("是否为完全二叉树->%d\n", isBTreeComplete(root));

	BTreeDestory(&root);
}


int main()
{
	test();
	return 0;
}