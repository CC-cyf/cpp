#include<iostream>
#include<time.h>
using namespace std;

/*
合数总是能分解成几个素数的乘积，利用这个性质加速质数的判断。
产生前100000(十万)个质数的序列，用于加速素数判断。
用此方法生成前100000(十万)个质数用时111ms(release中为64ms)，生成前1000000(百万)个质数用时2503ms。
生成的第100000个质数为1299709，用该方法可以检测的最大数字为1299709的平方，既1689243484681,已经大大超出int的范围。

*/
int* PrimeSequance = new int[100000];
int PrimeSequanceNum = 0;

bool IsAPrime(int num)
{
	for (int i = 0; PrimeSequance[i] * PrimeSequance[i] <= num && i < PrimeSequanceNum; i++)
	{
		if (num%PrimeSequance[i] == 0)return false;
	}
	return true;
}

void GeneratePrimeSequance()
{
	PrimeSequance[0] = 2;
	PrimeSequanceNum++;
	//给出第一个质数
	for (int i = 3; PrimeSequanceNum < 100000; i+=2)//跳过了所有偶数
	{
		if (IsAPrime(i) == true)
		{
			PrimeSequance[PrimeSequanceNum] = i;
			PrimeSequanceNum++;
		}
	}
}

//rand()生成的随机数在0x7fff(32767)以内
int CreateABigPrime()
{
	srand((unsigned)time(0));
	int BigPrime = (rand() % 900 + 100) * 1000000 + (rand() % 1000) * 1000 + (rand() % 1000);//生成一个100000000~999999999的大数
	while (IsAPrime(BigPrime) == false)BigPrime++;
	return BigPrime;
}

//测试用
int main()
{
	int begin, end;
	begin = clock();
	GeneratePrimeSequance();
	end = clock();
	for (int i = 0; i < 100; i++)
	{
		cout << PrimeSequance[i] << endl;
	}
	cout << PrimeSequance[99999] << endl;
	cout << "计算前100000(十万)个素数用时" << end - begin << "ms" << endl;
	int temp = CreateABigPrime();
	cout << "生成的大质数为" << temp << endl;
	system("pause");
	return 0;
}
