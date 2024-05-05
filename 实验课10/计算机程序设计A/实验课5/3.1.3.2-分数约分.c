#include <stdio.h>
#include <math.h>

int panduan(int n1, float t1, int n2, float t2) {
	if (fabs(n1 - t1) < 1e-6 && fabs(n2 - t2) < 1e-6 && n2 != 0)
		return 1;
	else
		return 0;
}


int main() {
	int n1, n2, n3, n4;
	float t1, t2;
	int i, min;
	printf("请按顺序输入分子分母：\n");
	for (;;) {
		printf("输入：");
		scanf("%f%f", &t1, &t2);
		n1 = (int)t1, n2 = (int)t2;
		if (panduan(n1, t1, n2, t2) == 0)
			printf("不合法的输入！\n");
		else {
			min = fabs(n1 ) > fabs(n2) ? fabs(n2 ) : fabs(n1 );
			n3 = n1, n4 = n2;
			for (i = 2; i <= min; i++) {
				if (n3 % i == 0 && n4 % i == 0) {
					n3 /= i, n4 /= i;
					min = fabs(n3) > fabs(n4) ? fabs(n4 ) : fabs(n3 );
					i = 1;
				}
			}
			if (n3 == n1 && n2 == n4)
				printf("输出:%d/%d为最简分数\n", n1, n2);
			else {
				if (n3 * n4 < 0)
					printf("输出:%d/%d=-%d/%d\n", n1, n2, (int)fabs(n3), (int)fabs(n4));
				else
					printf("输出:%d/%d=%d/%d\n", n1, n2, (int)fabs(n3), (int)fabs(n4));
			}
		}
	}
	return 0;
}