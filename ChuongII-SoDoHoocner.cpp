#include <stdio.h>

void Nhap(float a[], int n)
{
	for (int i = 0; i <= n; ++i)
	{
		scanf("%f",&a[i]);
	}
}


float hoocner(float a[], int n, float c)
{
	// Tinh theo phuong phap de quy
	if (n == 0) return a[0];
		return hoocner(a,n-1,c) * c + a[n];
}

// float hoocner(float a[], int n, float c)
// {
// 	float p = 0;
// 	for (int i = 0; i <= n; ++i)
// 	{
// 		p = p*c + a[i];
// 	}
// 	return p;
// }

int main(int argc, char const *argv[])
{
	int n;
	float a[100], c;
	printf("Nhap bac da thuc n: ");
	scanf("%d", &n);
	Nhap(a,n);
	printf("Nhap c: ");
	scanf("%f", &c);
	
	
	printf("Gia tri f(%.2f) la: %.2f\n", c, hoocner(a,n,c) );
	return 0;
}
