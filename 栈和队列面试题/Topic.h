#pragma once
#include "Queue.h"
#include "Stack.h"

/////////////////////ջ�Ͷ���������////////////////////////////////
//����ջʵ��һ������
typedef struct QueueByTwoStack
{
	Stack s1;
	Stack s2;
}QueueByTwoStack;

void QueueByTwoStackInit(QueueByTwoStack* qts);
void QueueByTwoStackPush(QueueByTwoStack* qts,DataType data);
void QueueByTwoStackPop(QueueByTwoStack* qts);
int QueueByTwoStackSize(QueueByTwoStack* qts);
int QueueByTwoStackEmpty(QueueByTwoStack* qts);
DataType QueueByTwoStackFront(QueueByTwoStack* qts);

//��������ʵ��һ��ջ

typedef struct StackByTwoQueue
{
	Queue q1;
	Queue q2;
}StackByTwoQueue;

void StackByTwoQueueInit(StackByTwoQueue* stq);
void StackByTwoQueuePush(StackByTwoQueue* stq, DataType data);
void StackByTwoQueuePop(StackByTwoQueue* stq);
int StackByTwoQueueSize(StackByTwoQueue* stq);
int StackByTwoQueueEmpty(StackByTwoQueue* stq);
void StackByTwoQueueDestroy(StackByTwoQueue* stq);
int StackByTwoQueueTop(StackByTwoQueue* stq);
void TestStackByTwoQueue();