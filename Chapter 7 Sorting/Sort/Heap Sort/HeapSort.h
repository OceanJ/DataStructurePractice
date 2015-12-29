#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_

typedef  int ElementType;
//下滤函数 i:需要下滤的节点 N:下滤的结束位置
void PercDown(ElementType A[], int i, int N); 
//堆排序 A:需要排序的数组 N:数组大小
void HeapSort(ElementType A[], int N);
#endif
