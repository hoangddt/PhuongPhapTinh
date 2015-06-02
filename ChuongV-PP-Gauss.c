/*=========================================
=            Phuong Phap Gauss            =
=========================================*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 20
/**
* Note: Index of array begin with 1
* not begin with 0
**/
void NhapMang(float a[][max], int n);
void BienDoi(float a[][max], int n);
void HoanDoiDong(float a[][max], int i, int j,int n);
float *TimNgiem(float a[][max], int n);
void XuatNghiem(float *a, int n);
void die(const char* message);

int main()
{
	int n, a[max][max];
	printf("Nhap n: \n");
	scanf("%d", &n);

	NhapMang(a,n);

	BienDoi(a,n);
	float *x = TimNgiem(a,n);
	XuatNghiem(x,n);
	free(x);
	getch();
}

void NhapMang(float a[][max], int n)
{
	printf("Nhap vao ma tran: \n");
	int i,j;
	for (i=1; i <= n; i++)
		for(j=1; j<=n+1;j++)
			scanf("%f",&a[i][j]);
}

void BienDoi(float a[][max], int n)
{
	int i,j,k; // counter inside loops
	float m;
	// Scan row from 1 to n-1, each loop will be alter the next row
	for (i = 1; i<n; i++)
	{
		// Find and check row
		if (a[i][i]==0)
		{
			for( j=i+1; j<=n;j++)
				if (a[j][i] != 0) break;
			if (j<=n) 
			{
				HoanDoiDong(a,i,j,n);
			}
			else die("Du lieu nhap vao khong hop le");
		}

		// Alter the next row
		for (j=i+1; j<=n; j++)
		{
			m = - a[j][i] / a[i][i];
			for(k = i; k<=n+1;k++)
				a[j][k] = a[j][k]*m;
		}
	}
}

void HoanDoiDong(float a[][max], int i, int j, int n)
{
	int index;
	float temp;
	// each row has n+1 elements
	for(index =1; index <= n+1;index++)
	{
		temp = a[i][index];
		a[i][index] = a[j][index];
		a[j][index] = temp;
	}
}

float *TimNgiem(float a[][max], int n)
{
	float *kq = (float*)malloc((n+1)*sizeof(float));
	int i,j;
	float s;
	for(i=n; i>=1; i--)
	{
		s = 0;
		for(j=i+1; j<=n;j++)
			s = s + a[i][j]*kq[j];
		kq[i] = (a[i][n+1] - s) / a[i][i];
	}

	return kq;
}

void XuatNghiem(float *a, int n)
{
	int i;
	printf("Vecto nghiem:\n");
	for(i=1;i<=n;i++)
		printf("%0.2f  ",a[i]);
}
void die(const char* message)
{
	printf("%s\n",message);
	exit(EXIT_FAILURE); // Unable to find variables
}
