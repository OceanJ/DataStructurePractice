#include"ShellSort.h"

int main()
{
	ElementType A[] = { 44, 22, 11, 33, 77, 66, 88, 99, 55, 0 };
	int N = sizeof(A) / sizeof(ElementType);
	PrintArray(A, N);
	cout << "Origin State:" << endl;
	PrintArray(A, N);
	cout << "After shell sort" << endl;
	ShellSort(A, N);
	PrintArray(A, N);
	getchar();
}