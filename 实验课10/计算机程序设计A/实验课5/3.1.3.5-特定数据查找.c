#include <stdio.h>

int main() {
	int i, a, flag = 0;
	scanf("%d", &a);
	for (i = 100; i < 1000; i++) {
		if (i / 100 + (i % 100) / 10 + i % 10 == a) {
			printf("%d", i);
			flag++;
			if (flag % 5 == 0) {
				printf("\n");
			} else
				printf(",");

		}
	}
	printf("\n���ϸ�λ������֮��Ϊ%d������������%d", a, flag);
	return 0;
}