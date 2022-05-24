#include<iostream>
#include<vector>

using namespace std;

class Prime{
	public:
		Prime(int low , int high);
    	Prime(int _n);
    bool judgePrime(int);
    virtual bool isPrime();
	virtual	void showPrime(); 
		int getSize(); 
	int n;
	protected:
		vector<int> p;
};

class SuperPrime:public Prime {
	public:
		SuperPrime(int low , int high);
    	SuperPrime(int _n);
    	bool isPrime();
		void showPrime();
		private:
    bool judgePrime(int);
		void findPrime(int , int); 
		vector<int>sp; //
};


