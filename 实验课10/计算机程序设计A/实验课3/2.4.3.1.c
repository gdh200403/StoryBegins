#include <stdio.h>

int main() {
	int n, i, j;
	int a[50] = {0, 1, 1};
	for (i = 3; i < 50; i++)
		a[i] = a[i - 1] + a[i - 2];
	printf("������Fibonacci���е�������");
loop:
	scanf("%d", &n);
	if (3 <= n && n <= 45) {
		for (i = 0; i < n; i++) {
			printf("%8d", a[i]);
			if ((i + 1) % 8 == 0)
				printf("\n");
		}
	} else {
		printf("��������������������������\n�����µ�������1~50����");
		goto loop;
	}
}