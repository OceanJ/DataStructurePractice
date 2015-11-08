#include <iostream>
using namespace std;

typedef int ElementType;

void PrintArray(ElementType A[], int N);
//Divide and conquer
void Merge(ElementType A[], ElementType TmpArray[], int Left, int Center, int Right);
void Sort(ElementType A[], ElementType TmpArray[], int Left, int Right);
void MergeSort(ElementType A[], int N);
