#include <stdio.h>

int main() {
	int a, b, c, x, y;
	printf("��������a=");
	scanf("%d", &a);
	printf("��������b=");
	scanf("%d", &b);
	printf("��������c=");
	scanf("%d", &c);
	printf("b>c&&b==c�Ľ����%d\n", b > c && b == c);
	printf("!(a>b)&&!c||1�Ľ����%d\n", !(a > b) && !c || 1);
	printf("!(x=a)&&(y=b)&&0�Ľ����%d\n", !(x = a) && (y = b) && 0);
	printf("!(a+b)+c-1&&b+c/2�Ľ����%d\n", !(a + b) + c - 1 && b + c / 2);
	printf("1&&30%%10>=0&&30%%10<=3�Ľ����%d\n", 1 && 30 % 10 >= 0 && 30 % 10 <= 3);
	return 0;
}