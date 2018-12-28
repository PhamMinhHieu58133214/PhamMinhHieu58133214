#include <iostream>
#include <conio.h>
using namespace std;
void Nhap(int a[],int n){

		for(int i = 0; i < n; i++){
			cout<<"a["<<i<<"]= ";
			cin >> a[i];
			}		
}
void Xuat(int a[],int n){
	for(int i = 0; i < n;i++)
	cout<<a[i]<<"\t";
}
void Heap(int a[],int i,int n){
	for(i = 1;i < n; i++){
		if(a[i] > a[2*i] && a[i] > a[2*i + 1]){
			swap(a[i],a[2*i]);
			swap(a[i],a[2*i + 1]);
			}
		else{
				swap(a[i],a[2*i]);
				swap(a[i],a[2*i + 1]);	
				}	
	cout<<a[i];	
	return;
	}
}
void Heap_sort(int a[],int i,int n){
	for(i = n/2; i >= 1;i--)
		Heap(a,i,n);
	int l = n;
	int k = i;
	while(l > k){
		a[k] == a[l];
		l = l - k;
		Heap(a,k,l);
	}
	return;
}

int main(){
	int a[10];
	int n,i;
	do{
		cout<<"Nhap n:";
		cin>>n;
	}while(n == 0);
	Nhap(a,n);
	cout<<"\n Mang chua sap xep: \n";
	Xuat(a,n);
	cout<<"\n Mang sau sap xep: \n";
	Heap(a,i,n);
	cout<<"\nSap xep:\n";
	Heap_sort(a,i,n);
	getch();
}
