#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"queue.h"

//插入排序  O(n^2)
//数据有序时---->O(n)
void insertSort(int* arr, int n)
{
	int index = 1;
	while (index < n)
	{
		int end = index - 1;
		int tmp = arr[index];
		while (end >= 0 && arr[end] > tmp)
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = tmp;
		index++;
	}
}


//希尔排序
void shellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		int index = gap;
		while (index < n)
		{
			int tmp = arr[index];
			int end = index - gap;
			while (end >= 0 && arr[end] > tmp)
			{
				arr[end + gap] = arr[end];
				end = end - gap;
			}
			arr[end + gap] = tmp;
			index++; 
		}
	}
}

void swap(int* arr, int m, int n)
{
	int tmp = arr[m];
	arr[m] = arr[n];
	arr[n] = tmp;
}


//选择排序
void selectSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minIdx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[minIdx] > arr[j])
				minIdx = j;
		}
		swap(arr, i, minIdx);
	}
}


//优化后选择排序
void selectSort2(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minIdx = i;//最小值下标
		int maxIdx = i;//最大值下标
		for (int j = i + 1; j < n; j++)
		{
			if (arr[minIdx] > arr[j])
				minIdx = j;
			if (arr[maxIdx] < arr[j])
				maxIdx = j; 
		}
		//最小值放在头部
		swap(arr, i, minIdx);
		//判断最大值是否在起始位置
		if (maxIdx == i)
			maxIdx = minIdx;
		//最大值放在尾部
		swap(arr, n - 1, maxIdx);
		n--;
	}
}


//堆排序
//向下调整算法:大堆
void shiftDown(int* arr, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] < arr[child + 1])
			++child;
		if (arr[child] > arr[parent])
		{
			swap(arr, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}


void heapSort(int* arr, int n)
{
	//创建堆
	for (int i = (n - 2) / 2; i >= 0; i--)
		shiftDown(arr, n, i);
	int end = n - 1;
	while (end > 0)
	{
		//与最后一个元素交换
		swap(arr, end, 0);
		//向下调整
		shiftDown(arr, end, 0);
		end--;
	}
}



//冒泡排序
void bubbleSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr, j, j + 1);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}



//获取基准值,三数取中法  前   中    后
int getMid(int* arr,int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end]) // begin  mid   end
			return mid;
		else if (arr[begin] > arr[end])  //begin   end   mid
			return end;
		else                       //end  begin  mid 
			return begin;
	}
	else
	{
		//mid >= begin
		if (arr[end] > arr[mid])  //end  mid begin
			return mid;
		else if (arr[begin] > arr[end])//mid begin end
			return begin;
		else                      //mid  end  begin
			return end;
	}
}


//快速排序hore
int paration1(int* arr, int begin, int end)
{
	//三数取中,获得中间值下标
	int mid = getMid(arr, begin, end);
	//把基准值放在开始位置
	swap(arr, begin, mid);
	//获得基准值
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		//从后往前找小的
		while (begin < end && arr[end] >= key)
			end--;
		//从前往后找大的
		while (begin < end && arr[begin] <= key)
			begin++;
		swap(arr, begin, end);
	}
	swap(arr, start, end);
	return end;
}


