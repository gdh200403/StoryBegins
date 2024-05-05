#include <stdio.h>

int main() {
	int i, j, k;
	float a[20];
	printf("从小到大地输入10个数：");
	for (i = 0; i < 10; i++)
		scanf("%f", &a[i]);
	for (j = 0; j < 5; j++) {
		printf("输入要插入的数据：");
		scanf("%f", &a[j + 10]);
		printf("目前有%d个元素：", j + 11);
		for (i = 0; i < j + 11; i++) {
			for (k = i; k > 0; k--) {
				if (a[k] > a[k - 1])
					;
				else {
					a[k] = a[k] + a[k - 1];
					a[k - 1] = a[k] - a[k - 1];
					a[k] = a[k] - a[k - 1];
				}
			}
		}
		for (i = 0; i < j + 11; i++) {
			printf("%10.3f", a[i]);
		}
		printf("\n");
	}

}