#include"Prime.h"
#include<math.h>

Prime::Prime(int low , int high){
	for(int i = low ; i <= high ; i++){
		if(judgePrime(i)){
			p.push_back(i); 
		}
	}
}
Prime::Prime(int _n):n(_n){
	if(judgePrime(_n))
	{
		p.push_back(_n);
	}
} 
bool Prime::isPrime(){
	if(Prime::judgePrime(n))
	{
		return true;
	}
	else return false;
}
void Prime::showPrime(){
	for(int i = 0 ; i < p.size() ; i++){
		cout << p[i] << " ";
	}
	cout << endl;
}
int Prime::getSize(){
	return p.size(); 
}
bool Prime::judgePrime(int a){
	if(a == 2){
		return true;
	}
	for(int i = 2 ; i <= sqrt(a) + 1 ; i++){
		if(a % i == 0){
			return false;
		}
	}
	return true;
}


SuperPrime::SuperPrime(int low , int high):Prime(low,high){
	findPrime(low, high); 
}
void SuperPrime::findPrime(int low , int high){
	for(int i = 0 ; i < p.size() ; i++){
		if(SuperPrime::judgePrime(p[i])){
			sp.push_back(p[i]); 
		}
	}
} 
SuperPrime::SuperPrime(int _n):Prime(_n){
	if (SuperPrime::judgePrime(_n))
	{
		sp.push_back(_n);
	 } 
}
void SuperPrime::showPrime(){
	for(int i = 0 ; i < sp.size() ; i++){
		cout << sp[i] << " ";
	}
	cout << endl;
}  
bool SuperPrime::isPrime(){
	if(Prime::judgePrime(n)&&SuperPrime::judgePrime(n) )
	{
		return true;
	}
	else return false;
}
bool SuperPrime::judgePrime(int a){
	int eve[20] = {0} , i = 0 , sum = 0 , largesum = 0;
	while(a){
		eve[i] = a % 10;
		sum += eve[i];
		largesum += eve[i] * eve[i];
		i++;
		a /= 10;
	}
	if(Prime::judgePrime(sum) && Prime::judgePrime(largesum) && Prime::judgePrime(a)){
		return true;
	}
	return false;
}
