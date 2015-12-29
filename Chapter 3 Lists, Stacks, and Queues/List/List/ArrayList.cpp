#include "ArrayList.h"

ArrayList CreateArrayList(int size)
{
	return CreateArrayList(size, NULL, 0);
}
ArrayList CreateArrayList(int size, ElementType* DataArray, int n)
{
	ArrayList L = (ArrayList)malloc(sizeof(struct ArrayListNode));
	if (!L)
	{
		printf("Out Of Space!");
		exit(0);
	}
	L->Elements = (ElementType *)malloc(sizeof(ElementType)*size);
	if (!L->Elements)
	{
		printf("Out Of Space!");
		free(L);
		exit(0);
	}
	//初始化数据
	for (int i = 0; i < n; i++)
		L->Elements[i] = DataArray[i];
	L->Size = size;
	L->N = n;
	return L;
}

int IsEmpty(ArrayList L)
{
	return (L->N == 0);
}

void InsertNum(int Index, ElementType num, ArrayList L)
{
	//检查索引是否合法
	if (Index > L->N || Index < 0)
	{
		printf("Error!This Index is illegal");
		exit(-1);
	}
	if (L->N + 1 > L->Size)
	{
		//重新分配内存空间扩大表容量
		ElementType* newList = (ElementType *)
			realloc(L->Elements, L->Size + sizeof(ElementType)*Increasement);
		if (!newList)
		{
			printf("Out Of Space!");
			exit(0);
		}
		L->Elements = newList;
		L->Size += Increasement;
	}
	//将数组下标i之后的元素后移一位
	for (int i = L->N; i > Index; i--)
		L->Elements[i] = L->Elements[i - 1];
	L->Elements[Index] = num;
	L->N++;
}


int  DeleteFromIndex(int P, ArrayList L)
{
	//检查索引是否合法
	if (P<0 || P>L->Size)
	{
		printf("Error!This Index is illegal");
		return 0;
	}
	int p;
	//数组下标p之后的元素前移一位
	for (p = P; p < L->N; p++)
		L->Elements[p] = L->Elements[p + 1];
	L->N--;
	//删除成功，返回1
	return 1;
}


int FindIndex(ElementType num, ArrayList L)
{
	int p;
	for (p = 0; p < L->Size; p++)
	{
		//仅返回第一次出现的位置
		if (L->Elements[p] == num)
			return p;
	}
	return -1;
}

//通过FindIndex找到索引，再利用DeleteFromPosion删除元素。
int DeleteFromValue(int Value, ArrayList L)
{
	int p = FindIndex(Value, L);
	if (p < 0)
	{
		printf("Error!The Value is not in the list");
		return 0;
	}
	return DeleteFromIndex(p, L);
}

//为顺序表排序(插入排序)，方便合并
void SortList(ElementType *Elements, int N)
{
	int i, j;
	ElementType temp;
	for (i = 1; i < N; i++)
	{
		temp = Elements[i];
		for (j = i; j > 0 && Elements[j - 1] > temp; j--)
			Elements[j] = Elements[j - 1];
		Elements[j] = temp;
	}
}
//先排序 再合并，相同项只保留一个。
ArrayList MergeList(ArrayList L1, ArrayList L2)
{
	SortList(L1->Elements, L1->N);
	SortList(L2->Elements, L2->N);
	ArrayList L3 = CreateArrayList(L1->Size + L2->Size);
	int i, j, k;
	for (i = 0, j = 0, k = 0; i < L1->N&&i < L2->N; k++)
	{
		if (L1->Elements[i] < L2->Elements[j])
			L3->Elements[k] = L1->Elements[i++];
		else if (L1->Elements[i]>L2->Elements[j])
			L3->Elements[k] = L2->Elements[j++];
		else
		{//去重
			L3->Elements[k] = L1->Elements[i];
			i++; j++;
		}
	}
	//处理剩余元素
	while (i < L1->N)
		L3->Elements[k++] = L1->Elements[i++];
	while (j < L2->N)
		L3->Elements[k++] = L2->Elements[j++];
	L3->N = k;
	return L3;
}
void DistroyList(ArrayList L)
{
	if (!L)
	{
		printf("The list is illegal\n");
		return;
	}
	free(L->Elements);
	free(L);
}

void PrintList(ArrayList L)
{
	printf("N: %d Size: %d Elements[] :", L->N, L->Size);
	for (int i = 0; i < L->N; i++)
	{
		printf("%d ", L->Elements[i]);
	}
	printf("\n");
}
