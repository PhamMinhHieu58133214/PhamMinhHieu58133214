#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void NhapNN(int a[10],int m){	//Thuc hien nhap mang tu 1 -> m;
	for(int i = 1; i <= m;i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}

}
void XuatNN(int a[10],int m){	//Xuat mang vua nhap tu 1 -> m
	for(int i = 1; i <= m ; i++)
	cout<<""<<a[i];		//output: 1 -> m
}
void TimNN(int a[10],int m,int n){ //tim n so ngau nhien tu 1->m
	for(int i = 0;i < n ; i++){
			cout<<rand()% m + 1; //Lay ngau nhien tu 1 -> m.
		}
}

int main(){
	int a[10];
	int m,n;
		cout<<"Nhap m: "; //input m;
		cin>>m;
	NhapNN(a,m); //intput 1->m
	XuatNN(a,m); //output 1->m
	do{
	cout<<"\nNhap n:";			//So luong so ngau nhien can tim
	cin>>n;
	}while(n >= m);
	TimNN(a,m,n);
	
}
