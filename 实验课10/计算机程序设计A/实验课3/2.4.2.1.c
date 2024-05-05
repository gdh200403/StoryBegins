#include <stdio.h>

int main() {
	int a[10];
	int i;
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]); //此时从键盘可一行输入10个空格分隔整数，或分成多行输入，直到输入10个整数
	for (i = 9; i >= 0; i--)
		printf("%d ", a[i]);
	return 0;
}