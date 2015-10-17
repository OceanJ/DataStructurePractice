#include "Queue.h"

void PrintQueue(Queue Q)
{
	if (IsEmpty(Q))
	{
		cout << "Queue is Empty!!!";
		return;
	}
	cout << "The queue:" << endl;
	cout << "Size: " << Q->Size << endl;
	cout << "Front >> ";
	int TmpIndex = Q->Front;
	for (int i = 0; i < Q->Size; i++)
	{
		cout << Q->Array[TmpIndex] << " >>";
		TmpIndex = ++TmpIndex % Q->Capacity;
	}
	cout << " Rear " << endl;
}

int main()
{
	Queue TestQueue = CreateQueue(10);
	cout << "Begin test of queue " << endl;
	for (int i = 0, n = 1; i < 10; i++, n *= 2)
	{
		cout << i + 1 << "> Enqueue : " << n<<endl;
		Enqueue(n, TestQueue);
	}
	PrintQueue(TestQueue);
	cout << "Is Full ? " << IsFull(TestQueue)<<endl;

	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << " >Dequeue :" << Front(TestQueue) << endl;
		Dequeue(TestQueue);
	}
	PrintQueue(TestQueue);
	cout << "Front and dequeue: " << FrontAndDequeue(TestQueue)<<endl;
	cout << "Now add more data to test the cicular array..." << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << "> Enqueue : " << i << endl;
		Enqueue(i, TestQueue);
	}
	PrintQueue(TestQueue);
	cout << "Now make the queue empty...";
	MakeEmpty(TestQueue);
	cout << "Is Empty ? "<<IsEmpty(TestQueue)<<endl;
	cout << "Now dipose the queue!" << endl;
	DisposeQueue(TestQueue);
	cout << "Test Succeed!" << endl << "Good bye!"<<endl;
	getchar();
}