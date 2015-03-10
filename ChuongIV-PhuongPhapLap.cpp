// ChuongIV-Phuong phap lap.
// phuong trinh trang 21
#include <stdio.h>
#include <math.h>
#define EPS 0.001

float g(float x)
{
	// Tinh cho phuong trinh g(x) = (x+1)^1/3
	return pow(x+1,1.0/3);
}

void thongBaoKetQua(float kq, bool coNghiem = true)
{
	if (coNghiem)
		printf("Nghiem cua phuong tring la: %0.3f\n", kq);
	else printf("Phuong trinh khong co nghiem o khoang nay.\n");
}


float Tinh(float a, float b, float x)
{
	// int count = 0;
	float temp;
	do
	{
		temp = x;
		x = g(x);
		if (x<a || x>b)
		{
			thongBaoKetQua(x, false);
			return 0;
		}
	}
	while ( fabs(x-temp) > EPS);
	
	thongBaoKetQua(x);
	return x;
}


int main()
{
	float a,b,x;
	printf("Nhap khoang nghiem a va b:\n");
	scanf("%f %f", &a, &b);
	printf("Chon x= \n");
	scanf("%f", &x);
	Tinh(a,b,x);
	
	return 0;
}