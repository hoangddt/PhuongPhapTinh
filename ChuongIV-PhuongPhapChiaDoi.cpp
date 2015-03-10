// ChuongIV-Phuong phap chia doi.
// phuong trinh trang 19
#include <stdio.h>
#include <math.h>
#define EPS 0.001

float f(float x)
{
	// Tinh cho phuong trinh 2^x + x -4
	return pow(2,x) + x -4;
}

int main()
{
	float a,b,c;
	printf("Nhap 2 diem a va b voi f(a)<0 va f(b)>0:\n");
	scanf("%f %f", &a, &b);
	do
	{
		c = 0.5*(a+b);
		if (f(c)>0) b = c;
		else a = c;
	}
	while ( fabs(a-b)>EPS && f(c) != 0);
	printf("Nghiem cua phuong tring la: %0.3f\n", c);
	return 0;
}