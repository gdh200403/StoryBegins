//p169 4.1.2.1-������ָ��
#include <stdio.h>

int main() {
	int i, x[6], sum = 0;
	printf("������6��������");
	for (i = 0; i < 6; ++i) {
		scanf("%d", x + i);
		sum += *(x + i);
	}
	printf("Sum=%d", sum);
	return 0;
}