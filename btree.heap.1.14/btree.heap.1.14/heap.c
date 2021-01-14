#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//向下调整算法
//前提：左右子树必须是一个堆
//小堆
void downJudgeSmall(int* arr, int n, int curPos)
{
	int child = 2 * curPos + 1;//左孩子
	while (child < n)
	{
		//左右孩子比较，找出最小值
		if (child + 1 < n && arr[child] > arr[child + 1])
			++child;
		if (arr[child] < arr[curPos])
		{
			int tmp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = tmp;
			//更新位置
			curPos = child;
			child = 2 * child + 1;
		}
		else
			break; 
	}
}


//大根堆
void downJudgeBig(int* arr, int n, int curPos)
{
	int child = 2 * curPos + 1;//左孩子
	while (child < n)
	{
		//左右孩子比较，找出最大值
		if (child + 1 < n && arr[child] < arr[child + 1])
			++child;
		if (arr[child] >  arr[curPos])
		{
			int tmp = arr[child];
			arr[child] = arr[curPos];
			arr[curPos] = tmp;
			//更新位置
			curPos = child;
			child = 2 * child + 1;
		}
		else
			break;
	}
}


//void test()
//{
//	int arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
//	downJudgeSmall(arr, sizeof(arr) / sizeof(arr[0]), 0);
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	test();
//}


//void createHeap(int* arr, int n)
//{
//	for (int i = (n - 2) / 2; i >= 0; i--)
//	{
//		downJudgeSmall(arr, n, i);
//	}
//}


//建堆
//将小根堆->大根堆 
void createHeap(int* arr, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		downJudgeBig(arr, n, i);
	}
}

int main()
{
	//int arr[] = { 100, 20, 3, 6, 89, 12, 15, 36, 25 };
	int arr[] = { 1,5,3,8,7,6 };
	createHeap(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
}