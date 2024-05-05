//p148 3.4.3.6-二分法查找数据
#include <stdio.h>
#define N 10

/*
*功能：二分法查找数据
*参数：a[]:按从小到大的顺序排列好的整数组，n:数组a[]元素个数，x:整型，待查找数据
*返回值：-1：找不到，其他：找到的数在a[]中的位置
*/
int findByHalf(int a[], int n, int x) {
	int low = 0;
	int high = n - 1;
	int middle;
	while (low <= high) {
		middle = (low + high) / 2;
		if (x == a[middle])
			return middle;
		else if (x > a[middle])
			low = middle + 1;//如果x比中间值大，新区间变成右边一半
		else if (x < a[middle])
			high = middle - 1;//如果x比中间值小，新区间变成左边一半
	}
	return -1;//若出循环，说明没找到
}

int main() {
	int a[N];
	int i;
	int x, flag;
	for (i = 0; i < N; i++) {
		a[i] = 2 * i + 1;
	}//按题目要求定义数组
	printf("请输入正整数：\n");
	scanf("%d", &x);
	flag = findByHalf(a, N, x);//调用函数，获取返回值
	if (flag == -1) {
		printf("删除后的结果为：\n未找到待删除数字！");
	} else {
		for (i = flag; i < N; i++) {
			a[i] = a[i + 1];
		}//删除该条数据并将后面数据前移一位
		printf("删除结果为：\n");
		for (i = 0; i < N - 1; i++)
			printf("%d ", a[i]);//输出
	}
	return 0;
}