#include <iostream>
#include <cmath>
using namespace std;
void  PrintArr(int ar[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
}
int GetDigit(int X, int d)
{
	int n = pow(10, d-1);
	return (int)X/n%10;
}
int GetMaxDigit(int A[], int N)
{
	int Max=A[0];
	for (int i = 1; i < N; i++)
	{
		if (A[i]>Max)
			Max = A[i];
	}
	int digit=0;
	while (Max)
	{	
		digit++;
		Max = Max / 10;
	}
	return digit;
}
/*
LSD��ʵ��

���λ���ȷ������������λ�ؼ���Kd�����ж������һ������

�����ݴε�λ�ؼ���Kd-1����һ������Ľ��������

�����ظ���ֱ�����ݹؼ���K1���һ��������ɣ��Ϳ��Եõ�һ����������С�

ʹ���������򷽷���ÿһ���ؼ����������ʱ������Ҫ�ٷ��飬�������������顣
*/
void LSDRadixSort(int A[], int N)
{
	int count[10];
	
	int *Collections = (int*)malloc((N + 1)*sizeof(int));
	int MaxDigit = GetMaxDigit(A, N);
	for (int d = 1; d <=MaxDigit; d++)
	{
		for (int i = 0; i < 10; i++)
		{
			count[i] = 0;
		}
		for (int i = 0; i < N; i++)
		{
			count[GetDigit(A[i],d)]++;
		}
		for (int i = 1; i < 10; i++)
		{
			count[i] = count[i] + count[i - 1];
		}

		//����������װ��Ͱ(ע��װ��ʱ��ķ��似��)
		for (int i = N-1; i >= 0; --i)        //����Ҫ��������ɨ�裬��֤�����ȶ���   
		{
			int j = GetDigit(A[i], d);        //����ؼ���ĵ�kλ�����֣� ���磺576�ĵ�3λ��5   
			Collections[count[j] - 1] = A[i]; //�����Ӧ��Ͱ�У�count[j]-1�ǵ�j��Ͱ���ұ߽����� 
			--count[j];               //��ӦͰ��װ������������һ  
		}

		//ע�⣺��ʱcount[i]Ϊ��i��Ͱ��߽�  

		//�Ӹ���Ͱ���ռ�����
		for (int i = 0,j = 0; i <= N; ++i, ++j)
		{
			A[i] = Collections[j];
		}
	}
	free(Collections);
}

/*
MSD��ʵ��

���λ���ȷ�ͨ����һ���ݹ�Ĺ��̣�

<1>�ȸ������λ�ؼ���K1���򣬵õ����ɶ����飬��������ÿ����������ͬ�ؼ���K1��

<2>�ٷֱ��ÿ���ж�����ݹؼ���K2�������򣬰�K2ֵ�Ĳ�ͬ���ٷֳ����ɸ���С�����飬ÿ�������еĶ��������ͬ��K1��K2ֵ��

<3>�����ظ���ֱ���Թؼ���Kd�������Ϊֹ��

<4> ��󣬰����������еĶ������������������͵õ�һ������Ķ������С�

*/
void MSDRadixSort(int arr[], int begin, int end, int d)
{
	const int radix = 10;
	int count[radix], i, j;
	//�ÿ�
	for (i = 0; i < radix; ++i)
	{
		count[i] = 0;
	}
	//����Ͱ�洢�ռ�
	int *bucket = (int *)malloc((end - begin + 1) * sizeof(int));
	//ͳ�Ƹ�Ͱ��Ҫװ��Ԫ�صĸ���  
	for (i = begin; i <= end; ++i)
	{
		count[GetDigit(arr[i], d)]++;
	}
	//���Ͱ�ı߽�������count[i]ֵΪ��i��Ͱ���ұ߽�����+1
	for (i = 1; i < radix; ++i)
	{
		count[i] = count[i] + count[i - 1];
	}
	//����Ҫ��������ɨ�裬��֤�����ȶ��� 
	for (i = end; i >= begin; --i)
	{
		j = GetDigit(arr[i], d);      //����ؼ���ĵ�dλ�����֣� ���磺576�ĵ�3λ��5   
		bucket[count[j] - 1] = arr[i];   //�����Ӧ��Ͱ�У�count[j]-1�ǵ�j��Ͱ���ұ߽�����   
		--count[j];                    //��j��Ͱ����һ��Ԫ�ص�λ��(�ұ߽�����+1)   
	}
	//ע�⣺��ʱcount[i]Ϊ��i��Ͱ��߽�    
	//�Ӹ���Ͱ���ռ�����  
	for (i = begin, j = 0; i <= end; ++i, ++j)
	{
		arr[i] = bucket[j];
	}
	//�ͷŴ洢�ռ�
	free(bucket);
	//�Ը�Ͱ�����ݽ���������
	for (i = 0; i < radix; i++)
	{
		int p1 = begin + count[i];         //��i��Ͱ����߽�   
		int p2 = begin + count[i + 1] - 1;     //��i��Ͱ���ұ߽�   
		if (p1 < p2 && d > 1)
		{
			MSDRadixSort(arr, p1, p2, d - 1);  //�Ե�i��Ͱ�ݹ���ã����л���������λ�� 1    
		}
	}
}


void  main()
{
	int  br[10] = { 20, 80, 90, 589, 998, 965, 852, 123, 456, 789 };
	cout << "ԭ�������£�" << endl;
	PrintArr(br, 10);
//	LSDRadixSort(br, 10);
	MSDRadixSort(br, 0, 9, 3);
	cout << "������������£�" << endl;
	PrintArr(br, 10);
	getchar();
}
/*
ԭ�������£�
20 80 90 589 998 965 852 123 456 789
������������£�
20 80 90 123 456 589 789 852 965 998

from:http://www.cnblogs.com/Braveliu/archive/2013/01/21/2870201.html
*/