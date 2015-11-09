#include "QuickSort.h"
void PrintArray(ElementType A[], int N)
{
	cout << "Array: {";
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << "  ";
	}
	cout << "}" << endl;
}
int main()
{
	ElementType A[] = { 21, 65, 32, 87, 12, 54, 87, 98, 25, 77, 73, 46, 78, 25, 72, 38, 48, 57, 32, 41, 62, 83, 56 };
	int N = sizeof(A) / sizeof(ElementType);
	cout << "Origin:" << endl;
	PrintArray(A, N);
	cout << "Quick Sort: " << endl;
	QuickSort(A, N);
	PrintArray(A, N);
	getchar();
}