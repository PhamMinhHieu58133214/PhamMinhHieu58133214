# include <stdio.h>
# include <conio.h>

void Xoan(int a[5][5],int t,int n){ 

  		if (t == n) 
		  printf ("%3d",a[t][t]);
  		else{ 
		  	for (int i = t ; i <= n;i++)   
   				printf("%3d",a[t][i]); 
     		for (int i = t + 1 ;i <= n ; i++) 
	 			printf("%3d",a[i][n]); 
     		for (int i = n - 1 ; i >= t ;i--)
	 			printf("%3d",a[n][i]); 
     		for (int i = n - 1; i >= t + 1 ;i--) 
	 			printf("%3d",a[i][t]);
     		Xoan(a,t + 1,n - 1);
   			}
}
int main(){ 
	int t,n;
	int a[5][5];
	FILE *f = fopen("E://Thuc tap co so/Nhom2-PhamMinhHieu-58133214/dlbt1.txt","rt");
	fscanf(f,"%d",&n);
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++)
		fscanf(f,"%d",&a[i][j]);
	}
	Xoan(a,0,4);
	fclose(f);
}
