#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
//khoi tao nut
//nut con
struct Con{			
	char MNK[10];
	char HoTen[30];
	char gt[4];
	Con *tiepc;
};
//nut xe
struct Xe{
	char SoXe[13];
	char LoaiXe[6];
	char HieuXe[15];
	Xe *tiepx;
};
//nut chu ho
struct CH{
	char SHK[5];
	char MNKCH[10];
	char TenCH[30];
	char Diachi[30];
	Xe *dsx;
	Con *dsc;
	CH *tieph;
};

CH *dau;
//khoi tao
void khoitao(CH *&dau){
	dau = NULL;
}
//nhap con
void NhapC(Con *&dsc1){
	char mnkt[10];
	char tenct[30];
	char gtt[4];
	Con *p,*q;
	do{
		cout<<"\n Nhap ma nhan khau con, nhan enter -> dung: ";
		fflush(stdin); gets(mnkt);
			if(strcmp(mnkt,"\0") != 0){
				p = new Con;
				strcpy(p->MNK,mnkt);
				cout<<"Nhap ten con: ";
				fflush(stdin); gets(tenct);
				cout<<"Nhap gioi tinh: ";
				fflush(stdin); gets(gtt);
					strcpy(p->HoTen,tenct);
					strcpy(p->gt,gtt);
					p->tiepc = NULL;
					//moc nut danh sach con
					if(dsc1 == NULL)
					dsc1 = p;
					else
					q->tiepc = p;
					q = p;
			}	
	}while(strcmp(mnkt,"\0") != 0);
}
//Nhap xe
void NhapX(Xe *&dsx1){
	char sxt[13];
	char lxt[6];
	char hxt[15];
	Xe *p,*q;
	do{
		cout<<"\n Nhap so xe, nhan enter -> dung: ";
		fflush(stdin); gets(sxt);
			if(strcmp(sxt,"\0") != 0){
				p = new Xe;
				strcpy(p->SoXe,sxt);
				cout<<"Nhap loai xe: ";
				fflush(stdin); gets(lxt);
				cout<<"Nhap hieu xe: ";
				fflush(stdin); gets(hxt);
					strcpy(p->LoaiXe,lxt);
					strcpy(p->HieuXe,hxt);
					p->tiepx = NULL;
					//moc nut danh sach con
					if(dsx1 == NULL)
					dsx1 = p;
					else
					q->tiepx = p;
					q=p;
			}	
	}while(strcmp(sxt,"\0") != 0);
}
//nhap chu ho
void NhapHo(CH *&ch1){
	char shkt[5];
	char mnkt[10];
	char tencht[30];
	char dct[30];
	CH *p,*q;
	do{
		cout<<"\n Nhap so ho khau: ";
		fflush(stdin); gets(shkt);
		if(strcmp(shkt,"\0") != 0){
			p = new CH;
			strcpy(p->SHK, shkt);
			cout<<"\n Nhap ma nhan khau chu ho: ";
			fflush(stdin); gets(mnkt);
			cout<<"\n Nhap ho ten chu ho: ";
			fflush(stdin); gets(tencht);
			cout<<"\n Nhap dai chi: ";
			fflush(stdin); gets(dct);
				strcpy(p->MNKCH,mnkt);
				strcpy(p->TenCH,tencht);
				strcpy(p->Diachi,dct);
				p->dsc = NULL;
				p->dsx = NULL;
			cout<<"\n Nhap xe: \n";
				NhapX(p->dsx);
			cout<<"\n Nhap con: \n";
				NhapC(p->dsc);
				if(ch1 == NULL)
					ch1 = p;
				else
					q->tieph = p;
					q = p;
		}
	}while(strcmp(shkt,"\0")!= 0);
}
void duyetcon(Con *dsc1){
	if(dsc1 != NULL){
		cout<<"\n Ho ten:"<< dsc1->HoTen;
		cout<<"\n Gioi tinh: "<<dsc1->gt;
		duyetcon(dsc1->tiepc);
	}
}
void duyetX(Xe *dsx1){
	if(dsx1 != NULL){
		cout<<"\n So xe:"<< dsx1->SoXe;
		cout<<"\n Loai xe:"<<dsx1->LoaiXe;
		cout<<"\n Hieu xe:"<<dsx1->HieuXe;
		duyetX(dsx1->tiepx);	
	}
}
void duyethk(CH *dau){
	if(dau != NULL){
		cout<<"So ho khau: "<<dau->SHK;
		cout<<"Ho ten chu ho: "<<dau->TenCH;
		cout<<"Dia chi: "<<dau->Diachi;
		duyetcon(dau->dsc);
	}
}

//int timkiemxe(CH *dau){
//	CH *p;
//	p = dau;
//	int X;
//	cout<<"Nhap hieu xe can tim: ";
//	cin>>X;
//		return 0;
//		cout<<"\n Khong tim thay xe:";
//	while(p != NULL){
//		if(p->HieuXe == X)
//		return 1;
//		p = p->tiepx;
//	}
//	return 0;
//}
//Chuong trinh chinh
int main(){	
	khoitao(dau);
	NhapHo(dau);
	duyethk(dau);
//	if(timkiemxe(dau) == 1){
//		cout<<"Co:";duyethk(dau);
//	}
//	else
//		cout<<"khong";
	cout<<"\n Nhap xong du lieu \n";
	getch();
	
}



