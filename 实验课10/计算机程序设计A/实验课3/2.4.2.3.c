#include <stdio.h>

int main() {
	int a[100];//较大数组
	int n;//输入数组实际有多少个元素有值
	int i, j, t; //循环变量，临时变量
	printf("有几个数（1~100）：");
	scanf("%d", &n);
	printf("输入%d个数：", n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	//1.将数组中的元素逆序存放
	for (i = 0; i < n / 2; i++) {
		t = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = t;
	}
	printf("逆序存储后的数组元素依次为：\n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	//2.交换任意两个数组元素，注意在有限的范围
	while (1) { //一直循环，需要通过内部break语句结束循环
		printf("\n输入要交换的两个元素位置（0~%d）：", n);
		scanf("%d%d", &i, &j);
		if (0 <= i && i <= n - 1 && 0 <= j && j <= n - 1) {
			a[i] += a[j];
			a[j] = a[i] - a[j];
			a[i] = a[i] - a[j];
		} else
			break;
		for (i = 0; i < n; i++)
			printf("%d ", a[i]);
	}
	return 0;

}