#include "HeapSort.h"
//利用异或交换两个数
void Swap(ElementType * ptA, ElementType * ptB)
{
	*ptA = *ptA^*ptB;
	*ptB = *ptA^*ptB;
	*ptA = *ptA^*ptB;
}
//得到节点i的左节点
int LeftChild(int i)
{
	return i * 2 + 1;
}
void PercDown(ElementType A[], int i, int N)
{
	int Child;
	ElementType tmp; //临时保存下滤节点的值
	for (tmp = A[i];LeftChild(i)<N; i = Child)
	{
		Child = LeftChild(i);
		//找到较大的孩子
		if (Child != N - 1 && A[Child + 1] > A[Child])
			Child++;
		//如果孩子更大，则将孩子上滤
		if (tmp < A[Child])
			A[i] = A[Child];
	}
	//最终i为需要下滤节点的终点位置
	A[i] = tmp;
}
void HeapSort(ElementType A[], int N)
{
	//1.建立二叉最大堆（根为最大值）
	//从倒数第二层最后一个节点即A[N/2]开始进行下滤 
	for (int i = N / 2; i>=0; i--)
	{
		PercDown(A, i, N);
	}
	//2.调用N-1次DeleteMAX()
	//将第一个节点和最后一个节点进行交换，再对第一个节点进行下滤
	//最终将会得到一个升序排列的数组
	for (int i = N-1;i > 0 ; i--)
	{
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}