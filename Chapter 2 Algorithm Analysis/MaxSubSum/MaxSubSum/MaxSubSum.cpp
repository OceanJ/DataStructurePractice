//����Ȼ�����ӶȴﵽO��N^2�����㷨
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

//��������
int Max3(int A, int B, int C)
{
	int MAX= (A > B ? A : B);
	MAX = MAX > C ? MAX : C;
	return MAX;
}

//���÷��η� ��������кͿ������������֡�Ҫô��벿��Ҫô�Ұ벿�����ߺ���м䡣��������ֿ������õݹ���� ��
//ǰ������������Էֱ����ǰ�벿�֣�����ǰ�벿�����һ��Ԫ�أ��������Լ���벿�֣�������벿�ֵ�һ��Ԫ�أ������ͣ�Ȼ������Ӷ��õ�
//������A:�������飬Left:��߽磬Right:�ұ߽�
int MaxSubSequenceSum2(const int A[], int Left, int Right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum=0, MaxRightBorderSum=0;
	int LeftBorderSum=0, RightBorderSum=0;
	int Center, i;
	//�����׼���� ��ֻ��һ��Ԫ��ʱ�����Ǹ���Ϊ���������
	if (Left == Right)
	{
		if (A[Left] > 0)
			return A[Left];
		else
			return 0;
	}
	Center = (Left + Right) / 2;
	//�ݹ��������������������
	MaxLeftSum = MaxSubSequenceSum2(A, Left, Center);
	MaxRightSum = MaxSubSequenceSum2(A, Center + 1, Right);
	//����ǰ�벿�ֵ����ͣ�����ǰ�벿�����һ��Ԫ�أ�
	for (i = Center; i >= Left; i--)
	{
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	//�����벿�ֵ����ͣ�������벿�ֵ�һ��Ԫ�أ�
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

//��ѷ��� O(N)
//�����ŵ㣺ֻ��Ҫ�����ݽ���һ��ɨ�裬���������м��䡣
//ͬʱ������ʱ�̣��㷨���ܶ����Ѷ������ݸ����������������ȷ�𰸣������㷨��
//�����㷨������Ҫ�����ռ䲢������ʱ�����е������㷨�������������㷨��
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
