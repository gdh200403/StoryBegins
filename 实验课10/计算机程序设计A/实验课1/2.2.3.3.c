#include <stdio.h>
#define Reset a=a1,b=b1,c=c1

int main() {
	int a, b, c, a1, b1, c1;
	printf("��������a=");
	scanf("%d", &a1);
	printf("��������b=");
	scanf("%d", &b1);
	printf("��������c=");
	scanf("%d", &c1);
	Reset;
	printf("a+=a+b�Ľ����%d\n", a += a + b);
	Reset;
	printf("a*=b%%c�Ľ����%d\n", a *= b % c);
	Reset;
	printf("a/=c-a�Ľ����%d\n", a /= c - a);
	Reset;
	printf("a+=a-=a*=a�Ľ����%d\n", a += a -= a *= a);
	Reset;
	printf("a=(a=++b,a+5,a/5)�Ľ����%d\n", a = (a = ++b, a + 5, a / 5));
	Reset;
	printf("(a>=b>=2)?1:0�Ľ����%d\n", (a >= b >= 2) ? 1 : 0);
	return 0;
}