/*=====================================================
=            Bang noi suy Ayken - Trang 48            =
=====================================================*/

#include <stdio.h>
#define max 10

void NhapFx(float *x,float *y, int n);
float TimKQ(float *x, float *y, int n, float c);

int main()
{
	int n;
	float x[max], y[max], c;

	// n is last index, not numbers of elements
	printf("Nhap n: \n");
	scanf("%d",&n);

	printf("Nhap c: \n");
	scanf("%f",&c);

	NhapFx(x,y,n);


	float kq = TimKQ(x, y, n, c);
	printf("Ket Qua la: %0.2f\n", kq);
	return 0;
}

void NhapFx(float *x,float *y, int n)
{
	int i;
	printf("Nhap day x:\n");
	for(i=0; i<=n;i++)
		scanf("%f", &x[i]);

	printf("Nhap day y:\n");
	for(i=0; i<=n;i++)
		scanf("%f", &y[i]);
}

float TimKQ(float *x, float *y, int n, float c)
{
	float w = 1,
		  s =0,
		  d;
	int i,j;

	for(i=0;i<=n;i++)
	{
		w = w*(c-x[i]);
		d = c - x[i];
		for(j = 0; j<=n; j++)
			if (j!=i)
				d = d*(x[i] - x[j]);
		s = s + y[i]/d;
	}

	return w*s;
}