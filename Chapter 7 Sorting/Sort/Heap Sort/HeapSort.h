#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_

typedef  int ElementType;
//���˺��� i:��Ҫ���˵Ľڵ� N:���˵Ľ���λ��
void PercDown(ElementType A[], int i, int N); 
//������ A:��Ҫ��������� N:�����С
void HeapSort(ElementType A[], int N);
#endif
