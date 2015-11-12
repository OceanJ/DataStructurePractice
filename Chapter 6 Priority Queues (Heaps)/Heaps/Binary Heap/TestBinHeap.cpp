#include "BinHeap.h"
void PrintArray(ElementType A[], int N)
{
	cout << "Array: {";
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << "  ";
	}
	cout << "}" << endl;
}

void PrintHeap(PriorityQueue H)
{
	if (H)
	{
		PrintArray(H->Elements, H->Size);
	}
}
int main()
{

}