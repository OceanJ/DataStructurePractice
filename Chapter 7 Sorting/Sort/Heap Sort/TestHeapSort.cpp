#include<iostream>
#include"HeapSort.h"

using namespace std;
void PrintArray(ElementType A[], int N)
{
	cout << "Array:{ ";
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << ",  ";
	}
	cout << "}" << endl;
}

int main()
{
	int A[] = { 32, 542, 23, 21, 43, 64, 879, 34, 654, 76, 69, 52, 24 };
	int Size = sizeof(A) / sizeof(int);
	cout << "Origin:" << endl;
	PrintArray(A, Size);
	cout << "After HeapSort:" << endl;
	HeapSort(A, Size);
	PrintArray(A,Size);
	getchar();
}