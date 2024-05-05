#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "main.h"
#define MAX_SIZE 100

void ShowMenu3(void) {
	printf("返回上级菜单\t\t0\n");
	printf("随机填充数组\t\t1\n");
	printf("手动输入数组\t\t2\n");
	printf("常数填充数组\t\t3\n");
	printf("等差数列填充\t\t4\n");
	return;
}

void FillRandom(unsigned int arr_num, float* array, float min, float max)						//随机填充
{
	if (min > max)return;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < arr_num; i++) {
		array[i] = min + (max - min) * rand() / (float)RAND_MAX;
	}
	return;
}

void FillSameVal(unsigned int arr_num, float* array, float val)			//同值填充
{
	for (int i = 0; i < arr_num; i++)
		array[i] = val;
	return;
}

void FillKeyboard(unsigned int arr_num, float* array)					//键盘输入
{
	int flag = 0;
	printf("请输入%d个数据：\n", arr_num);
	for (int i = 0; i < arr_num; i++) {
		printf("第%d个：", i + 1);
		flag += scanf("%f", &array[i]);
	}
	if (flag == arr_num){
		printf("输入成功！\n");
		return;
	}
	else {
		printf("输入失败！\n");
		return;
	}
}

void FillArithSeq(unsigned int arr_num, float* array, float a0, float d)	//等差填充
{
	for (int i = 0; i < arr_num; i++) {
		array[i] = a0 + i * d;
	}
	return;
}