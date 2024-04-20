#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

//nhap vao 2 da thuc P(x) va q(x) bac n 
// tinh P'(d)/Q'(d) voi d nhap tu ban phim
// goi a la max cua cac he so cua da thuc P(x) , b la max cac he so cua da thuc Q(x) 
// tinh a - b;
//in ra man hinh he so tong cua p(x) va q(x)

void nhap(int n ,int a[]){
	for(int i = 0 ; i <= n;i++){
		scanf("%d", &a[i]);
	}
}

void xuat(int n,int a[]){
	for(int i = 0 ; i <= n; i++){
		printf("%d  ",a[i]);
	}
	printf("\n");
}

float dao_ham(int n,int a[],int d){
	float kq = 0;
	for(int i = 1 ; i <= n; i++)
		kq += i * pow(d, i - 1);
	return kq;
}

int max(int n,int a[]){
	int res = a[0];
	for(int i = 0 ; i <= n;i++)	
		if(a[i] > res)
			res = a[i];
	return res;
}
int *tongdathuc(int n,int a[],int b[]){
	int *c = new int[n + 1];
	for(int i = 0 ; i < n;i++){
		c[i] = a[i] + b[i];
	}
	return c;
}

int main(){
	int n,d;
	printf("nhap bac cua 2 da thuc la : ");
	scanf("%d",&n);
	int P[100],Q[100];
	printf("\nnhap cac he so cua da thuc P(x) :\n");
	nhap(n,P);
	printf("\nnhap cac he so cua da thuc Q(x):\n");
	nhap(n,Q);
	printf("\nnhap d :\n");
	scanf("%d",&d);
	printf("P'(d)/Q'(d) = %.2f",dao_ham(n,P,d)/dao_ham(n,Q,d));
	printf("\na - b = %d",max(n,P)-max(n,Q));
	
}
