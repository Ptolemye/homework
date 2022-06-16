#include<iostream>
#include<string.h>
using namespace std;

ÆðÒå¼Ì³Ð Ìø¹ýÐéº¯Êý±í 
static_cast
function object
class Matrix{
	private:// ???????????????? 
		int cols;
		int rows;
		double *p;//??????????,????,???? 
	public:
		Matrix(){//?????? 
			rows = 0;
			cols = 0;
			p = NULL;
		}
		Matrix(int row , int col , int value = 0.0){//??????,???????????? 
			rows = row;
			cols = col;
			p = new double[rows * cols];//???????????????? 
			for(int i = 0 ; i < row ; i++){
				for(int j = 0 ; j < col ; j++){
					p[i * col + j] = value;//???? 
				}
			} 
		}
		~Matrix(){//????,???? 
			delete p;
		}
		int getrow(){
			return rows;
		}
		int getcol(){
			return cols;
		}
		double getvalue(int i , int j){//??i?j??????
			return p[(i - 1) * cols + j - 1];//??????????,??i?j??? 
		}
		void show(){//???? 
			for(int i = 0 ; i < rows ; i++){
				for(int j = 0 ; j < cols ; j++){
					cout << p[i * cols + j] << " ";
				}
				cout << endl;
			}
		}
		
		Matrix operator+(Matrix m){//??????????add?? 
			if(m.getrow() != rows || m.getcol() != cols){
				cout << "??????,?????" << endl;
				return *this; 
			}
			Matrix tem(rows , cols);//???????????????? 
			for(int i = 0 ; i < rows ; i++){
				for(int j = 0 ; j < cols ; j++){
					tem.p[i * cols + j] = m.getvalue(i + 1 , j + 1) + p[i * cols + j]; // ?????? 
				}
			}
			return tem;
		}
		Matrix operator-(Matrix m){//??????????sub?? 
			if(m.getrow() != rows || m.getcol() != cols){
				cout << "??????,?????" << endl;
				return *this;
			}
			Matrix tem(rows , cols);
			for(int i = 0 ; i < rows ; i++){
				for(int j = 0 ; j < cols ; j++){
					tem.p[i * cols + j] = p[i * cols + j] - m.getvalue(i + 1 , j + 1);  
				}
			}
			return tem;
		}
		Matrix operator*(Matrix m){//????? 
			if(m.getrow() != cols){
				cout << "?????" << endl;
				return *this;
			}
			Matrix tem(rows , m.getcol());//?????“????” 
			for(int i = 0 ; i < rows ; i++){
				for(int j = 0 ; j < m.getcol() ; j++){//?????? 
					for(int k = 0 ; k < cols ; k++){
						tem.p[i * m.getcol() + j] += p[i * cols + k] * m.getvalue(k + 1 , j + 1);//?????? 
					}
				}
			}
			return tem;
		}
		Matrix dot(Matrix m){//???????????,??????dot 
			if(m.getrow() != rows || m.getcol() != cols){
				cout << "??????,?????" << endl;
				return *this; 
			}
			Matrix tem(rows , cols);
			for(int i = 0 ; i < rows ; i++){
				for(int j = 0 ; j < cols ; j++){
					tem.p[i * cols + j] = p[i * cols + j] * m.getvalue(i + 1 , j + 1); 
				}
			}
			return tem;
		}
};


#include"Matrix.h"

int main(){
	
	Matrix m1(3 , 2 , 1) , m2(2 , 3 , 2) , m3(2 , 2 , 2) , m4(2 , 2 , 3) , m5(2 , 2);
	cout << m1.getrow() << endl << m1.getcol() << endl << "****" << endl;//???? 
	cout << m3.getvalue(2 , 2) << endl << m4.getvalue(2 , 2) << endl << "****" << endl; 
	(m3 + m4).show();
	(m3 - m4).show();
	(m1 * m2).show();
	( m3.dot(m4) ).show();//?????? 
	m5.show();
	
	return 0;
}
