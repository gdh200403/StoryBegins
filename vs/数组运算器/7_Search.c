#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include "main.h"

void ShowMenu7(void) {
	printf("返回上级菜单\t\t0\n");
	printf("普通查找\t\t1\n");
	printf("二分查找\t\t2\n");
	return;
}

unsigned int SeqSearch(unsigned int arr_num, float* array, float val)		//普通查找
{
	int flag = 0; int i;
	for ( i = 0; i < arr_num; i++) {
		if (fabs(val - array[i]) < 1e-5) {
			flag++;
			break;
		}
	}
	if (flag)
		return i;
	else
		return -1;
}

unsigned int BiSearch(unsigned int arr_num, float* array, float val)		//二分查找
{
	if (IsAsc(arr_num, array)) {
		int left=0, right=arr_num-1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (val < array[mid])
				right = mid - 1;
			else if (val > array[mid])
				left = mid + 1;
			else if (val == array[mid])
				goto END_1;
		}
		return -1;
	END_1:
		return mid;
	}
	else if (IsDesc(arr_num, array)) {
		int left = 0, right = arr_num - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (val > array[mid])
				right = mid - 1;
			else if (val < array[mid])
				left = mid + 1;
			else if (val == array[mid])
				goto END_2;
		}
		return -1;
	END_2:
		return mid;
	}
	else
		return -2;
}