#include <stdio.h>
#include <stdlib.h>
#define Increasement (20)
typedef int ElementType;

typedef struct SeqListModel{

	int Size; //��Ĵ�С
	int N;	//����ʵ��Ԫ�ظ���
	ElementType * List;
}*SeqList;
//ͨ��ָ����Ĵ�С����ʼ���ݣ����ݸ�������ʼ��˳���
SeqList InitSeqList(int size,ElementType* Data,int n);
//�ж�˳����Ƿ�Ϊ��
int IsEmpty(SeqList L);
//����num��λ��Position
void InsertNum(int Position, ElementType num,SeqList L);
//��������ɾ������
int  DeleteFromPosition(int P, SeqList L);
//����Num��һ�γ������������
int  LocateNum(ElementType num, SeqList L);
//������ֵ��ɾ������
int DeleteFromValue(int Value, SeqList L);
//�����������
void SortList(ElementType *List, int N);
//�ϲ�����������һ���±�
SeqList MergeList(SeqList L1, SeqList L2 );


