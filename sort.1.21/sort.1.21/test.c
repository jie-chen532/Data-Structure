#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"queue.h"

//��������  O(n^2)
//��������ʱ---->O(n)
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


//ϣ������
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


//ѡ������
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


//�Ż���ѡ������
void selectSort2(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minIdx = i;//��Сֵ�±�
		int maxIdx = i;//���ֵ�±�
		for (int j = i + 1; j < n; j++)
		{
			if (arr[minIdx] > arr[j])
				minIdx = j;
			if (arr[maxIdx] < arr[j])
				maxIdx = j; 
		}
		//��Сֵ����ͷ��
		swap(arr, i, minIdx);
		//�ж����ֵ�Ƿ�����ʼλ��
		if (maxIdx == i)
			maxIdx = minIdx;
		//���ֵ����β��
		swap(arr, n - 1, maxIdx);
		n--;
	}
}


//������
//���µ����㷨:���
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
	//������
	for (int i = (n - 2) / 2; i >= 0; i--)
		shiftDown(arr, n, i);
	int end = n - 1;
	while (end > 0)
	{
		//�����һ��Ԫ�ؽ���
		swap(arr, end, 0);
		//���µ���
		shiftDown(arr, end, 0);
		end--;
	}
}



//ð������
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



//��ȡ��׼ֵ,����ȡ�з�  ǰ   ��    ��
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


//��������hore
int paration1(int* arr, int begin, int end)
{
	//����ȡ��,����м�ֵ�±�
	int mid = getMid(arr, begin, end);
	//�ѻ�׼ֵ���ڿ�ʼλ��
	swap(arr, begin, mid);
	//��û�׼ֵ
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		//�Ӻ���ǰ��С��
		while (begin < end && arr[end] >= key)
			end--;
		//��ǰ�����Ҵ��
		while (begin < end && arr[begin] <= key)
			begin++;
		swap(arr, begin, end);
	}
	swap(arr, start, end);
	return end;
}


//���������ڿӷ�
int paration2(int* arr, int begin, int end)
{
	//��ȡ��׼ֵ����
	int mid = getMid(arr, begin, end);
	//�ѻ�׼ֵ���ڿ�ʼλ��
	swap(arr, mid, begin);
	//��ȡ��׼ֵ,��һ����Ϊ�ӵ�λ��
	int key = arr[begin];
	while (begin < end)
	{
		//�Ӻ���ǰ��С�ڻ�׼ֵ��ֵ
		while (begin < end && arr[end] >= key)
			end--;
		//���
		arr[begin] = arr[end];

		while (begin < end && arr[begin] <= key)
			begin++;
		//���
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
}


//��������ǰ��ָ��
int paration3(int* arr, int begin, int end)
{
	int mid = getMid(arr, begin, end);
	swap(arr, mid, begin);
	int prev = begin;
	int cur = prev + 1;
	int key = arr[prev];
	while (cur <= end)
	{
		//��cur�ߵ�С�ڻ�׼ֵ����prev + 1������curʱ����
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
	//����
	int div = paration1(arr, begin, end);
	//���
	quickSort1(arr, begin, div - 1);
	quickSort1(arr, div + 1, end);
}

void quickSort2(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//����
	int div = paration2(arr, begin, end);
	//���
	quickSort2(arr, begin, div - 1);
	quickSort2(arr, div + 1, end);
}


void quickSort3(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//����
	int div = paration3(arr, begin, end);
	//���
	quickSort3(arr, begin, div - 1);
	quickSort3(arr, div + 1, end);
}


//�ǵݹ�:������ջ����ķ���
//ʹ�ö��е�����
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
	printf("������:");
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

