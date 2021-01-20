#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//插入排序  O(n^2)
//数据有序时---->O(n)
void insertSort(int* arr,int n)
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
			int end = index - gap;
			int tmp = arr[index];
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


void test()
{
	srand((unsigned)time(NULL));
	int n = 0;
	printf("数据量:");
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int)*n);
	int* arr1 = (int*)malloc(sizeof(int)*n);
	int* arr2 = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}

	memcpy(arr1, arr, sizeof(int)*n);
	memcpy(arr2, arr, sizeof(int)*n);


	int begin = clock();
	insertSort(arr1, n);
	int end = clock();
	printf("InsertSort:%d\n", end - begin);


    int begin1 = clock();
	shellSort(arr2, n);
	int end1 = clock();
	printf("ShellSort:%d\n", end1- begin1);
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