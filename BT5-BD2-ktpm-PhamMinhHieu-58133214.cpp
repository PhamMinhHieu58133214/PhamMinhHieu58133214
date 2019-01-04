#include<graphics.h>
#include<conio.h>
#include <iostream>
using namespace std;
 


//---Duong thang----------------
int duongthang(int x1,int x2,int y1,int y2){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	line(x1,x2,y1,y2);
	getch();
	closegraph();
	return 0;
}
//hinh tam giac--------------
int hinhtamgiac(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4){
	int gd = DETECT, gm; 
	int arr[] = {x1,x2,x3,x4,y1,y2,y3,y4}; 
    initgraph(&gd, &gm, "");
    drawpoly(4, arr);
    getch();
    closegraph();
    return 0; 
}
//-----------Hinh chu nhat
int hinhchunhat(int a,int b,int c,int d){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	rectangle(a,b,c,d);
	getch();
	closegraph();
	return 0;
}
//hinh vuong----------------
int hinhvuong(int a,int b,int c,int d){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	rectangle(a,b,c,d);
	getch();
	closegraph();
	return 0;
}

//---Hinh tron-----
int hinhtron(int x, int y,int r){
   	int gd = DETECT, gm;
  	initgraph(&gd, &gm, "");
  	circle(x,y,r);
  	getch();
  	closegraph();
 	return 0;
}

void textcolor(int x)	//to mau chu~; 0~255;
{
	HANDLE mau; //
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void menu(){
	int chon;
	do{	
		textcolor(14);
		cout<<"\n \t\t\t\t\t\t-------MENU------- \n";
		cout<<"\n\t\t\t\t\t1. Duong thang.";
		cout<<"\n\t\t\t\t\t2. Tam giac.";
		cout<<"\n\t\t\t\t\t3. Hinh chu nhat.";
		cout<<"\n\t\t\t\t\t4. Hinh vuong.";
		cout<<"\n\t\t\t\t\t5. Duong tron. ";
		cout<<"\n\t\t\t\t\t6. Thoat. ";
		cout<<"\n\t\t\t\t\t Chon : ";
		cin>>chon;
		switch(chon){
			case 1:{
				int x1,x2,y1,y2;
				cout<<"Nhap toa do x1: ";
				cin>>x1;
				cout<<"Nhap toa do x2: ";
				cin>>x2;
				cout<<"Nhap toa do y1: ";
				cin>>y1;
				cout<<"Nhap toa do y2: ";
				cin>>y2;
				cout<<duongthang(x1,x2,y1,y2);
				break;
			}
			case 2:{
				int x1,x2,x3,x4,y1,y2,y3,y4;
				cout<<"Nhap toa do x1: ";
				cin>>x1;
				cout<<"Nhap toa do x2: ";
				cin>>x2;
				cout<<"Nhap toa do x3: ";
				cin>>x3;
				cout<<"Nhap toa do x4: ";
				cin>>x4;
				cout<<"Nhap toa do y1: ";
				cin>>y1;
				cout<<"Nhap toa do y2: ";
				cin>>y2;
				cout<<"Nhap toa do y3: ";
				cin>>y3;
				cout<<"Nhap toa do y4: ";
				cin>>y4;
				cout<<hinhtamgiac(x1,x2,x3,x4,y1,y2,y3,y4);
				break;
			}
			case 3:{
				int a,b,c,d;
				cout<<"Nhap chieu dai canh a: ";
				cin>>a;
				cout<<"Nhap chieu dai canh b: ";
				cin>>b;
				cout<<"Nhap chieu dai canh c: ";
				cin>>c;
				cout<<"Nhap chieu dai canh d: ";
				cin>>d;
				cout<<hinhchunhat(a,b,c,d);
				break;
			}
			case 4:{
				int a,b,c,d;
				cout<<"Nhap chieu dai canh:";
				cin>>a;
				cout<<"Nhap chieu rong: ";
				cin>>c;
				b = a;
				d = c;
				cout<<hinhvuong(a,b,c,d);
				break;
			}
			case 5:{
				int x,y,r;
				cout<<"Nhap x: ";
				cin>>x;
				cout<<"Nhap y: ";
				cin>>y;
				cout<<"Nhap ban kinh: ";
				cin>>r;
				cout<<hinhtron(x,y,r);
				break;
			}
		}
		
	}while(chon == 0); // chon != 0; 
			
}
int main(){
	menu();
	return 0;
}
