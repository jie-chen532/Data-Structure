#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>

typedef int SDataType;

typedef struct stack
{
	SDataType* data;
	int size;
	int capacity;
}stack;


//��ʼ��
void initStack(stack* st)
{
	if (st == NULL)
		return;
	st->data = NULL;
	st->size = 0;
	st->capacity = 0;
}


//���ռ�
void checkCapacity(stack* st)
{
	if (st->size == st->capacity)
	{
		int newCap = st->size == 0 ? 1 : 2 * st->capacity;
		st->data = (SDataType*)realloc(st->data, sizeof(SDataType)*newCap);
		st->capacity = newCap;
	}
}


//��ջ
void stackPush(stack* st, SDataType val)
{
	if (st == NULL)
		return;
	checkCapacity(st);
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


//ջ��Ԫ�ظ���
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


void test()
{
	struct stack st;
	initStack(&st);
	
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	stackPush(&st, 4);
	stackPush(&st, 5);
	stackPush(&st, 6);
	stackPush(&st, 7);//7 6 5 4 3 2 1

	stackPop(&st);
	stackPop(&st);
	stackPop(&st);
	stackPop(&st);//3 2 1

	stackPrint(&st);


}

int main()
{
	test();
	return 0;
}