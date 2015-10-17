#ifndef _Queue_h
#define _Queue_h
#include <iostream>
using namespace std;
typedef int ElementType;

/*Queue implentation is a dynamically allocated arrray*/
struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	ElementType* Array;
	
};
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif  /* _Queue_h */
/* END */
