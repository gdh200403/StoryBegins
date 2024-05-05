//p146 3.4.3.3-数组合并排序
#include <stdio.h>
#define M 5
#define N 5

int main() {
	int a[M + N], b[N];
	int i, j;
	int min;
	printf("请输入数组1:\n");
	for (i = 0; i < M; i++)
		scanf("%d", &a[i]);
	printf("请输入数组2:\n");
	for (i = 0; i < N; i++)
		scanf("%d", &b[i]);
	for (i = M; i < M + N; i++) {
		a[i] = b[i - M];
	}
	for (i = 0; i < M + N - 1; i++) {
		min = i;
		for (j = i + 1; j < M + N; j++) {
			min = a[min] > a[j] ? j : min;
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	printf("合并后的排序结果为：\n");
	for (i = 0; i < M + N; i++)
		printf("%d ", a[i]);
	return 0;
}