#include <stdio.h>

int main() {
	char c;
	unsigned short s;
	double d;
	printf("Input one char:");
	c = getchar();
	printf("ASCII:%d\n", c);
	printf("Input one short:");
	scanf("%d", &s);
	printf("unsigned short:%u\n", s);
	printf("Input one double:");
	scanf("%f", &d);
	printf("double:%g\n", d); //自动选择小数或指数小数输出
	return 0;

}