/*
Major Element of a array
 Definition :if the element appear more than N/2 times in an Array that has N element. 
 Solution:大体思路首先是找到主要元素的候选元，再确定候选元是不是主要元素
  1.构造数组B，比较A[i]和A[i+1]是否相等（i=0,3，...,[N/2])，如果相等则加入B
  2.递归的寻找B中的候选元；它也是A的候选元。
  3.当数组中只有一个元素时即返回结果，如果没有元素则证明不存在。
	
  元素个数奇偶问题：
  如果前N-1个元素中已经有一个主要元素了，加入最后一个元素改变不了这个结果，因此直接返回结果。
  否则加入最后一个元素作为候选元，再重新递归计算。
  One way to do this is to note that if the first NO−1 elements have a majority, then the last
  element cannot change this. Otherwise, the last element could be a majority. Thus if N is
  odd, ignore the last element. Run the algorithm as before. If no majority element emerges,
  then return the last element as a candidate.
  (From the textbook) 

  TODO: avoid using another array B
*/

#include <iostream>
using namespace std;

int MajorElem(int A[],int N)
{
	if (N ==0)
		return NULL;
	else if (N ==1)
		return A[0];
	int *B = new int[N / 2 + 1];
	int size = 0;
	for (int i = 0; i < N-1; i+=2) //暂时忽略最后一个元素
	{
		if (A[i] == A[i + 1])
		{
			B[size++] = A[i];
		}
	}
	int result = MajorElem(B, size); 
	if (result != NULL)		//如果有结果，则返回
		return result;
	else                    //否则加上最后一个元素再计算
	{
		B[size++] = A[N - 1];
		return MajorElem(B, size);
	}
}

int main()
{
	int A[10] = { 1,2,3,4,4,1,1,1,1};
	cout << MajorElem(A,9);
	getchar();
}