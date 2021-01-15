#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef int HDataType;
typedef struct Heap
{
	HDataType* data;
	int size;
	int capacity;
}Heap;

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//���µ�����logn��С�ѣ�
void shiftDown(int* arr, int  n, int pos)
{
	int child = 2 * pos + 1;//����
	while (child < n)
	{
		//�ҳ����Һ�����Сֵ
		if (child + 1 < n && arr[child] > arr[child + 1])
			++child;
		if (arr[child] < arr[pos])
		{
			swap(&arr[child], &arr[pos]);
			pos = child;
			child = 2 * pos + 1;
		}
		else
			break;
	}
}


//�ѵĴ���
void createHeap(int* arr, int n)
{
	//�ӵ�һ����Ҷ�ӽ�㿪ʼ
	int i = 0;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(arr, n, i);
	}
}


//���ϵ���(С��)
void shiftUp(int* arr, int n, int pos)
{
	int parent = (pos - 1) / 2;
	while (pos > 0)
	{
		if (arr[pos] < arr[parent])
		{
			swap(&arr[pos], &arr[parent]);
			pos = parent;
			parent = (pos - 1) / 2;
		}
		else
			break;
	}
}


//��ʼ��
void InitHeap(Heap* hp)
{
	if (hp == NULL)
		return;
	hp->capacity = hp->size = 0;
	hp->data = NULL;
}


//�������
void checkCapacity(Heap* hp)
{
	if (hp->size == hp->capacity)
	{
		hp->capacity = hp->capacity == 0 ? 1 : 2 * hp->capacity;
		hp->data = (HDataType*)realloc(hp->data, sizeof(HDataType)*hp->capacity);
	}
}


//�ѵĲ���
void heapPush(Heap* hp, HDataType val)
{
	//�������
	checkCapacity(hp);
	//β��
	hp->data[hp->size++] = val;
	//���ϵ���
	shiftUp(hp->data, hp->size, hp->size-1);
}


//�ѵ��п�
int heapEmpty(Heap* hp)
{
	if (hp == NULL || hp->size == 0)
		return 1;
	return 0;
}


//�ѵ�ɾ��
void heapPop(Heap* hp)
{
	//�п�
	if (heapEmpty(hp))
		return;
	//���(��С)�����һ��Ԫ�ؽ���
	swap(&hp->data[0], &hp->data[hp->size - 1]);
	//βɾ
	hp->size--;
	//���µ���
	shiftDown(hp->data, hp->size, 0);
}

//ȡջ��Ԫ��
HDataType heapTop(Heap* hp)
{
	return hp->data[0];
}

//�ѵ����ݸ���
int heapSize(Heap* hp)
{
	return hp->size;
}

// ��������ж�����
void HeapSort(int* a, int n)
{
	//����
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		shiftDown(a, n, i);
	}
	
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		shiftDown(a, end, 0);
		--end; 
	}
}


void PrintTopK(int* arr, int n, int k)
{
	Heap hp;
	InitHeap(&hp);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		heapPush(&hp,arr[i]);
	}
	while (k--)
	{
		printf("%d ", heapTop(&hp));
		heapPop(&hp);
	}
}


//�ѵ�����
void HeapDestory(Heap* hp)
{
	free(hp->data);
	hp->data = NULL; 
}

void printHeap(Heap* hp)
{
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
	}
	printf("\n");
}

//void test()
//{
//	Heap hp;
//	InitHeap(&hp);
//	heapPush(&hp, 8);
//	heapPush(&hp, 7);
//	heapPush(&hp, 12);
//	heapPush(&hp, 9);
//	heapPush(&hp, 3);
//	heapPush(&hp, 4);
//	heapPush(&hp, 6);
//	heapPush(&hp, 5);
//	
//	heapPop(&hp);
//	heapPop(&hp);
//	heapPop(&hp);
//	//printHeap(&hp);
//	//printf("%d\n", heapTop(&hp));
//	HeapDestory(&hp);
//	//printf("%d\n", heapTop(&hp));
//}

void test()
{
	int arr[] = { 2, 3, 6, 5, 8, 7, 1, 9 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	test();
	return 0;
}