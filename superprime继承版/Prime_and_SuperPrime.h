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
	}//得到范围内所有素数
	void getPrime()
	{
		for (int i = head; i <= end; i++)
		{
			if (judgePrime(i))p.push_back(i);
		}
	}//将范围内素数存入p向量
	virtual void show()
	{
		for (int i = 0; i < getSize(); i++)
		{
			cout << p[i]<<' ';
		}
	}//此处的show函数使用了虚函数 
	int getSize()
	{
		return p.size();
	}//获取向量大小
};
class SuperPrime :public Prime//子类继承父类public的变量 ，故继承了judgePrime、getPrime、show、getSize,可在子类中直接使用 
{
public:
	SuperPrime(int _head,int _end):Prime(_head,_end){}//有参构造子类函数，并传递给父类 
public:
	void show()//父类show使用虚函数，在子类中加以改变 
	{
		for (int i = 0; i < getSize(); i++)
		{
			if (judgeSuperPrime(p[i]))cout << p[i]<<' ';
		}
	}
	bool judgeSuperPrime(int a)//这是子类的特有函数，不同于父类，用于判断超级素数 
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

