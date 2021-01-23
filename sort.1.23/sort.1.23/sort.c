#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

void merge(int* arr, int begin, int end, int* tmp)
{
	int mid = begin + (end - begin) / 2;
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int index = begin;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}

	if (begin1 <= end1)
		memcpy(tmp + index, arr + begin1, sizeof(int)*(end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + index, arr + begin2, sizeof(int)*(end2 - begin2 + 1));
	memcpy(arr+begin, tmp+begin, sizeof(int)*(end - begin + 1)); 
}


//递归归并排序
void _mergeSort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;

	_mergeSort(arr, begin, mid, tmp);
	_mergeSort(arr, mid + 1, end, tmp);

	merge(arr, begin, end, tmp); 
}


void mergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);

	_mergeSort(arr, 0, n - 1, tmp);

	free(tmp);
}


//非递归
void mergeSortNOR(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int)* n);
	int step = 1;
	while (step < n)
	{
		for (int begin = 0; begin < n; begin += 2 * step)
		{
			int mid = begin + step - 1;
			int end = begin + 2 * step - 1;

			if (mid >= n - 1)
				continue;

			if (end >= n)
				end = n - 1;
			merge(arr, begin, end, tmp);
		}
		step = step * 2;
	}

	free(tmp);
}


//计数排序
void countSort(int* arr,int n)
{
	int max = arr[0];
	int min = arr[0];
	//遍历数组，找出最小值
	for (int i = 1; i < n ; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	int range = max - min + 1;

	//将数组元素置0
	int* countArr = (int*)calloc(range, sizeof(int));

	//计数
	for (int i = 0; i < n; i++)
	{
		countArr[arr[i] - min]++;
	}

	//遍历计数数组，排序
	int index = 0;
	for (int i = 0; i < range; i++)
	{
		while (countArr[i]--)
		{
			arr[index++] = i + min;
		}
	}
}


void countTest()
{
	int arr[] = { 2, 3, 4, 5, 6, 4, 3, 2, 5, 10, 4, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	countSort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void test()
{
	srand((unsigned)time(NULL));
	int n;
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
	mergeSort(arr1, n);
	int end = clock();
	printf("mergeSort:%d\n", end - begin);


	begin = clock();
	mergeSort(arr2, n);
	end = clock();
	printf("mergeSortNOR:%d\n", end - begin);
	//for (int i = 0; i < n; i++)
	//{
	//	printf("%d ", arr2[i]);
	//}
	//printf("\n");

	free(arr);
	free(arr1);
	free(arr2);
}


int main()
{
	//test();
	countTest();
	return 0;
}