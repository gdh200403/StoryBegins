#include <stdio.h>

int main() {
	int a, b, c, x, y;
	printf("输入整数a=");
	scanf("%d", &a);
	printf("输入整数b=");
	scanf("%d", &b);
	printf("输入整数c=");
	scanf("%d", &c);
	printf("b>c&&b==c的结果是%d\n", b > c && b == c);
	printf("!(a>b)&&!c||1的结果是%d\n", !(a > b) && !c || 1);
	printf("!(x=a)&&(y=b)&&0的结果是%d\n", !(x = a) && (y = b) && 0);
	printf("!(a+b)+c-1&&b+c/2的结果是%d\n", !(a + b) + c - 1 && b + c / 2);
	printf("1&&30%%10>=0&&30%%10<=3的结果是%d\n", 1 && 30 % 10 >= 0 && 30 % 10 <= 3);
	return 0;
}