#include <stdio.h>
#include <math.h>.

int main() {
	float x, a = 2.0;
	printf("��һ��������");
	scanf("%f", &x);
	if (x > 0) {
		for (; fabs(a * a - x ) >= 1e-6;) {
			a = a - (a * a - x) / ( 2 * a);
			//printf("%f", a);
		}
		printf("%.6f��ƽ����Ϊ%.6f", x, a);

	} else
		printf("ERROR");
	return 0;
}