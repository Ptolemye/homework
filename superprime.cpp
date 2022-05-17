#include <iostream>
#include <math.h>
using namespace std;
int prime(int number)
{
    int flag = 1;
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
class Sum_and_Sum_of_Square
{
	int number;
public:
	int _number = number;
    int sum=0;
    int sum_of_square=0;
    while(1)
    {
            sum += _number % 10;
			sum_of_square += pow(_number % 10,2);
    		if (number<=10)break;
			_number=_number/divisor;
	}
    if (prime(sum) * prime(sum_of_square) == 1)
    return 1;
}

int main()
{
    for (int i = 100; i < 1000; i++)
    {
        if (Sum_and_Sum_of_Square(i) == 1&&prime(i)==1)
            cout << i<<endl;
    }
}
