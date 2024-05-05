#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include "main.h"

void ShowMenu8() {
	printf("返回上级菜单\t0\n");
	printf("是否升序\t\t1\n");
	printf("是否降序\t\t2\n");
	printf("是否全等\t\t3\n");
	return;
}

int IsAsc(unsigned int arr_num, float* array)				//是否升序
{
	int flag = 0;
	for (int i = 0; i < arr_num-1; i++) {
		if (array[i] < array[i + 1])
			flag++;
		else
			break;
	}
	if (flag == arr_num - 1)
		return 1;
	else
		return 0;
}

int IsDesc(unsigned int arr_num, float* array)				//是否降序
{
	int flag = 0;
	for (int i = 0; i < arr_num - 1; i++) {
		if (array[i] > array[i + 1])
			flag++;
		else
			break;
	}
	if (flag == arr_num - 1)
		return 1;
	else
		return 0;
}

int IsAllEqual(unsigned int arr_num, float* array)			//是否全等
{
	int flag = 0;
	for (int i = 0; i < arr_num - 1; i++) {
		if (fabs(array[i] > array[i + 1])<1e5)
			flag++;
		else
			break;
	}
	if (flag == arr_num - 1)
		return 1;
	else
		return 0;
}