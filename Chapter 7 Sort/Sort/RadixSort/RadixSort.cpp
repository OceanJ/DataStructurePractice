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
LSD法实现

最低位优先法首先依据最低位关键码Kd对所有对象进行一趟排序，

再依据次低位关键码Kd-1对上一趟排序的结果再排序，

依次重复，直到依据关键码K1最后一趟排序完成，就可以得到一个有序的序列。

使用这种排序方法对每一个关键码进行排序时，不需要再分组，而是整个对象组。
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

		//把数据依次装入桶(注意装入时候的分配技巧)
		for (int i = N-1; i >= 0; --i)        //这里要从右向左扫描，保证排序稳定性   
		{
			int j = GetDigit(A[i], d);        //求出关键码的第k位的数字， 例如：576的第3位是5   
			Collections[count[j] - 1] = A[i]; //放入对应的桶中，count[j]-1是第j个桶的右边界索引 
			--count[j];               //对应桶的装入数据索引减一  
		}

		//注意：此时count[i]为第i个桶左边界  

		//从各个桶中收集数据
		for (int i = 0,j = 0; i <= N; ++i, ++j)
		{
			A[i] = Collections[j];
		}
	}
	free(Collections);
}

/*
MSD法实现

最高位优先法通常是一个递归的过程：

<1>先根据最高位关键码K1排序，得到若干对象组，对象组中每个对象都有相同关键码K1。

<2>再分别对每组中对象根据关键码K2进行排序，按K2值的不同，再分成若干个更小的子组，每个子组中的对象具有相同的K1和K2值。

<3>依此重复，直到对关键码Kd完成排序为止。

<4> 最后，把所有子组中的对象依次连接起来，就得到一个有序的对象序列。

*/
void MSDRadixSort(int arr[], int begin, int end, int d)
{
	const int radix = 10;
	int count[radix], i, j;
	//置空
	for (i = 0; i < radix; ++i)
	{
		count[i] = 0;
	}
	//分配桶存储空间
	int *bucket = (int *)malloc((end - begin + 1) * sizeof(int));
	//统计各桶需要装的元素的个数  
	for (i = begin; i <= end; ++i)
	{
		count[GetDigit(arr[i], d)]++;
	}
	//求出桶的边界索引，count[i]值为第i个桶的右边界索引+1
	for (i = 1; i < radix; ++i)
	{
		count[i] = count[i] + count[i - 1];
	}
	//这里要从右向左扫描，保证排序稳定性 
	for (i = end; i >= begin; --i)
	{
		j = GetDigit(arr[i], d);      //求出关键码的第d位的数字， 例如：576的第3位是5   
		bucket[count[j] - 1] = arr[i];   //放入对应的桶中，count[j]-1是第j个桶的右边界索引   
		--count[j];                    //第j个桶放下一个元素的位置(右边界索引+1)   
	}
	//注意：此时count[i]为第i个桶左边界    
	//从各个桶中收集数据  
	for (i = begin, j = 0; i <= end; ++i, ++j)
	{
		arr[i] = bucket[j];
	}
	//释放存储空间
	free(bucket);
	//对各桶中数据进行再排序
	for (i = 0; i < radix; i++)
	{
		int p1 = begin + count[i];         //第i个桶的左边界   
		int p2 = begin + count[i + 1] - 1;     //第i个桶的右边界   
		if (p1 < p2 && d > 1)
		{
			MSDRadixSort(arr, p1, p2, d - 1);  //对第i个桶递归调用，进行基数排序，数位降 1    
		}
	}
}


void  main()
{
	int  br[10] = { 20, 80, 90, 589, 998, 965, 852, 123, 456, 789 };
	cout << "原数据如下：" << endl;
	PrintArr(br, 10);
//	LSDRadixSort(br, 10);
	MSDRadixSort(br, 0, 9, 3);
	cout << "排序后数据如下：" << endl;
	PrintArr(br, 10);
	getchar();
}
/*
原数据如下：
20 80 90 589 998 965 852 123 456 789
排序后数据如下：
20 80 90 123 456 589 789 852 965 998

from:http://www.cnblogs.com/Braveliu/archive/2013/01/21/2870201.html
*/