#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Nhap(int a[100][100],int &n,int &m){
	srand(time(NULL));
	do{
		for(int i = 0; i < n;i++)
			for(int j = 0; j < m ; j++){
				a[i][j] = rand()%(100 - 0 + 1);
			}
	}while(n < 3 || n > 5);
}
void Xuat(int a[100][100],int n,int m){
	for(int i = 0; i < n;i++){
		for(int j = 0; j < m; j++)
		cout<<"\t"<<a[i][j]<<"\t";
		cout<<endl;
	}
}
void xoadong(int a[100][100],int &n,int m){
	int d;
	do{
		cout<<"\n Nhap vao dong can xoa: ";
		cin>>d;
	}while(0 > d || d > n);
	for(int i = d; i < n - 1 ; i++)
		for(int j = 0; j < m ; j++){
			a[i][j] = a[i + 1][j];
		}
		n--;
		Xuat(a,n,m);
}
void xoacot(int a[100][100],int n,int &m){
		int c;
	do{
		cout<<"Nhap vao cot can xoa: ";
		cin>>c;
	}while(0 > c || c > m);
	for(int i = 0; i < n ; i++)
		for(int j = c; j < m - 1 ; j++){
			a[i][j] = a[i][j + 1];
		}
		m--;
		Xuat(a,n,m);
}
bool ktra(int a[100][100],int n){
	for(int i = 0; i < n - 1 ; i++){
		for(int j = i + 1; j < n ; j++){
			if(a[i][j] != a[j][i]){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	int a[100][100];
	int n,m;
	do{
		cout<<"Nhap ma tran nxn = ";
		cin>>n;
	}while(3 > n || n > 10);
	m = n;
	Nhap(a,n,m);
	cout<<"Ma tran nxn:"<<endl;
	Xuat(a,n,m);
	if(ktra(a,n) == 0){
		cout<<"\n Ma tran khong doi xung. ";
	}
	else{
		cout<<"\n Ma tran doi xung.";
	}
	xoadong(a,n,m);
	xoacot(a,n,m);
	
		
}
