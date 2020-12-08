#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int SLDataType;

typedef struct seqList
{
	SLDataType* data;
	int size;//��ЧԪ�ظ���
	int capacity;//������
}seqList;

//��ʼ��һ���յ�˳���
void initseqList(seqList* sl);

//β��
void seqListPushBack(seqList* sl, SLDataType val);

//�������
void seqListCheckCapacity(seqList* sl);

//βɾ
void seqListPopBack(seqList* sl);

//����λ�õ�Ԫ��
SLDataType seqListAt(seqList* sl, int pos);

//ͷ��
void seqListPushFront(seqList* sl, SLDataType val);

//ͷɾ
void seqListPopFront(seqList* sl);

//����λ�ò���
void seqListInsert(seqList* sl, int pos, SLDataType val);

//����λ��ɾ��
void seqListErase(seqList* sl, int pos);

//��ӡ
void seqListPrint(seqList* sl);

