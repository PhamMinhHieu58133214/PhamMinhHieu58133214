#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <stdlib.h>
using namespace std;

ifstream f("dulieua.txt"); //truyen file dulieu.txt vao bien khachhang;
ifstream a("dl2.txt");		//truyen file dl2.txt vao bien giao dich;
ofstream g("customer.txt"); // luu danh sach khach hang tu bien khach hang vao file customer;
ofstream h("trans.txt");	//luu danh sach giao dich tu bien giao dich vao file trans.txt;

class KhachHang{
	protected:
		string MSKH;
		string TenKH;
		int Tien;
	public:
		KhachHang(){};
		void NhapTTKH(){
			string s;
			getline(f,s); MSKH = s; //Truyen file dulieua.txt de truy xuat MSKH;
			getline(f,s); TenKH = s; //Truyen file dulieua.txt de truy xuat TenKH;
			getline(f,s); Tien = atoi(s.c_str());//Truyen file dulieua.txt de truy xuat Tien;
		}	
		void XuatTTKH(){
			cout<<"\n Ma so khach hang: "<<MSKH;
			cout<<"\n Ho&Ten khach hang: "<<TenKH;
			cout<<"\n So du trong tai khoan khach hang: "<<Tien;
			g<<"\n\n Ma so khach hang: "<<MSKH;  //luu vao file customer.txt
			g<<"\n Ho&Ten khach hang: "<<TenKH; //luu vao file customer.txt
			g<<"\n So du trong tai khoan khach hang: "<<Tien;//luu vao file customer.txt
			h<<"\n\n Ma so khach hang: "<<MSKH; // Luu vao file trans.txt
		}
};
class GiaoDich : public KhachHang{
	private:
		string LoaiGD;
		int LuongTien;
	public:
		friend class dskh;
		void NhapGD(){
			KhachHang::NhapTTKH();
			string s; 
			getline(a,s); LoaiGD = s;	//Truyen file dl2.txt de truy xuat LoaiGD
			getline(a,s); LuongTien = atoi(s.c_str());	//Truyen file dl2.txt de truy xuat SoTien
		}
		void XuatGD(){
			KhachHang::XuatTTKH();
			cout<<"\n Loai giao dich: "<<LoaiGD;
			cout<<"\n Luong tien giao dich: "<<LuongTien;
			h<<"\n Loai giao dich: "<<LoaiGD;// Luu vao file trans.txt
			h<<"\n Luong tien giao dich: "<<LuongTien;// Luu vao file trans.txt
		}
};
class QLKH{
	protected:
		int n;
		vector <KhachHang> dskh; //Vector dskh dung de them cac KhachHang vao
		vector <GiaoDich> dsgd; //Vector dsgd dung de them cac GiaoDich vao
	public:
		void NhapTTKH(){
			string s;
			getline(f,s); 
			n = atoi(s.c_str()); //so luong khach hang
			dskh.resize(n); // kich co size dskh = n
			dsgd.resize(n); // kich co size dsgd = n
			cout<<n<<endl;
			for(int i = 0;i < dsgd.size();i++)
				{
					dsgd[i].NhapGD();
				}
			f.close();
		}
		void XuatTTKH(){
			cout<<"\n Khach hang: "<<n;
				for(int i=0;i<dsgd.size();i++)
				dsgd[i].XuatGD();
		}
		void ThemKH(){
			string MSKH,TenKH,LoaiGD;
			int Tien,SoTien;
			int m;
			cout<<"\n\n So khach hang can them: ";
			cin>>m;
			cin.sync();
			for(int i = n; i < n + m;i++){ // bat dau chay tu n(file truyen vao n =3; i chay den n+m thi dung;
			cout<<" Ma so khach hang: ";
			cin>>MSKH;
			cout<<" Ho&Ten khach hang: ";
			cin>>TenKH;
			cout<<" So du trong tai khoan khach hang: ";
			cin>>Tien;
			cout<<" Loai giao dich: ";
			cin>>LoaiGD;
			cout<<" So tien giao dich: ";
			cin>>SoTien;
			cout<<endl;
			g<<"\n\n Ma so khach hang: "<<MSKH;//luu vao file customer.txt
			g<<"\n Ho&Ten khach hang: "<<TenKH;//luu vao file customer.txt
			g<<"\n So du trong tai khoan khach hang:"<<Tien;//luu vao file customer.txt
			h<<"\n\n Ma so khach hang: "<<MSKH; //luu vao file trans.txt
			h<<"\n Loai Giao dich: "<<LoaiGD; //luu vao file trans.txt
			h<<"\n So tien giao dich: "<<SoTien; //luu vao file trans.txt	
		}	
			g<<"\n\n Tong so khach hang: "<<n + m;
			for(int i = n; i < n + m;i++){
				cout<<"So khach hang vua them: "<<m;
				cout<<" Thong tin khach hang vua them: \n";
				cout<<"\n Ma so khach hang: "<<MSKH;
				cout<<"\n Ho&Ten khach hang: "<<TenKH;
				cout<<"\n So du trong tai khoan khach hang:"<<Tien;
				cout<<"\n Loai Giao dich: "<<LoaiGD;
				cout<<"\n So tien giao dich: "<<SoTien<<endl;
			}
	}
	/*	int Gui(){
			string LoaiGD,gui;
			int SoTien,Tien;
			ifstream filein;
			filein.open("trans.txt",ios::in);
			filein>> LoaiGD;
			filein>> SoTien;
			ifstream cus;
			cus.open("customer.txt",ios::in);
			cus>>Tien;
			if(LoaiGD == gui)
				if(SoTien >= 500000){
					Tien += SoTien;
					return Tien;
				}
			for(int i = 0; i < dskh.size();i++){
				dskh[i].XuatTTKH();
			g<<"So du tai khoan khach hang sau khi gui: "<<Tien;	
			}
		}*/

};
int main(){
	QLKH DSKH;
	DSKH.NhapTTKH();
	DSKH.XuatTTKH();
	DSKH.ThemKH();
	//DSKH.Gui();
}

