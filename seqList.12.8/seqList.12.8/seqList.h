#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int SLDataType;

typedef struct seqList
{
	SLDataType* data;
	int size;//有效元素个数
	int capacity;//总容量
}seqList;

//初始化一个空的顺序表
void initseqList(seqList* sl);

//尾插
void seqListPushBack(seqList* sl, SLDataType val);

//检查容量
void seqListCheckCapacity(seqList* sl);

//尾删
void seqListPopBack(seqList* sl);

//具体位置的元素
SLDataType seqListAt(seqList* sl, int pos);

//头插
void seqListPushFront(seqList* sl, SLDataType val);

//头删
void seqListPopFront(seqList* sl);

//任意位置插入
void seqListInsert(seqList* sl, int pos, SLDataType val);

//任意位置删除
void seqListErase(seqList* sl, int pos);

//打印
void seqListPrint(seqList* sl);

