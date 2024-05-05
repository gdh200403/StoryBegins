#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include "main.h"

void ShowMenu5(void) {
	printf("�����ϼ��˵�\t\t0\n");
	printf("ָ���±����\t\t1\n");
	printf("�������������\t\t2\n");
	return;
}

void InsertIndex(PARA* para, float* array, unsigned int index, float val)	//ָ���±�
{
	int i;
	for (i = para->arr_num; i > index; i--) {
		array[i] = array[i - 1];
	}
	array[index] = val;
	para->arr_num++;
	return;
}

unsigned int InsertOrder(PARA* para, float* array, float val)			//���������в���
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