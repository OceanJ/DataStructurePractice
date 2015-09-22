//最自然但复杂度达到O（N^2）的算法
int MaxSubSequenceSum1(const int A[], int N)
{
	int ThisSum, MaxSum, i, j;
	MaxSum = 0;
	for (i = 0; i < N; i++)
	{
		ThisSum = 0;
		for (j = i; i < N; j++)
		{
			ThisSum += A[j];
			if (ThisSum>MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

//辅助函数
int Max3(int A, int B, int C)
{
	int MAX= (A > B ? A : B);
	MAX = MAX > C ? MAX : C;
	return MAX;
}

//利用分治法 最大子序列和可能在三处出现。要么左半部，要么右半部，或者横跨中间。两种情况又可以利用递归求解 。
//前第三种情况可以分别计算前半部分（包括前半部分最后一个元素）的最大和以及后半部分（包括后半部分第一个元素）的最大和，然后再相加而得到
//参数：A:输入数组，Left:左边界，Right:右边界
int MaxSubSequenceSum2(const int A[], int Left, int Right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum=0, MaxRightBorderSum=0;
	int LeftBorderSum=0, RightBorderSum=0;
	int Center, i;
	//处理基准情形 当只有一个元素时，若非负则为最大子序列
	if (Left == Right)
	{
		if (A[Left] > 0)
			return A[Left];
		else
			return 0;
	}
	Center = (Left + Right) / 2;
	//递归计算左右两边序列最大和
	MaxLeftSum = MaxSubSequenceSum2(A, Left, Center);
	MaxRightSum = MaxSubSequenceSum2(A, Center + 1, Right);
	//计算前半部分的最大和（包括前半部分最后一个元素）
	for (i = Center; i >= Left; i--)
	{
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	//计算后半部分的最大和（包括后半部分第一个元素）
	for (i = Center+1; i <= Right; i++)
	{
		RightBorderSum+= A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);

}

int MaxSubSequenceSum2_Drive(const int A[], int N)
{
	return MaxSubSequenceSum2(A, 0, N - 1);
}

//最佳方法 O(N)
//附带优点：只需要对数据进行一次扫描，无需对其进行记忆。
//同时在任意时刻，算法都能对它已读入数据给出子序列问题的正确答案（联机算法）
//完美算法：仅需要常量空间并以线性时间运行的联机算法几乎是完美的算法。
int MaxSubSequenceSum3(const int A[], int N)
{
	int ThisSum=0, MaxSum=0, i;
	for (i = 0; i < N; i++)
	{
		ThisSum += A[i];
		if (ThisSum>MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum; 
}
