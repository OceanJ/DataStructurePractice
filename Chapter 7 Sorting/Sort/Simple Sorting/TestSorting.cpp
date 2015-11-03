#include<iostream>
#include"SimpleSorting.h"
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
	ElementType X[] = { 54, 22, 45, 64, 33, 72, 13, 94, 1 ,88};
	int N = sizeof(X) / sizeof(ElementType);
	cout << "Origin:" << endl;
	PrintArray(X, N);
	cout << "Insertion Sort:" << endl;
	InsertionSort(X, N);
	//cout << "Bubble Sort:" << endl;
	//BubbleSort(X, N);
	//cout << "Selection Sort:" << endl;
	//SelectionSort(X, N);

	PrintArray(X, N);
	getchar();
}