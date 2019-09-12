#include<iostream>
#include<time.h>
using namespace std;

/*
���������ֽܷ�ɼ��������ĳ˻�������������ʼ����������жϡ�
����ǰ100000(ʮ��)�����������У����ڼ��������жϡ�
�ô˷�������ǰ100000(ʮ��)��������ʱ111ms(release��Ϊ64ms)������ǰ1000000(����)��������ʱ2503ms��
���ɵĵ�100000������Ϊ1299709���ø÷������Լ����������Ϊ1299709��ƽ������1689243484681,�Ѿ���󳬳�int�ķ�Χ��

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
	//������һ������
	for (int i = 3; PrimeSequanceNum < 100000; i+=2)//����������ż��
	{
		if (IsAPrime(i) == true)
		{
			PrimeSequance[PrimeSequanceNum] = i;
			PrimeSequanceNum++;
		}
	}
}

//rand()���ɵ��������0x7fff(32767)����
int CreateABigPrime()
{
	srand((unsigned)time(0));
	int BigPrime = (rand() % 900 + 100) * 1000000 + (rand() % 1000) * 1000 + (rand() % 1000);//����һ��100000000~999999999�Ĵ���
	while (IsAPrime(BigPrime) == false)BigPrime++;
	return BigPrime;
}

//������
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
	cout << "����ǰ100000(ʮ��)��������ʱ" << end - begin << "ms" << endl;
	int temp = CreateABigPrime();
	cout << "���ɵĴ�����Ϊ" << temp << endl;
	system("pause");
	return 0;
}
