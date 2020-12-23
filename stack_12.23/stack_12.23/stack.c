#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>

//˳���ʵ��ջ
typedef int SDataType;

typedef struct stack
{
	SDataType* data;
	int size;
	int capacity;
}stack;

//ջ��ʼ��
void initStack(stack* st)
{
	if (st == NULL)
		return;
	st->data = NULL;
	st->size = 0;
	st->capacity = 0;
}


//�������
void checkStack(stack* st)
{
	if (st->size == st->capacity)
	{
		int newLen = st->capacity == 0 ? 1 : 2 * st->capacity;
		st->data = (SDataType*)realloc(st->data, sizeof(SDataType)*newLen);
		st->capacity = newLen;
	}
}


//��ջ
void stackPush(stack* st, SDataType val)
{
	if (st == NULL)
		return;
	checkStack(st);
	st->data[st->size] = val;
	st->size++;
}

//��ջ
void stackPop(stack* st)
{
	if (st == NULL || st->size == 0)
		return;
	st->size--;
}


//ջ�����ݸ���
int stackSize(stack* st)
{
	if (st == NULL)
		return 0;
	return st->size;
}


//ջ�Ƿ�Ϊ��
int checkEmpty(stack* st)
{
	if (st == NULL || st->size == 0)
		return 1;
	return 0;
}


//ջ��Ԫ��
SDataType stackTop(stack* st)
{
	return st->data[st->size - 1];
}


//��ӡ
void stackPrint(stack* st)
{
	if (st == NULL || st->size == 0)
		return;
	while (!checkEmpty(st))
	{
		printf("%d ", stackTop(st));
		stackPop(st);
	}
	printf("\n");
}

//����
void stackDestory(stack* st)
{
	if (st == NULL)
		return;
	free(st->data);
	st->data = NULL;
}

int main()
{
	struct stack st;
	initStack(&st);
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	stackPush(&st, 4);
	stackPush(&st, 5);//5 4 3 2 1

	stackPop(&st);
	stackPop(&st);//3 2 1
  
	stackDestory(&st);
	stackPrint(&st);
	return 0;
}