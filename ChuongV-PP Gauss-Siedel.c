#include <stdio.h>
#include <conio.h>

#define max 20
#define exp 0.001
/**
* Note: Index of array begin with 1
* not begin with 0
**/

void NhapMang(float a[][max], int n);
void XuatNghiem(float *a, int n);
void TimNghiem(float a[][max], int n);


int main()
{
	int n;
	float a[max][max];
	printf("Nhap n: \n");
	scanf("%d", &n);

	NhapMang(a,n);
	TimNghiem(a,n);

	getch();
	return 0;
}

void NhapMang(float a[][max], int n)
{
	printf("Nhap vao ma tran: \n");
	int i,j;
	for (i=1; i <= n; i++)
		for(j=1; j<=n+1;j++)
			scanf("%f",&a[i][j]);
}

void TimNghiem(float a[][max], int n)
{
	float x[n+1], y[n+1];
	int t,i,j;
	float s;
	do
	{
		t = 0;
		for(i=1;i<=n;i++)
		{
			s = 0;
			for (j=1; j<= n; j++)
				if (i !=j) s = s+a[i][j]*x[j];
			y[i]= (a[i][n+1] - s)/a[i][i];
			// Keep loop
			if (fabs(y[i] - x[i]) >= exp) 
				t = 1;
			x[i] = y[i];
		}
	}
	while (t);
	XuatNghiem(x,n);
}

void XuatNghiem(float *a, int n)
{
	int i;
	printf("Vecto nghiem:\n");
	for(i=1;i<=n;i++)
		printf("%0.2f  ",a[i]);
}
