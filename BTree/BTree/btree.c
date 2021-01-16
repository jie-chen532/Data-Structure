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

	printf("节点个数--->%d\n", BTreeSize(root));
	printf("高度------->%d\n", BTreeHeight(root));
	printf("叶子节点数->%d\n", BTreeLeaf(root)); 
	printf("第3层节点个数->%d\n", BTreeKSize(root, 3));

	BTreeDestory(&root);
}


int main()
{
	test();
	return 0;
}