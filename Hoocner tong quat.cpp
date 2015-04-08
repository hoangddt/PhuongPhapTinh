#include<stdio.h>
#include<conio.h>
void Init(float a[], int n){
	for(int i = 0; i <= n; i++){
		scanf("%f", &a[i]);
	}
}
void Hoocner(float a[], int n, float c){
	int k;
	int j;
	for(k = n; k > 0; k--){
		for(j = 1; j <= k; j++){
			a[j] = a[j-1]*c + a[j];
		}
	}
}
void Out(float a[], int n, float c){
	printf("he so cua P(y + %.3f) :", c);
	for(int i = 0; i <= n; i++)
		printf("\t%.2f", a[i]);
}
main(){
	int n;
	float c;
	float a[n+1];
	printf("n : ");
	scanf("%d", &n);
	Init(a, n);
	printf("c : ");
	scanf("%f", &c);
	Hoocner(a, n, c);
	Out(a,n,c);
	getch();
	return 0;
}
