#include"Prime.cpp"

void func(Prime &a) 
{
	//a.findPrime(100 , 999);
	cout << "素数为：" << endl; 
	a.showPrime();
}
void func(Prime *p)
{
  cout << "素数为：" << endl; 
  p->showPrime();
}
void prime(int a, int b)
{
  std::vector<Prime*> ps;
	for (int i = a; i < b; ++i) {
		Prime * p = new Prime(i);
		if (p->isPrime())
			ps.push_back(p);
    else
      delete p;
  }
	for (int i=0;i<ps.size();i++) {
		ps[i]->showPrime();
		delete ps[i];
	}
}
void superprime(int a, int b)
{
  std::vector<Prime*> ps;
	for (int i = a; i < b; ++i) {
		Prime * p = new SuperPrime(i);
		if (p->isPrime())
			ps.push_back(p);
    else
      delete p;
  }
	for (int i=0;i<ps.size();i++) {
		ps[i]->showPrime();
		delete ps[i];
	}
}  
int main(){

  Prime pm(100, 999);
  func(pm);
  func(&pm);

  SuperPrime sp(100, 999);
  func(sp);
  func(&sp);

  prime(100, 999);
  superprime(100, 999);
	return 0;
}