//快速排序—挖坑法
int paration2(int* arr, int begin, int end)
{
	//获取基准值坐标
	int mid = getMid(arr, begin, end);
	//把基准值放在开始位置
	swap(arr, mid, begin);
	//获取基准值,第一个作为坑的位置
	int key = arr[begin];
	while (begin < end)
	{
		//从后向前找小于基准值的值
		while (begin < end && arr[end] >= key)
			end--;
		//填坑
		arr[begin] = arr[end];

		while (begin < end && arr[begin] <= key)
			begin++;
		//填坑
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
}


//快速排序—前后指针
int paration3(int* arr, int begin, int end)
{
	int mid = getMid(arr, begin, end);
	swap(arr, mid, begin);
	int prev = begin;
	int cur = prev + 1;
	int key = arr[prev];
	while (cur <= end)
	{
		//当cur走到小于基准值并且prev + 1不等于cur时交换
		if (arr[cur] < key && ++prev != cur)
			swap(arr, cur, prev);
		cur++;
	}
	swap(arr, prev, begin);
	return prev;
}


void quickSort1(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//划分
	int div = paration1(arr, begin, end);
	//左边
	quickSort1(arr, begin, div - 1);
	quickSort1(arr, div + 1, end);
}

void quickSort2(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//划分
	int div = paration2(arr, begin, end);
	//左边
	quickSort2(arr, begin, div - 1);
	quickSort2(arr, div + 1, end);
}


void quickSort3(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//划分
	int div = paration3(arr, begin, end);
	//左边
	quickSort3(arr, begin, div - 1);
	quickSort3(arr, div + 1, end);
}


//非递归:不会有栈溢出的风险
//使用队列当容器
void quickSortNR(int* arr,int n)
{
	queue q;
	queueInit(&q);
	queuePush(&q, 0);
	queuePush(&q, n-1);
	while (!(queueEmpty(&q)))
	{
		int left = queueFront(&q);
		queuePop(&q);
		int right = queueFront(&q);
		queuePop(&q);

		int div = paration1(arr, left, right);

		
		if (left < div - 1)
		{
			queuePush(&q, left);
			queuePush(&q, div - 1);
		}

		if (div + 1 < right)
		{
			queuePush(&q, div + 1);
			queuePush(&q, right);
		}

	}
}



void test()
{
	srand((unsigned)time(NULL));
	int n = 0;
	printf("数据量:");
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int)*n);
	int* arr1 = (int*)malloc(sizeof(int)*n);
	int* arr2 = (int*)malloc(sizeof(int)*n);
	int* arr3 = (int*)malloc(sizeof(int)*n);
	int* arr4 = (int*)malloc(sizeof(int)*n);
	int* arr5 = (int*)malloc(sizeof(int)*n);
	int* arr6 = (int*)malloc(sizeof(int)*n);
	int* arr7 = (int*)malloc(sizeof(int)*n);
	int* arr8 = (int*)malloc(sizeof(int)*n);
	int* arr9 = (int*)malloc(sizeof(int)*n);
	int* arr10 = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}

	memcpy(arr1, arr, sizeof(int)*n);
	memcpy(arr2, arr, sizeof(int)*n);
	memcpy(arr3, arr, sizeof(int)*n);
	memcpy(arr4, arr, sizeof(int)*n);
	memcpy(arr5, arr, sizeof(int)*n);
	memcpy(arr6, arr, sizeof(int)*n);
	memcpy(arr7, arr, sizeof(int)*n);
	memcpy(arr8, arr, sizeof(int)*n);
	memcpy(arr9, arr, sizeof(int)*n);
	memcpy(arr10, arr, sizeof(int)*n);


	int begin = clock();
	insertSort(arr1, n);
	int end = clock();
	printf("InsertSort:%d\n", end - begin);


	begin = clock();
	shellSort(arr2, n);
	end = clock();
	printf("ShellSort:%d\n", end - begin);


	begin = clock();
	selectSort(arr3, n);
	end = clock();
	printf("selectSort:%d\n", end - begin);


	begin = clock();
	selectSort2(arr4, n);
	end = clock();
	printf("selectSort2:%d\n", end - begin);



	begin = clock();
	heapSort(arr5, n);
	end = clock();
	printf("heapSort:%d\n", end - begin);


	begin = clock();
	quickSort1(arr7, 0, n - 1);
	end = clock();
	printf("quickSort1:%d\n", end - begin);


	begin = clock();
	quickSort2(arr8, 0, n - 1);
	end = clock();
	printf("quickSort2:%d\n", end - begin);


	begin = clock();
	quickSort3(arr9, 0, n - 1);
	end = clock();
	printf("quickSort3:%d\n", end - begin);


	begin = clock();
	quickSortNR(arr10, n);
	end = clock();
	printf("quickSortNR:%d\n", end - begin);


	//begin = clock();
	//bubbleSort(arr6, n);
	//end = clock();
	//printf("bubbleSort:%d\n", end - begin);


	//begin = clock();
	//bubbleSort(arr6, n);
	//end = clock();
	//printf("sorted bubbleSort:%d\n", end - begin);
}






int main()
{
	//int arr[] = { 1, 2, 3, 7, 3, 4, 0, 10 };
	//int sz = 8;
	//insertSort(arr, sz);
	//for (int i = 0; i < sz; i++)
	//{
	//	printf("%d ", arr[i]);
	//}

	test();
}

