#include <stdio.h>

int main() {
	int i, j, k;
	char a[100];
	for (i = 0; i < 3; i++) {
		printf("����һ���ַ�����");
		scanf("%s", a);
		for (j = 0; j < 100; j++) {
			if (a[j] == '\0')
				break;
		}
		k = j;
		for (j = 0; j < k; j++) {
			if (a[j] >= '0' && a[j] <= '9')
				a[j] = '*';
		}
		printf("����");
		for (j = 0; j < k; j++)
			printf("%c", a[j]);
		printf("\n");
		printf("����");
		for (j = k - 1; j >= 0; j--)
			printf("%c", a[j]);
		printf("\n");

	}
}