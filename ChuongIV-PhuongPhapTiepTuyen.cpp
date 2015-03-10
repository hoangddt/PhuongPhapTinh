// ChuongIV-Phuong phap Tiep Tuyen.
// phuong trinh trang 23
#include <iostream>
#include <cmath>
#define EPS 0.001
using namespace std;

// f(x) = x^3 +x -5
float f(float x)
{
	return pow(x,3) + x -5;
}

float fdh(float x)
{
	return 3*pow(x,2)+1;
}


void thongBaoKetQua(float kq, bool coNghiem = true)
{
	if (coNghiem)
		cout<<"Phuong trinh co nghiem la: "<<kq;
	else cout<<"Phuong trinh khong co nghiem trong khoang nay";
}


float Tinh(float a, float b, float x)
{
	float temp;
	do
	{
		temp = x;
		x = temp - f(temp)/fdh(temp);
		// Xu ly lap vo han
		if (x>b || x< a)
		{
			thongBaoKetQua(0, false);
			return 0;
		}
	}
	while ( fabs(temp - x)>EPS );

	thongBaoKetQua(x);
 	return x;

}

int main()
{
	float a, b, x;
	cout<< "Nhap khoang nghiem [a, b]: ";
	cin>>a>>b;
	cout<<"Chon gia tri x = ";
	cin>>x;
	Tinh(a,b,x);
	return 0;
}