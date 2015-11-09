#include "QuickSort.h"
void InsertionSort(ElementType  A[], int Left,int Right)
{
	for (int i = Left+1; i < Right+1; i++)
	{
		ElementType Tmp = A[i];
		int j;
		for (j = i; j>Left && A[j - 1] > Tmp; j--)
			A[j] = A[j - 1];
		A[j] = Tmp;
	}
}

void Swap(ElementType* A, ElementType *B)
{
	ElementType Tmp = *A;
	*A = *B;
	*B = Tmp;
}
//Pivot is the mid-value of A[Left]¡¢A[Center] and A[Right] 
ElementType CreatePivot(ElementType A[], int Left, int Right)
{
	int Center=(Left+Right)/2;
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Center]);
	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Right]);
	if (A[Center] > A[Left])
		Swap(&A[Center], &A[Right]);
	//The Result is A[Right]>A[Center]>A[Left]

	Swap(&A[Center], &A[Right-1]);
	//Then move the Pivot to right side 
	return A[Right - 1];
}
void QSort(ElementType A[], int Left, int Right)
{
	if (Right - Left < 3)
	{
		int i = Left, j = Right - 1;
		ElementType Pivot = CreatePivot(A, Left, Right);
		while (1)
		{
			while (A[++i] < Pivot); //Stop when A[i]>=Pivot
			while (A[++j] > Pivot); //Stop when A[j]<=Pivot
			if (i < j)
				Swap(&A[i], &A[j]); //Do Swap 
			else
				break;
		}
		Swap(&A[i], &A[Right - 1]);  //Move the pivot to A[i]
		QSort(A, Left, i - 1);  //Deal the Left half part
		QSort(A, i + 1, Right); //Deal the Right half part
	}
	//Deal the small subarray
	else
		//InsertSort is  faster in small array
		InsertionSort(A, Left, Right);
}

//Drive the recursion process
void QuickSort(ElementType A[], int N)
{
	QSort(A, 0, N - 1);
}
