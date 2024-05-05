#include <stdio.h>
double func_fac(int n);
double func_pow(int dishu, int zhishu);
double func_sum(int n);
double a[100];

double func_fac(int n) {
	if (n > 0)
		return n * func_fac(n - 1);
	else if (n == 0)
		return 1;
}

double func_pow(int dishu, int zhishu) {
	if (zhishu > 0)
		return dishu * func_pow(dishu, zhishu - 1);
	else if (zhishu == 0)
		return 1;
}

double func_sum(int n) {
	if (n > 1)
		return a[n] + func_sum(n - 1);
	else if (n == 1)
		return a[0] + a[1];
}

int main() {
	int n, i;
	int x;
	printf("输入x的值：");
	scanf("%d", &x);
	printf("近似到几阶？");
	scanf("%d", &n);
	printf("e的%d次方的%d阶近似值为：", x, n);
	for (i = 0; i <= n; i++) {
		a[i] = func_pow(x, i) / func_fac(i);
	}
	printf("%f", func_sum(n));
	return 0;
}
