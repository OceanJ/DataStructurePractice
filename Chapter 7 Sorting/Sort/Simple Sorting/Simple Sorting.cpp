typedef  int ElementType;

ElementType * InsertionSort(ElementType  A[],int N)
{
	for (int i = 1; i < N; i++)
	{
		ElementType Tmp = A[i];
		for (int j = i; j>0 && A[j - 1] > Tmp; j--)
			A[j] = A[j - 1];
		A[j] = Tmp;
	}
}