#include<iostream>
using namespace std;

class A
{
private:
	int _a;
	int _b;
public:
	void set(int a,int b);
	void show();
};

void A::set(int a,int b)
{
	_a = a;
	_b = b;
}
void A::show()
{
	cout << '(' << _a << ',' << _b << ')' << endl;
}

int main()
{
	A a1;
	int a, b;
	cin >> a >> b;
	a1.set(a, b);
	a1.show();
}
