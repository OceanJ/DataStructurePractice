#include "Queue.h"

Queue CreateQueue(int MaxElements)
{
	Queue Q = new QueueRecord;
	if (!Q)
	{
		cout << "Out of Space!!!";
		return NULL;
	}
	Q->Array = new ElementType[MaxElements];
	if (!Q->Array)
	{
		cout << "Out of Space!!!";
		return NULL;
	}
	Q->Capacity = MaxElements;
	MakeEmpty(Q);
}
void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}
int IsEmpty(Queue Q)
{
	if (!Q)
		return 1;
	else
		return Q->Size==0;
}
int IsFull(Queue Q)
{
	return Q->Size >= Q->Capacity;
}

void DisposeQueue(Queue Q)
{
	if (Q)
	{
		free(Q->Array);
		free(Q);
	}
}

void Enqueue(ElementType X, Queue Q)
{
	if (IsFull(Q))
	{
		cout << "Queue is full!!!" << endl;
		return;
	}
	/*Use cicular array :if rear gets to the end ,let it become start TmpIndex*/
	Q->Rear = ++Q->Rear % Q->Capacity;
	Q->Array[Q->Rear] = X;
	Q->Size++;
}

void Dequeue(Queue Q)
{
	if (IsEmpty(Q))
	{
		cout << "Queue is empty!!!" << endl;
		return;
	}
	Q->Front = ++Q->Front % Q->Capacity;
	Q->Size--;
}

ElementType Front(Queue Q)
{
	if (IsEmpty(Q))
	{
		cout << "Queue is empty!!!" << endl;
		return 0;
	}
	return Q->Array[Q->Front];
}

ElementType FrontAndDequeue(Queue Q)
{
	if (IsEmpty(Q))
	{
		cout << "Queue is empty!!!" << endl;
		return 0;
	}
	int TmpElement = Q->Array[Q->Front];
	int TmpIndex = ++Q->Front % Q->Capacity;
	Q->Size--;
	return TmpElement;
}