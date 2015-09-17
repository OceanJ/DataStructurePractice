#include <stdio.h>
#include <stdlib.h>
#define Increasement (20)
typedef int ElementType;

typedef struct SeqListModel{

	int Size; //表的大小
	int N;	//表中实际元素个数
	ElementType * List;
}*SeqList;
//通过指定表的大小，初始数据，数据个数来初始化顺序表。
SeqList InitSeqList(int size,ElementType* Data,int n);
//判断顺序表是否为空
int IsEmpty(SeqList L);
//插入num到位置Position
void InsertNum(int Position, ElementType num,SeqList L);
//根据索引删除数据
int  DeleteFromPosition(int P, SeqList L);
//返回Num第一次出现数组的索引
int  LocateNum(ElementType num, SeqList L);
//根据数值来删除数据
int DeleteFromValue(int Value, SeqList L);
//数组插入排序
void SortList(ElementType *List, int N);
//合并两个表，返回一个新表。
SeqList MergeList(SeqList L1, SeqList L2 );


