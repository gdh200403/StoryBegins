//p171 4.1.3.1-用指针完成数组元素的交换
#include <stdio.h>

int main() {
	int i, j;
	int a[10];
	int max, min;
	for (i = 0; i < 10; i++) {
		scanf("%d", a + i);
	}
	max = 0;
	for (i = 0; i < 9; i++) {
		if (*(a + max) <= *(a + i + 1))
			max = i + 1;
		else
			max = max;
	}
	*(a + 9) += *(a + max);
	a[max] = a[9] - a[max];
	*(a + 9) -= *(a + max);
	min = 0;
	for (i = 0; i < 9; i++) {
		if (a[min] >= a[i + 1])
			min = i + 1;
		else
			min = min;
	}
	*(a) += *(a + min);
	a[min] = a[0] - a[min];
	*(a) -= *(a + min);
	for (i = 0; i < 10; i++) {
		printf("%d ", *(a + i));
	}
	return 0;
}