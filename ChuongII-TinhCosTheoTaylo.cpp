#include <stdio.h>
#include <math.h>
#define EPS 0.001
float Cos(float x)
{
	float result = 1;
	float operand = 1;
	for (int i = 2; 1 ; i += 2)
	{
		if ( fabs(operand) <= EPS) break;
		operand = -operand* x*x/(i*(i-1));
		result += operand;
	}
 	return result;
}

int main()
{
	float x;
	printf("Nhap x can tinh cos: \n");
	scanf("%f", &x);
	printf("Cos(x) = %0.2f\n", Cos(x) );
	return 0;
}
