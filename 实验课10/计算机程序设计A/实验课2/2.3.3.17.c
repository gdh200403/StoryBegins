#include <stdio.h>
#include <math.h>.

int main() {
	float x, a = 2.0;
	printf("输一个正数：");
	scanf("%f", &x);
	if (x > 0) {
		for (; fabs(a * a - x ) >= 1e-6;) {
			a = a - (a * a - x) / ( 2 * a);
			//printf("%f", a);
		}
		printf("%.6f的平方根为%.6f", x, a);

	} else
		printf("ERROR");
	return 0;
}