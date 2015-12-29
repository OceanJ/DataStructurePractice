#include "HeapSort.h"
//������򽻻�������
void Swap(ElementType * ptA, ElementType * ptB)
{
	*ptA = *ptA^*ptB;
	*ptB = *ptA^*ptB;
	*ptA = *ptA^*ptB;
}
//�õ��ڵ�i����ڵ�
int LeftChild(int i)
{
	return i * 2 + 1;
}
void PercDown(ElementType A[], int i, int N)
{
	int Child;
	ElementType tmp; //��ʱ�������˽ڵ��ֵ
	for (tmp = A[i];LeftChild(i)<N; i = Child)
	{
		Child = LeftChild(i);
		//�ҵ��ϴ�ĺ���
		if (Child != N - 1 && A[Child + 1] > A[Child])
			Child++;
		//������Ӹ����򽫺�������
		if (tmp < A[Child])
			A[i] = A[Child];
	}
	//����iΪ��Ҫ���˽ڵ���յ�λ��
	A[i] = tmp;
}
void HeapSort(ElementType A[], int N)
{
	//1.�����������ѣ���Ϊ���ֵ��
	//�ӵ����ڶ������һ���ڵ㼴A[N/2]��ʼ�������� 
	for (int i = N / 2; i>=0; i--)
	{
		PercDown(A, i, N);
	}
	//2.����N-1��DeleteMAX()
	//����һ���ڵ�����һ���ڵ���н������ٶԵ�һ���ڵ��������
	//���ս���õ�һ���������е�����
	for (int i = N-1;i > 0 ; i--)
	{
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}