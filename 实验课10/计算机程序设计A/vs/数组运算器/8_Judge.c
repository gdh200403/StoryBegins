#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include "main.h"

void ShowMenu8() {
	printf("�����ϼ��˵�\t0\n");
	printf("�Ƿ�����\t\t1\n");
	printf("�Ƿ���\t\t2\n");
	printf("�Ƿ�ȫ��\t\t3\n");
	return;
}

int IsAsc(unsigned int arr_num, float* array)				//�Ƿ�����
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

int IsDesc(unsigned int arr_num, float* array)				//�Ƿ���
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

int IsAllEqual(unsigned int arr_num, float* array)			//�Ƿ�ȫ��
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