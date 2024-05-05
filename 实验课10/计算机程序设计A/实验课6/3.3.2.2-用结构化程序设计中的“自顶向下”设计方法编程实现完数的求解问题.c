//p133 3.3.2.2-用结构化程序设计中的“自顶向下”设计方法编程实现完数的求解问题

/*
*程序功能：输出一定范围内的完数及完数因子列表
*/
#include <stdio.h>
//全局变量，用于统计因子个数
int factorsNum = 0;
//求解数的因子并判断是否为完数的函数原型声明
int isPerfectNumber(int num, int factorList[]);
//输出完数及其因子列表（不包括完数自身）的函数原型声明
void print(int perfectNumber, int factorList[]);

int main() {
	int i, upperNumber, factorList[100] = {0};
	printf("请输入范围上限：");
	scanf("%d", &upperNumber);
	for (i = 1; i <= upperNumber; i++) {
		if (isPerfectNumber(i, factorList) == 1) {
			print(i, factorList);
			factorsNum = 0;
		}
	}
	return 0;
}

/*
*功能：求解数的因子并判断是否为完数
*参数：num：待处理的数，factorList：保存完数的因子
*返回值：若数为完数，返回1，否则返回0
*/
int isPerfectNumber(int num, int factorList[]) {
	int i, j = 0, sum = 0;
	for (i = 1; i < num; i++) {
		if (num % i == 0) {
			factorList[j] = i;
			j++;
			factorsNum++;
		}
	}
	for (i = 0; i < j; i++)
		sum += factorList[i];
	if (num == sum)
		return 1;
	return 0;
}

/*
*功能：输出完数及其因子列表（不包括完数自身）
*返回值：无，在函数体输出
*/
void print(int perfectNumber, int factorList[]) {
	int i;
	printf("%d:", perfectNumber);
	for (i = 0; i < factorsNum; i++) {
		if (factorList[i] != 0)
			printf("%d ", factorList[i]);
	}
	printf("\n");
}