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

void thongBaoKetQua(float kq, bool coNghiem = true)
{
	if (coNghiem)
		printf("Nghiem cua phuong tring la: %0.3f\n", kq);
	else printf("Phuong trinh khong co nghiem o khoang nay.\n");
}


float Tinh(float a, float b)
{
	int count = 0;
	float c;
	do
	{
		c = 0.5*(a+b);
		if (f(c)>0) b = c;
		else a = c;
		// xu ly lap vo han
		count++;
		if (count>1000) 
		{
			thongBaoKetQua(c, false);
			return 0;
		}
	}
	while ( fabs(f(c)) > EPS);
	thongBaoKetQua(c);
	return c;
}


int main()
{
	float a,b;
	printf("Nhap 2 diem a va b voi f(a)<0 va f(b)>0:\n");
	scanf("%f %f", &a, &b);
	Tinh(a,b);
	
	return 0;
}