#include<stdio.h>
#include<conio.h>
#include<math.h>
float test_cos(float x){
	float t = 1;
	float q = 1;
	int temp = 1;
	for(int i = 1; i > 0; i++){
		if( fabs(t) <= 0.001) break;
		t = -t*x*x/(2*i*(2*i-1));
		q = q + t;
	}
	return q;
}
main(){
	float x;
	printf("x : "); scanf("%f", &x);
	printf("cos(x) = %.3f", test_cos(x));
	getch();
}
