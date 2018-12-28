#include <iostream>
using namespace std;

struct nut{
	int Info;
	nut *left, *right;
};
typedef nut Node;
Node *goc;
//-----------------------------
void khoitao(Node *goc){
	goc == NULL;
}
//-------------
void mocnut(Node *&goc,int x){
	if(goc == NULL){
		goc = new Node;
		goc->Info;
		goc->left = NULL;
		goc->right = NULL;
	}
	else
		if(goc->Info >= x)
			mocnut(goc->left,x);
		else
			mocnut(goc->right,x);
}
//---------------------
void taocay(Node *&goc){
	int tam;
	do{
		cout<<"nhap 1 so nguyen, nhan 0 de dung chuong trinh: ";
		cin>>tam;
		if(tam != 0)
			mocnut(goc,tam);
	}while(tam != 0);
}
void DuyetLRN(Node *&goc){
	if(goc != NULL){
		DuyetLRN(goc->left);
		cout<<""<<goc->Info;
		DuyetLRN(goc->right);
	}
}
int max(int a, int b){
	if(a > b)
		return a;
	else
		return b;
}
int Chieucao(Node *goc){
	if(goc == NULL)
		return 0;
	else
		if((goc -> left == NULL) && (goc -> right == NULL))
			return 1;
		else
			return 1 + max(Chieucao(goc->left),Chieucao(goc->right));
}
void Xuat(Node *&goc){
    if(goc != NULL){
        cout<<goc->Info<<" ";
        Xuat(goc->left);
        Xuat(goc->right);
    }
}
int xoanut(Node *goc,int x){
	cout<<"Nhap vi tri can xoa: ";
	cin>>x;
	 if(goc == NULL) 
	 	return 0;
    if(goc->Info > x) 
		xoanut(goc->left,x);
    if(goc->Info < x) \
		xoanut(goc->right,x);
    if(goc->Info == x) {
        Node *p;
		p = goc;
        if(goc->left == NULL) { 
            goc = goc->right; 
        }
        else 
			if(goc->right == NULL){
            	goc = goc->left;
        }
    	}
    else{
    	Node *p;
    	p = goc;
    	delete p;
	}
}
int main(){
	khoitao(goc);
	taocay(goc);
	Xuat(goc);
	cout<<"\n Duyet LRN:";
	DuyetLRN(goc);
	cout<<"\n Chieu cao cua cay:"<<Chieucao(goc);
	cout<<endl;
	int x;
	cout<<"\n Xoa nut:";
	xoanut(goc,x);
}
