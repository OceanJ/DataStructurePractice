/*埃拉托斯特尼筛法，简称埃氏筛或爱氏筛，是一种公元前250年由古希腊数学家埃拉托斯特尼所提出的一种简单检定素数的算法。
给出要筛数值的范围N，找出\sqrt{N}以内的素数p_{1},p_{2},\dots,p_{k}。
先用2去筛，即把2留下，把2的倍数剔除掉；再用下一个质数，也就是3筛，把3留下，把3的倍数剔除掉；
接下去用下一个质数5筛，把5留下，把5的倍数剔除掉；不断重复下去......。
算法复杂度为O(NloglogN) 
from:http://blog.csdn.net/avan_lau/article/details/7257566 */

#include <iostream>
#include <ctime>
using namespace std;

const int MAX = 1e+8;  //限定最大范围
int Primes[MAX];		 //存储素数表
bool isPrime[MAX];	 //用于筛选



int Eratosthenes(int N)
{
	int size = 0;
	for (int i = 0; i < N; i++) isPrime[i] = true; //设置初始状态
	for (int i = 2; i * i< N; i++) 
	{ 
		if (isPrime[i])  
			for (int j = i + i; j < N; j += i) //筛掉素数的倍数
				isPrime[j] = false;
	}
	for (int i = 2; i < N; i++)	//保存筛选结果 
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
对于一个正整数，如果其为合数，那么该数的质因数分解形式是唯一的。
现定义：对于某个范围内的任意合数，只能由其最小的质因子将其从表中删除。我们很容易得出该算法的时间复杂度为线性的，
为什么呢？因为一个合数的质因数分解式是唯一的，而且我们定义了合数只能由最小质因子将其从表中删除，
所以每个合数只进行了一次删除操作(需要注意的是:埃氏素数筛选法中合数可能被多个质数删除，比如12，18等合数).
现在原始的问题转换为怎么将合数由其最小的质因子删除？
我们考查任何一个数n，假设其最小质因子为m，那么小于等于m的质数与n相乘，会得到一个更大的合数，
且其最小质因数为与n相乘的那个质数，而该合数可以直接从表中删除，因为其刚好满足之前的合数删除的定义，
所以我们需要维护一个表用来记录已经找到了的质数，然后根据刚才叙述的步骤执行，就能将埃氏素数筛选法的时间复杂度降为O(N)
*/

int  Euler(int N)
{

	int size = 0;
	for (int i = 0; i < N; i++) isPrime[i] = true; //设置初始状态
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