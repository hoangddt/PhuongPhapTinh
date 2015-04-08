#include <stdio.h>

void Nhap(float a[], int n)
{
	printf("Nhap lan luot cac he so:\n");
	for (int i = 0; i <= n; ++i)
	{
		scanf("%f", &a[i]);
	}
}

// Ham tinh dung de quy
void HoocnerRecurison(float a[], int n, float c)
{
	if (n==0) return;
	for (int i = 0;i < n;i++)
		a[i+1] = a[i] *c +a[i+1];
	HoocnerRecurison(a,n-1,c);
}

// Ham tinh khong dung de quy
void Hoocner(float a[], int n, float c)
{
 	for (int i = n; i > 0; --i)
	 	for (int j=0; j<i; j++)
	 		a[j+1] = a[j]*c + a[j+1];
}

void KetQua(float a[], int n, float c)
{
	printf("Cac he so cua phuong trinh\n");
	for (int i = 0; i <= n; ++i)
	{
		printf("%.2f  ", a[i]);
	}
}

int main()
{
	int n, c;
	float a[100];
	printf("Nhap bac phuong trinh: n= ");
	scanf("%d",&n);
	Nhap(a,n);
	printf("Nhap gia tri c: \n");
	scanf("%d", &c);
	HoocnerRecurison(a, n, c);
	KetQua(a,n,c);
	return 0;
}
