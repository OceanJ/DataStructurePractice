/*������˹����ɸ������ư���ɸ����ɸ����һ�ֹ�Ԫǰ250���ɹ�ϣ����ѧ�Ұ�����˹�����������һ�ּ򵥼춨�������㷨��
����Ҫɸ��ֵ�ķ�ΧN���ҳ�\sqrt{N}���ڵ�����p_{1},p_{2},\dots,p_{k}��
����2ȥɸ������2���£���2�ı����޳�����������һ��������Ҳ����3ɸ����3���£���3�ı����޳�����
����ȥ����һ������5ɸ����5���£���5�ı����޳����������ظ���ȥ......��
�㷨���Ӷ�ΪO(NloglogN) 
from:http://blog.csdn.net/avan_lau/article/details/7257566 */

#include <iostream>
#include <ctime>
using namespace std;

const int MAX = 1e+8;  //�޶����Χ
int Primes[MAX];		 //�洢������
bool isPrime[MAX];	 //����ɸѡ



int Eratosthenes(int N)
{
	int size = 0;
	for (int i = 0; i < N; i++) isPrime[i] = true; //���ó�ʼ״̬
	for (int i = 2; i * i< N; i++) 
	{ 
		if (isPrime[i])  
			for (int j = i + i; j < N; j += i) //ɸ�������ı���
				isPrime[j] = false;
	}
	for (int i = 2; i < N; i++)	//����ɸѡ��� 
	{
		if (isPrime[i])
			Primes[size++] = i;
	}
	//cout << "Size:" << size<<endl;
	//for (int i = 0; i < size; i++) 
	//{
	//	cout << Primes[i] <<endl;
	//}
	return size;
}

/*
����һ���������������Ϊ��������ô�������������ֽ���ʽ��Ψһ�ġ�
�ֶ��壺����ĳ����Χ�ڵ����������ֻ��������С�������ӽ���ӱ���ɾ�������Ǻ����׵ó����㷨��ʱ�临�Ӷ�Ϊ���Եģ�
Ϊʲô�أ���Ϊһ���������������ֽ�ʽ��Ψһ�ģ��������Ƕ����˺���ֻ������С�����ӽ���ӱ���ɾ����
����ÿ������ֻ������һ��ɾ������(��Ҫע�����:��������ɸѡ���к������ܱ��������ɾ��������12��18�Ⱥ���).
����ԭʼ������ת��Ϊ��ô������������С��������ɾ����
���ǿ����κ�һ����n����������С������Ϊm����ôС�ڵ���m��������n��ˣ���õ�һ������ĺ�����
������С������Ϊ��n��˵��Ǹ����������ú�������ֱ�Ӵӱ���ɾ������Ϊ��պ�����֮ǰ�ĺ���ɾ���Ķ��壬
����������Ҫά��һ����������¼�Ѿ��ҵ��˵�������Ȼ����ݸղ������Ĳ���ִ�У����ܽ���������ɸѡ����ʱ�临�ӶȽ�ΪO(N)
*/

int  Euler(int N)
{

	int size = 0;
	for (int i = 0; i < N; i++) isPrime[i] = true; //���ó�ʼ״̬
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= N; ++i)
	{
		if (isPrime[i])
			Primes[size++] = i;
		for (int j = 0; j < size && Primes[j] <= N / i; ++j)
		{
			isPrime[i * Primes[j]] = false;
			if (i % Primes[j] == 0)
				break;
		}
	}
	//cout << "Size:" << size << endl;
	//for (int i = 0; i < size; i++)
	//{
	//	cout << Primes[i] << endl;
	//}
	return size;
}

int main()
{
	int i = 1e+7; 
	int result ;
	time_t start, end;
	start = clock();
	start = clock();
	result = Eratosthenes(i);
	end = clock();
	cout << "Eratos:    Size:  " << result << "  Time:  " << (double)(end - start) / (double)CLOCKS_PER_SEC << endl;
	start = clock();
	result = Euler(i);
	end = clock();
	cout << "Euler:     Size:  " << result << "  Time:  " << (double)(end - start) / (double)CLOCKS_PER_SEC << endl;
	getchar();
}