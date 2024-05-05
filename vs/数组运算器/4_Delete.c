#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include "main.h"
#define MAX_SIZE 100

void ShowMenu4(void) {
	printf("返回上级菜单\t\t0\n");
	printf("指定下标删除\t\t1\n");
	printf("指定数值删除\t\t2\n");
	printf("指定下标范围删除\t3\n");
	return;
}

int DeleteIndex(PARA* para, float* array, unsigned int index)			//指定下标
{
	if (index <= para->arr_num) {
		if (index != MAX_SIZE) {
			for (int i = index; i < para->arr_num; i++) {
				array[i] = array[i + 1];
			}
		}
		else
			array[index] = 0;
		para->arr_num--;
		return 0;//删除成功返回0
	}
	else {
		return -1;//删除失败返回-1
	}
}

int DeleteValue(PARA* para, float* array, float val)			//指定数值,返回值为删除元素的个数
{
	int i;
	int count=0; int record[MAX_SIZE];
	for (i = 0; i < para->arr_num; i++) {
		if (fabs(val - array[i]) < 1e-5)
		{
			record[count] = i;
			count++;
		}
	}
		for (i = 1; i < count; i++)
			record[i] -= i;
		for (i = 0; i < count; i++) {
			DeleteIndex(para, array, record[i]);
		}
	return count;
}

void DeleteRange(PARA* para, float* array, unsigned int left, unsigned int right)	//指定下标区间
{
	if (left >= right || left<0 || right>para->arr_num)
		return;
	else {
		for (int i = 0; i < right - left + 1; i++) {
			DeleteIndex(para, array, left);
		}
	}
	return;
}