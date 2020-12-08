#define _CRT_SECURE_NO_WARNINGS 1

#include"seqList.h"

//初始化一个空的顺序表
void initseqList(seqList* sl)
{
	if (sl == NULL)
		return;
	sl->data = NULL;
	sl->size = 0;
	sl->capacity = 0;
}

//检查容量
void seqListCheckCapacity(seqList* sl)
{
	if (sl->size == sl->capacity)
	{
		int newCapacity = sl->capacity == 0 ? 1 : 2 * sl->capacity;
		//开辟空间
		SLDataType* newData = (SLDataType*)malloc(newCapacity*sizeof(SLDataType));
		//拷贝
		memcpy(newData, sl->data, sl->size*sizeof(SLDataType));
		//释放原有空间
		free(sl->data);
		sl->data = newData;
		//改变容量
		sl->capacity = newCapacity;
	}
}


//尾插:o(1)
void seqListPushBack(seqList* sl, SLDataType val)
{
	if (sl == NULL)
	{
		return;
	}
	//检查容量
	seqListCheckCapacity(sl);
	//尾插
	sl->data[sl->size] = val;
	sl->size++;
}

//尾删:o(1)
void seqListPopBack(seqList* sl)
{
	if (sl == NULL || sl->size == 0)
		return;
	sl->size--;
}

//具体位置的元素
SLDataType seqListAt(seqList* sl, int pos)
{
	return sl->data[pos];
}

//顺序表的长度
int seqListSize(seqList* sl)
{
	if (sl == NULL || sl->size == 0)
		return 0;
	else
		return sl->size;
}

//头插
void seqListPushFront(seqList* sl, SLDataType val)
{
	//if (sl == NULL)
	//	return;
	//seqListCheckCapacity(sl);
	//int end = sl->size;
	//while (end > 0)
	//{
	//	sl->data[end] = sl->data[end - 1];
	//	end--;
	//}
	//sl->data[0] = val;
	//sl->size++;
	seqListInsert(sl, 0, val);
}

//头删
void seqListPopFront(seqList* sl)
{
	//if (sl == NULL || sl->size == 0)
	//	return;
	//int start = 1;
	//while (start < sl->size)
	//{
	//	sl->data[start - 1] = sl->data[start];
	//	start++;
	//}
	//sl->size--;
	seqListErase(sl, 0);
}

//任意位置插入
void seqListInsert(seqList* sl, int pos, SLDataType val)
{
	if (sl == NULL)
		return;
	if (pos >= 0 && pos <= sl->size)
	{
		seqListCheckCapacity(sl);
		int end = sl->size;
		while (end > pos)
		{
			sl->data[end] = sl->data[end - 1];
			end--;
		}
		sl->data[pos] = val;
		sl->size++;
	}
}

//任意位置删除
void seqListErase(seqList* sl, int pos)
{
	if (sl->data == NULL || sl->size == 0)
		return;
	if (pos >= 0 && pos < sl->size)
	{
		int tmp = pos + 1;
		while (tmp < sl->size)
		{
			sl->data[tmp-1] = sl->data[tmp];
			tmp++;
		}
		sl->size--;
	}
}

//销毁
void seqListDestory(seqList* sl)
{
	if (sl != NULL && sl->data != NULL)
	{
		free(sl->data);
		sl->data = NULL;
	}
}

//打印
void seqListPrint(seqList* sl)
{
	if (sl == NULL)
		return;
	int i = 0;
	for (i = 0; i < sl->size; i++)
	{
		printf("%d ", sl->data[i]);
	}
	printf("\n");
}

void test()
{
	seqList sl;
	initseqList(&sl);
	seqListPushBack(&sl , 1);
	seqListPushBack(&sl, 2);
	seqListPushBack(&sl, 3);
	seqListPushBack(&sl, 4);
	seqListPopBack(&sl);
	seqListPopBack(&sl);
	seqListPushFront(&sl, 6);
	seqListPushFront(&sl, 5);
	seqListPopFront(&sl);
	seqListInsert(&sl, 1, 7);
	seqListErase(&sl, 2);
	//seqListPrint(&sl);
	seqListDestory(&sl);
	//printf("%d\n", seqListAt(&sl, 0));
}

int main()
{
	test();
	return 0;
}

