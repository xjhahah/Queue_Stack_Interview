#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

#define DataType int

typedef struct Node
{
	struct Node* _pNext;
	DataType _data;
}Node,*PNode;

typedef struct Queue
{
	PNode _pHead;
	PNode _pTail;
}Queue;
void InitQueue(Queue* q);
void QueuePush(Queue* q, DataType data);
void QueuePop(Queue* q);
DataType QueueFront(Queue* q);
DataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void DestroyQueue(Queue* q);