#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;

void textcolor(int x)	//to mau chu~; x = 0~255;
{
	HANDLE mau; //
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
//Ham tinh so ngay cua mot thang
int SoNgayCuaThang(int th,int nam)
{
    switch(th)
    {
    case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10: 
	case 12:
        return 31; // thang 1,3,5,7,8,10,12 co 31 ngay
		break;
    case 2:
        if (nam % 4 == 0) 
			return 29; //Nam nhuan thang 2 có 29 ngay
		else 
			return 28; //Nam khong nhuan thang 2 co 28 ngay
		break;
    default:
        return 30; //Cac thang con lai co 30 ngay
    }
}

//Ham chuyen tu ngay -> thu

int ThuCuaNgay(int ng, int th, int nam)
{
    //cout<<"Nhap vao nam can in lich: ";
    //cin>>nam;
	//int ThuCuaNgay(int ng,int th,int nam)
    int s = (nam - 1)/4 + (nam - 1) * 365;//gan bien cho s: de thay doi ngay bat dau cua thu sau thu ket thuc cua nam sau
    for (int i = 1; i < th ;++i) // i = 12 thang, tang tu 1 -> 12
        s += SoNgayCuaThang(i, nam);  //so ngay trong thang cua nam do
        s += ng;					// bien tang theo ngay
    if (ng % 7 == 00) 				//s % 7 == 0;
		return 7;					// tra ve la 7 ngay/ tuan
    else 
		return (ng % 7);				// s % 7 de tim so ngay du ra
}
void Xuat(int th,int nam){
	for (int thang = th; thang <= th; thang++)
    {	
    	if(thang == th){		//neu thang == gia tri th; xuat thong tin cua thang do ra
		cout<<"\t___________________________________________________ \n";
		cout<<"\t\t\tThang:"<<th<<"\t Nam"<<nam<<endl;
		cout<<"\t___________________________________________________ \n";
        cout<<"\n\t S";		//chu nhat
        cout<<"\t M";		//thu 2
        cout<<"\t T";		//thu 3
        cout<<"\t W";		//thu 4
        cout<<"\t T";		//thu 5
        cout<<"\t F";		//thu 6
        cout<<"\t S"<<endl; //thu 7
    }
        int k = 2; // gan bien tam k = 2
        while (k) // k != 0;
            if (ThuCuaNgay(1,thang,nam) == k || (ThuCuaNgay(1,thang,nam) == 1 && k == 8)){ //neu ngay 1, thang x,nam y ma bang k; hoac = 1,k ==8;
			cout<<"\t"<<01; // xuat ngay dau thang ra; 
			break;
			}
            else {
				cout<<" \t"; 
				k++; // k tang len 1 don vi
			}
        if (ThuCuaNgay(1,thang,nam) == 1){ //ktra neu ngay 1 cua thang do, so du s%7 co == 1;
			textcolor(4);
			cout<<endl; //xuong dong
		}
		else
			textcolor(15);
       	for (int i = 2; i <= SoNgayCuaThang(thang, nam); ++i) //vong lap chay tu ngay 2 -> = so ngay trong thang
        {
            
            if (ThuCuaNgay(i,thang,nam) == 1){ //ktra neu ngay 1 cua thang do, so du s%7 co == 1;
				cout<<"\t"<<i<<endl;} //Neu co, in ra ngay bat dau bang trung voi thu nao do
            else {
				cout<<"\t"<<i; //Neu khong, in ra ngay bat dau bang trung voi thu nao do
			}
			if(ThuCuaNgay(i,thang,nam) == 1) //ktra neu ngay 1 cua thang do, so du s%7 co == 1;
        		textcolor(4); //Thu dau tien(chu nhat) mau do
        	else
        		textcolor(15);//Cac thu con lai(2,3,4,5,6,7) mau trang
        }
        textcolor(15);
        cout<<"\n\t___________________________________________________ \n";
        cout<<endl;
        cout<<endl;
    }
}
int main()
{	
	
    int th, nam;		// th = thang , nam = nam;
    cout<<"Nhap vao mot thang : ";
    cin>>th;
    cout<<"Nhap vao nam: ";
    cin>>nam;
   	cout<<"Lich cua thang \t"<<th<<"\tNam "<<nam<<"\tla:";
    cout<<endl;
    Xuat(th,nam); // xuat thang va nam can tim
    getch();
}  
