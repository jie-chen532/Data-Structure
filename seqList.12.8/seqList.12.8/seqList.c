#define _CRT_SECURE_NO_WARNINGS 1

#include"seqList.h"

//��ʼ��һ���յ�˳���
void initseqList(seqList* sl)
{
	if (sl == NULL)
		return;
	sl->data = NULL;
	sl->size = 0;
	sl->capacity = 0;
}

//�������
void seqListCheckCapacity(seqList* sl)
{
	if (sl->size == sl->capacity)
	{
		int newCapacity = sl->capacity == 0 ? 1 : 2 * sl->capacity;
		//���ٿռ�
		SLDataType* newData = (SLDataType*)malloc(newCapacity*sizeof(SLDataType));
		//����
		memcpy(newData, sl->data, sl->size*sizeof(SLDataType));
		//�ͷ�ԭ�пռ�
		free(sl->data);
		sl->data = newData;
		//�ı�����
		sl->capacity = newCapacity;
	}
}


//β��:o(1)
void seqListPushBack(seqList* sl, SLDataType val)
{
	if (sl == NULL)
	{
		return;
	}
	//�������
	seqListCheckCapacity(sl);
	//β��
	sl->data[sl->size] = val;
	sl->size++;
}

//βɾ:o(1)
void seqListPopBack(seqList* sl)
{
	if (sl == NULL || sl->size == 0)
		return;
	sl->size--;
}

//����λ�õ�Ԫ��
SLDataType seqListAt(seqList* sl, int pos)
{
	return sl->data[pos];
}

//˳���ĳ���
int seqListSize(seqList* sl)
{
	if (sl == NULL || sl->size == 0)
		return 0;
	else
		return sl->size;
}

//ͷ��
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

//ͷɾ
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

//����λ�ò���
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

//����λ��ɾ��
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

//����
void seqListDestory(seqList* sl)
{
	if (sl != NULL && sl->data != NULL)
	{
		free(sl->data);
		sl->data = NULL;
	}
}

//��ӡ
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

