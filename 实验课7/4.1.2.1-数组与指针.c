//p169 4.1.2.1-数组与指针
#include <stdio.h>

int main() {
	int i, x[6], sum = 0;
	printf("请输入6个整数：");
	for (i = 0; i < 6; ++i) {
		scanf("%d", x + i);
		sum += *(x + i);
	}
	printf("Sum=%d", sum);
	return 0;
}