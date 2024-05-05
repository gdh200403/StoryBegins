#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include "main.h"

void ShowMenu5(void) {
	printf("返回上级菜单\t\t0\n");
	printf("指定下标添加\t\t1\n");
	printf("有序数组中添加\t\t2\n");
	return;
}

void InsertIndex(PARA* para, float* array, unsigned int index, float val)	//指定下标
{
	int i;
	for (i = para->arr_num; i > index; i--) {
		array[i] = array[i - 1];
	}
	array[index] = val;
	para->arr_num++;
	return;
}

unsigned int InsertOrder(PARA* para, float* array, float val)			//有序数组中插入
{
	int index;
	if (IsAsc(para->arr_num, array)) {
		for (index = 0; index < para->arr_num; index++) {
			if (array[index] > val)
				break;
		}
		InsertIndex(para, array, index, val);
		return index;
	}
	else if (IsDesc(para->arr_num, array)) {
		for (index = 0; index < para->arr_num; index++) {
			if (array[index] < val)
				break;
		}
		InsertIndex(para, array, index, val);
		return index;
	}
	else
		return -1;
}