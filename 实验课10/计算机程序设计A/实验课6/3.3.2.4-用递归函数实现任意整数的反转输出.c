//p138 3.3.2.4-用递归函数实现任意整数的反转输出
/*
*功能：整数反转输出
*/
#include <stdio.h>
#include <math.h>

/*
*功能：递归函数，递归输出
*参数：decimal:正整数
*返回值：无，在函数体中输出结果
*/
void decimalReverse(unsigned decimal) {
	if (decimal / 10 == 0) {
		printf("%d", decimal);
	} else {
		printf("%d", decimal % 10);
		decimalReverse(decimal / 10);
	}
}

int main() {
	int decimal;
	printf("Plwase enter a decimal:");
	scanf("%d", &decimal);
	printf("%d<->%c", decimal, decimal > 0 ? ' ' : '-');
	decimalReverse(fabs(decimal));
	return 0;
}