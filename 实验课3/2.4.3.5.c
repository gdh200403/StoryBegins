#include <stdio.h>

int main() {
	int i, j, k;
	float a[20];
	printf("��С���������10������");
	for (i = 0; i < 10; i++)
		scanf("%f", &a[i]);
	for (j = 0; j < 5; j++) {
		printf("����Ҫ��������ݣ�");
		scanf("%f", &a[j + 10]);
		printf("Ŀǰ��%d��Ԫ�أ�", j + 11);
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