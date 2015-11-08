#include "MergeSort.h"
void PrintArray(ElementType A[], int N)
{
	cout << "Array: {";
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << "  ";
	}
	cout << "}" << endl;
}
//Merge left and right sorted parts
void Merge(ElementType A[], ElementType TmpArray[], int Left, int Center,int Right)
{
	int IndexL = Left;    //Begin of left part
	int IndexR = Center;  //Begin of right part
	int IndexT = Left;    //Begin of temp array
	while(IndexL<=Center-1&&IndexR<=Right)
	{
		if (A[IndexL] <= A[IndexR])
			TmpArray[IndexT++] = A[IndexL++];
		else 
			TmpArray[IndexT++] = A[IndexR++];
	}
	//Deal the remained datas
	while (IndexL <= Center-1)
		TmpArray[IndexT++] = A[IndexL++];
	while (IndexR <= Right)
		TmpArray[IndexT++] = A[IndexR++];
	//Copy the temp array datas back to A
	for (int i = Right; i >= Left; i--)
		A[i] = TmpArray[i];
}
void Sort(ElementType A[], ElementType TmpArray[], int Left, int Right)
{
	int Center;
	if (Left < Right)
	{
		Center = (Right + Left) / 2;
		//Divide into two parts
		Sort(A, TmpArray, Left, Center);
		Sort(A, TmpArray, Center+1,Right);
		//Then Merge two parts
		Merge(A, TmpArray, Left, Center+1, Right);
	}
}

//To drive sort process
void MergeSort(ElementType A[], int N)
{
	//Temp array is used for merging process
	ElementType* TmpArray = new ElementType[N];
	if (!TmpArray)
	{
		cerr << "Out of Space!!!" << endl;
		exit(-1);
	}
	//Right index must -1 
	Sort(A, TmpArray, 0, N-1);
	free(TmpArray);
}