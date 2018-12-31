#include <iostream>     // std::cin, std::cout
#include<windows.h>
using namespace std;

int Cong(int a, int b){
	return a + b;
}

int Tru(int a,int b){
	return (a - b);
}

int Nhan(int a,int b){
	return a * b;
}

float chia(int a, int b){ //chia lay phan nguyen
	return(float(a / b));
}

int laydu(int a,int b)	{ // chia lay phan du
	return a % b;
}

void textcolor(int x)	//to mau chu~; 0~255;
{
	HANDLE mau; //
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void menu(){
	int a,b;
	textcolor(1);
	cout<<"Nhap vao so nguyen thu nhat: ";
	textcolor(4);
	cin>>a;
	textcolor(1);
	cout<<"\n Nhap vao so nguyen thu hai: ";
	textcolor(4);
	cin>>b;
	int chon;
	do{	
		textcolor(14);
		cout<<"\n \t\t\t\t\t\t-------MENU------- \n";
		cout<<"\n\t\t\t\t\t1. Phep cong.";
		cout<<"\n\t\t\t\t\t2. Phep tru.";
		cout<<"\n\t\t\t\t\t3. Phep nhan.";
		cout<<"\n\t\t\t\t\t4. Phep chia lay nguyen.";
		cout<<"\n\t\t\t\t\t5. Phep chia lay du. ";
		cout<<"\n\t\t\t\t\t0. Thoat. ";
		cout<<"\n\t\t\t\t\t Chon : ";
		cin>>chon;
		switch(chon){
			case 0: break;
			case 1:{
				textcolor(4);
				cout<<"\n Tong a + b = "<<Cong(a,b);
				break;
			}
			case 2:{
				textcolor(4);
				cout<<"\n Hieu a - b = "<<Tru(a,b);
				break;
			}
			case 3:{
				textcolor(4);
				cout<<"\n Tich a * b = "<<Nhan(a,b);
				break;
			}
			case 4:{
				textcolor(4);
				cout<<"\n Thuong a/b = "<<chia(a,b);
				break;
			}
			case 5:{
				textcolor(4);
				cout<<"\n Lay du a%b = "<<laydu(a,b);
				break;
			}
			default: cout<<"\n Sai lua chon: ";
		}
	}while(chon == 0); // chon != 0; 
}
int main(){
	menu();
	return 0;
}
