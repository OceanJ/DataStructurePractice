#include <stdio.h>
#include <stdlib.h>
#define Increasement (20)
typedef int ElementType;

typedef struct ArrayListNode{

	int Size; //��Ĵ�С
	int N;	//����ʵ��Ԫ�ظ���
	ElementType * Elements;
}*ArrayList;
//ͨ��ָ����Ĵ�С����ʼ��˳���
ArrayList CreateArrayList(int size);
//ͨ��ָ����Ĵ�С����ʼ���ݣ����ݸ�������ʼ��˳���
ArrayList CreateArrayList(int size,ElementType* DataArray,int n);
//�ж�˳����Ƿ�Ϊ�� 1:�� 0:�ǿ�
int IsEmpty(ArrayList L);
//����num��Elements[Index]
void InsertNum(int Index, ElementType num,ArrayList L);
//��������ɾ������
int  DeleteFromIndex(int P, ArrayList L);
//����Num��һ�γ������������
int  FindIndex(ElementType num, ArrayList L);
//������ֵ��ɾ������
int DeleteFromValue(int Value, ArrayList L);
//����Ĳ�������
void SortList(ElementType *Elements, int N);
//�ϲ�����������һ���±�
ArrayList MergeList(ArrayList L1, ArrayList L2 );
//˳���ӡ�����б�
void PrintList(ArrayList L);

void DistroyList(ArrayList L);



