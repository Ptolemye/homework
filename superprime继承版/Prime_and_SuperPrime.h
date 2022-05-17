#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Prime
{
public:
	int head,end;
	vector<int>p;
public:
	Prime(int _head,int _end)
	{
		head = _head;
		end = _end;
		getPrime();
	}
	bool judgePrime(int a)
	{
		for (int i = 2; i < sqrt(a) + 1; i++)
		{
			if (a % i == 0)return false;
		}
		return true;
	}//�õ���Χ����������
	void getPrime()
	{
		for (int i = head; i <= end; i++)
		{
			if (judgePrime(i))p.push_back(i);
		}
	}//����Χ����������p����
	virtual void show()
	{
		for (int i = 0; i < getSize(); i++)
		{
			cout << p[i]<<' ';
		}
	}//�˴���show����ʹ�����麯�� 
	int getSize()
	{
		return p.size();
	}//��ȡ������С
};
class SuperPrime :public Prime//����̳и���public�ı��� ���ʼ̳���judgePrime��getPrime��show��getSize,����������ֱ��ʹ�� 
{
public:
	SuperPrime(int _head,int _end):Prime(_head,_end){}//�вι������ຯ���������ݸ����� 
public:
	void show()//����showʹ���麯�����������м��Ըı� 
	{
		for (int i = 0; i < getSize(); i++)
		{
			if (judgeSuperPrime(p[i]))cout << p[i]<<' ';
		}
	}
	bool judgeSuperPrime(int a)//������������к�������ͬ�ڸ��࣬�����жϳ������� 
	{
		int sum=0; int largesum=0;
		if (!judgePrime(a))return false;
		for(;a>1;)
		{
			sum += a % 10;
			largesum += (a % 10) * (a % 10);
			a /= 10;
		}
		if (judgePrime(sum) && judgePrime(largesum))return true;
		else return false;
	}
};//

