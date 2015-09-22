#include <iostream>
using namespace std;
/*
��̬�滮��Max[i]��ʾ��A[i]��β����������л���Min[i]��ʾ��A[i]��β����������л�
Max[i]=Max3(A[i],Max[i-1]*A[i],Min[i-1]*A[i]);
Min[i]=Min3(A[i],Max[i-1]*A[i],Min[i-1]*A[i]);
*/
double Max3(double A, double B, double C)
{
	double Max = A > B ? A : B;
	return Max > C ? Max : C;
}
double Min3(double A, double B, double C)
{
	double Min = A < B ? A : B;
	return Min < C ? Min : C;
}
double MaxSubMulti(const double A[], const int N)
{
	double Result = 0;
	double *Max=new double [N+1]();
	double *Min=new double [N+1]();
	Max[0] = Min[0] = A[0];
	for (int i = 1; i < N; i++)
	{
		Max[i] = Max3(A[i], Max[i - 1] * A[i], Min[i - 1] * A[i]);
		Min[i] = Min3(A[i], Max[i - 1] * A[i], Min[i - 1] * A[i]);
		if (Max[i]>Result)
			Result = Max[i];
	}
	delete Max;
	delete Min;
	if (Result < 0)
		return -1;
	else
		return Result;
}

int main()
{
	double A[] = {-3.2,5,-1.6,1,2.5 };
	cout << MaxSubMulti(A, 5);
	getchar();
}