#include <stdio.h>
#include <stdlib.h>
#define Increasement (20)
typedef int ElementType;

typedef struct ArrayListNode{

	int Size; //表的大小
	int N;	//表中实际元素个数
	ElementType * Elements;
}*ArrayList;
//通过指定表的大小来初始化顺序表。
ArrayList CreateArrayList(int size);
//通过指定表的大小，初始数据，数据个数来初始化顺序表。
ArrayList CreateArrayList(int size,ElementType* DataArray,int n);
//判断顺序表是否为空 1:空 0:非空
int IsEmpty(ArrayList L);
//插入num到Elements[Index]
void InsertNum(int Index, ElementType num,ArrayList L);
//根据索引删除数据
int  DeleteFromIndex(int P, ArrayList L);
//返回Num第一次出现数组的索引
int  FindIndex(ElementType num, ArrayList L);
//根据数值来删除数据
int DeleteFromValue(int Value, ArrayList L);
//数组的插入排序
void SortList(ElementType *Elements, int N);
//合并两个表，返回一个新表。
ArrayList MergeList(ArrayList L1, ArrayList L2 );
//顺序打印数组列表
void PrintList(ArrayList L);

void DistroyList(ArrayList L);



