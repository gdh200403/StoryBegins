#include <stdio.h>

int main() {
	float x, y;
	int a, b;
	printf("3.5+1/2+56%%10=%f\n", 3.5 + 1 / 2.0 + 56 % 10);
	printf("Input a and calculate a++*1/3\n");
	printf("��������a=");
	scanf("%d", &a);
	printf("%f\n", (a++) / 3.0);

	printf("Input a,x,y and calculate x+a%%3*(int)(x+y)%%2/4\n");
	printf("��������a=");
	scanf("%d", &a);
	printf("����ʵ��x=");
	scanf("%f", &x);
	printf("����ʵ��y=");
	scanf("%f", &y);
	printf("%f\n", x + a % 3 * (int)(x + y) % 2 / 4.0);

	printf("Input a,b,x,y and calculate (float)(a+b) / 2 + (int)x %% (int)y\n");
	printf("��������a=");
	scanf("%d", &a);
	printf("��������b=");
	scanf("%d", &b);
	printf("����ʵ��x=");
	scanf("%f", &x);
	printf("����ʵ��y=");
	scanf("%f", &y);
	printf("%f\n", (float)(a + b) / 2 + (int)x % (int)y);
}