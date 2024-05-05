#include <stdio.h>

int main() {
	int a[100];
	int n, i, t, ti;
	printf("有几个整数？");
	scanf("%d", &n);
	printf("输入%d个整数：", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}//输入整数列
	t = a[0];
	for (i = 0; i < n ; i++) {
		if (a[i] < t)
			;
		else
			t = a[i];
	}//得到最大值t
	for (i = 0; i < n; i++) {
		if (t == a[i])
			break;
	}
	ti = i;//获得值为t的第一个数在数列中的位置
	for (i = 0; i < n - 1; i++) {
		if (i >= ti)
			a[i] = a[i + 1]	;
	}//该数后的数前移一位
	a[n - 1] = t;//该数放在最后一位
	printf("最大数位于最后：");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}//输出新数列
	return 0;


}