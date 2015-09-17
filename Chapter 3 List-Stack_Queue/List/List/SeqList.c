#include "SeqList.h"


SeqList InitSeqList(int size, ElementType* Data, int n)
{
	SeqList L = (SeqList)malloc(sizeof(struct SeqListModel));
	if (!L)
	{
		printf("Out Of Space!");
		exit(0);
	}
	L->List = (ElementType *)malloc(sizeof(ElementType)*size);
	if (!L->List)
	{
		printf("Out Of Space!");
		free(L);
		exit(0);
	}
	//初始化数据
	for (int i = 0; i < n; i++)
		L->List[i] = Data[i];
	L->Size = size;
	L->N = n;
	return L;
}

int IsEmpty(SeqList L)
{
	return (L->N == 0);
}

void InsertNum(int Position, ElementType num, SeqList L)
{
	if (Position > L->N || Position < 0)
	{
		printf("Error!This Position is illegal");
		exit(0);
	}
	if (Position >L->Size)
	{
		//扩大表容量
		ElementType* new = (ElementType *)
			realloc(L->List, L->Size + sizeof(ElementType)*Increasement);
		if (!new)
		{
			printf("Out Of Space!");
			exit(0);
		}
		L->List = new;
		L->Size += Increasement;
	}
	for (int i = L->N; i >= Position; i--)
		L->List[i] = L->List[i - 1];
	L->List[Position - 1] = num;
	L->N++;
}


int  DeleteFromPosition(int P, SeqList L)
{
	//检查索引是否合法
	if (P<0 ||P>L->Size)
	{
		printf("Error!This Position is illegal");
		return 0;
	}
	int p;
	for (p = P; p < L->N; p++)
		L->List[p] = L->List[p + 1];
	L->N--;
	return 1;
}


int LocateNum(ElementType num, SeqList L)
{
	int p;
	for (p = 0; p < L->Size; p++)
	{
		//仅返回第一次出现的位置
		if (L->List[p] == num)
			return p;
	}
	return -1;
}

//通过LocateNum找到索引，再利用DeleteFromPosion删除元素。
int DeleteFromValue(int Value, SeqList L)
{
	int p = LocateNum(Value, L);
	if (p<0)
	{
		printf("Error!The Value is not in the list");
		return 0;
	}
	return DeleteFromPosition(p, L);
}

//为顺序表排序，方便合并
void SortList(ElementType *List, int N)
{
	int i, j;
	ElementType temp;
	for (i = 1; i < N; i++)
	{
		temp = List[i];
		for (j = i; j > 0 && List[j - 1] > temp; j--)
			List[j] = List[j - 1];
		List[j] = temp;
	}
}
//先排序 再合并，相同项只保留一个。
SeqList MergeList(SeqList L1, SeqList L2)
{
	SortList(L1->List, L1->N);
	SortList(L2->List, L2->N);
	SeqList L3 = InitSeqList(L1->Size + L2->Size, NULL, 0);
	int i, j, k;
	for (i = 0, j = 0, k = 0; i < L1->N&&i < L2->N; k++)
	{
		if (L1->List[i] < L2->List[j])
			L3->List[k] = L1->List[i++];
		else if (L1->List[i]>L2->List[j])
			L3->List[k] = L2->List[j++];
		else
		{
			L3->List[k] = L1->List[i];
			i++; j++;
		}
	}
	while (i < L1->N)
		L3->List[k++] = L1->List[i++];
	while (j < L2->N)
		L3->List[k++] = L2->List[j++];
	L3->N = k;
	return L3;
}

int main()
{
	//Test List
	int data1[] = { 123, 53, 64, 23, 67, 2, 4, 67, 87, 11 };
	int data2[] = { 23, 345, 78, 79, 3, 667, 98, 22, 42, 13 };
	SeqList L1= InitSeqList(20, data1, 10);
	SeqList L2 = InitSeqList(20, data2, 10);
//	printf("%d",LocateNum(123, L1));
//	DeleteFromValue(123, L1);
//	InsertNum(1, 11, L1);
//	printf("[0] = %d,[1]=%d", L1->List[0], L1->List[1]);
	SeqList L3 = MergeList(L1, L2);
	for (int i = 0; i < L3->N; i++)
	{
		printf("%d ", L3->List[i]);
	}
	getchar();

}