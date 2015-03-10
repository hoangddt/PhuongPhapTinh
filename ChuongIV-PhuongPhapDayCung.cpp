// ChuongIV-Phuong phap Day Cung.
// phuong trinh trang 24
#include <iostream>
#include <cmath>
#define EPS 0.001
using namespace std;

// f(x) = 2^x + x -4
float f(float x)
{
	return pow(2,x) + x -4;
}


void thongBaoKetQua(float kq, bool coNghiem = true)
{
	if (coNghiem)
		cout<<"Phuong trinh co nghiem la: "<<kq;
	else cout<<"Phuong trinh khong co nghiem trong khoang nay";
}


float Tinh(float a, float b)
{
	float temp,
		  fx,
		  x = 0,
		  fa = f(a),
		  fb = f(b),
		  count = 0;
	do
	{
		temp = x;
		x = a - (b-a)*fa/(fb - fa);
		fx = f(x);

		if (fa*fx < 0)
		{
			b = x;
			fb = f(b);
		}
		if (fb*fx<0)
		{
			a = x;
			fa = f(a);
		}
		// Xu ly lap vo han
		if (x>b || x< a)
		{
			thongBaoKetQua(0, false);
			return 0;
		}
		// lan dau tien chi co 1 x nen chua can kiem tra dieu kien
		if (count++ == 0) continue;
	}
	while ( fabs(temp - x) > EPS );

	thongBaoKetQua(x);
 	return x;

}

int main()
{
	float a, b;
	cout<< "Nhap khoang nghiem [a, b]: ";
	cin>>a>>b;
	Tinh(a,b);
	return 0;
}
