#include <stdio.h>
#define Reset a=a1,b=b1,c=c1

int main() {
	int a, b, c, a1, b1, c1;
	printf("输入整数a=");
	scanf("%d", &a1);
	printf("输入整数b=");
	scanf("%d", &b1);
	printf("输入整数c=");
	scanf("%d", &c1);
	Reset;
	printf("a+=a+b的结果是%d\n", a += a + b);
	Reset;
	printf("a*=b%%c的结果是%d\n", a *= b % c);
	Reset;
	printf("a/=c-a的结果是%d\n", a /= c - a);
	Reset;
	printf("a+=a-=a*=a的结果是%d\n", a += a -= a *= a);
	Reset;
	printf("a=(a=++b,a+5,a/5)的结果是%d\n", a = (a = ++b, a + 5, a / 5));
	Reset;
	printf("(a>=b>=2)?1:0的结果是%d\n", (a >= b >= 2) ? 1 : 0);
	return 0;
}