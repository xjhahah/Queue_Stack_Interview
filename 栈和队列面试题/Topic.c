#include "Topic.h"


void QueueByTwoStackInit(QueueByTwoStack* qts)
{
	assert(qts);
	StackInit(&qts->s1);
	StackInit(&qts->s2);
}
void QueueByTwoStackDestroy(QueueByTwoStack* qts)
{
	assert(qts);
	StackDestory(&qts->s1);
	StackDestory(&qts->s2);
}
void QueueByTwoStackPush(QueueByTwoStack* qts, DataType data)
{
	assert(qts);
	StackPush(&(qts->s1), data);
}
void QueueByTwoStackPop(QueueByTwoStack* qts)
{
	assert(qts);
	//1. 如果s2有数据直接出栈
	//2. 如果s2没有数据，则将s1数据颠倒
	if (StackEmpty(&qts->s2) == 0)
	{
		while (StackEmpty(&qts->s1))
		{
			StackPush(&qts->s2, StackTop(&qts->s1));
			StackTop(&qts->s1);
		}
	}
	StackPop(&qts->s2);
}
DataType QueueByTwoStackFront(QueueByTwoStack* qts)
{
	assert(qts);
	if (StackEmpty(&qts->s2) == 0)
	{
		while (StackEmpty(&qts->s1))
		{
			StackPush(&qts->s2, StackTop(&qts->s1));
			StackTop(&qts->s1);
		}
	}
	return StackTop(&qts->s2);
}
int QueueByTwoStackSize(QueueByTwoStack* qts)
{
	assert(qts);
	return StackSize(&qts->s1) + StackSize(&qts->s2);
}
int QueueByTwoStackEmpty(QueueByTwoStack* qts)
{
	assert(qts);
	return StackSize(&qts->s1) | StackSize(&qts->s2);
}
void TestTopic()
{
	QueueByTwoStack qts;
	QueueByTwoStackInit(&qts);

	QueueByTwoStackPush(&qts, 1);
	QueueByTwoStackPush(&qts, 2);
	QueueByTwoStackPush(&qts, 3);

	QueueByTwoStackPop(&qts);
	QueueByTwoStackPop(&qts);

	QueueByTwoStackPush(&qts, 4);
	QueueByTwoStackPush(&qts, 5);

	while (QueueByTwoStackEmpty(&qts))
	{
		printf("%d ", QueueByTwoStackFront(&qts));
		QueueByTwoStackPop(&qts);
	}
	printf("\n");
}

////////////////两个队列实现一个栈//////////////////////
void StackByTwoQueueInit(StackByTwoQueue* stq)
{
	assert(stq);
	InitQueue(&stq->q1);
	InitQueue(&stq->q2);
}
void StackByTwoQueuePush(StackByTwoQueue* stq, DataType data)
{
	assert(stq);
	if (QueueEmpty(&stq->q1) != 0)
	{
		QueuePush(&stq->q1, data);
	}
	else
	{
		QueuePush(&stq->q2, data);
	}
}
void StackByTwoQueuePop(StackByTwoQueue* stq)
{
	assert(stq);
	Queue* empty = &stq->q1;
	Queue* non_empty = &stq->q2;
	if (QueueEmpty(&stq->q1) != 0)
	{
		empty = &stq->q2;
		non_empty = &stq->q1;
	}
	while (QueueSize(non_empty)>1)
	{
		QueuePush(empty, QueueFront(non_empty));
		QueuePop(non_empty);
	}
	QueuePop(non_empty);
}
int StackByTwoQueueSize(StackByTwoQueue* stq)
{
	assert(stq);
	return QueueSize(&stq->q1) + QueueSize(&stq->q2);
}
int StackByTwoQueueEmpty(StackByTwoQueue* stq)
{
	assert(stq);
	return QueueEmpty(&stq->q1) | QueueEmpty(&stq->q2);
}
void StackByTwoQueueDestroy(StackByTwoQueue* stq)
{
	assert(stq);
	DestroyQueue(&stq->q1);
	DestroyQueue(&stq->q2);
}
int StackByTwoQueueTop(StackByTwoQueue* stq)
{
	assert(stq);
	if (QueueEmpty(&stq->q1))
	{
		return QueueBack(&stq->q1);
	}
	else 
		return QueueBack(&stq->q2);
}
void TestStackByTwoQueue()
{
	StackByTwoQueue stq;
	StackByTwoQueueInit(&stq);

	StackByTwoQueuePush(&stq, 1);
	StackByTwoQueuePush(&stq, 2);
	StackByTwoQueuePush(&stq, 3);
	StackByTwoQueuePush(&stq, 4);
	StackByTwoQueuePush(&stq, 5);

	while (StackByTwoQueueEmpty(&stq))
	{
		printf("%d ", StackByTwoQueueTop(&stq));
		StackByTwoQueuePop(&stq);
	}
	printf("\n");
}