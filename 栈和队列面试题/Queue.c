#include "Queue.h"


PNode BuyQNode(DataType data)
{
	PNode pNewNode = NULL;
	pNewNode = (PNode)malloc(sizeof(Node));
	if (NULL==pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}
void InitQueue(Queue* q)
{
	assert(q);
	q->_pHead = q->_pTail = NULL;
}
void QueuePush(Queue* q, DataType data)
{
	assert(q);
	if (NULL == q->_pHead)
	{
		q->_pHead = q->_pTail = BuyQNode(data);
	}
	else
	{
		q->_pTail->_pNext = BuyQNode(data);
		q->_pTail = q->_pTail->_pNext;
	}
}
void QueuePop(Queue* q)
{
	PNode pNext = NULL;
	assert(q);
	pNext = q->_pHead->_pNext;
	free(q->_pHead);
	q->_pHead = pNext;
	if (NULL==pNext)
	{
		q->_pTail = NULL;
	}
}
DataType QueueFront(Queue* q)
{
	assert(q);
	return q->_pHead->_data;
}
DataType QueueBack(Queue* q)
{
	assert(q);
	return q->_pTail->_data;
}
int QueueSize(Queue* q)
{
	PNode pCur = NULL;
	assert(q);
	pCur = q->_pHead;
	int count = 0;
	while (pCur)
	{
		++count;
		pCur = pCur->_pNext;
	}
	return count;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->_pHead;
}
void DestroyQueue(Queue* q)
{
	PNode pNewHaed = NULL;
	pNewHaed = q->_pHead;
	if (q->_pHead)
	{
		pNewHaed = q->_pHead->_pNext;
		free(q->_pHead);
		q->_pHead = pNewHaed;
	}
}