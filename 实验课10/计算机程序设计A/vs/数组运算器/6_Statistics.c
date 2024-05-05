#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include "main.h"

void ShowMenu6(void) {
	printf("�����ϼ��˵�\t0\n");
	printf("���ֵ\t\t1\n");
	printf("��Сֵ\t\t2\n");
	printf("ƽ��ֵ\t\t3\n");
	printf("����\t\t4\n");
	printf("������\t\t5\n");
	return;
}

float Max(unsigned int arr_num, float* array)				//���ֵ
{
	float max=array[0];
	for (int i = 1; i < arr_num; i++) {
		max = max > array[i] ? max : array[i];
	}
	return max;
}

float Min(unsigned int arr_num, float* array)				//��Сֵ
{
	float min = array[0];
	for (int i = 0; i < arr_num; i++) {
		min = min < array[i] ? min : array[i];
	}
	return min;
}

float Average(unsigned int arr_num, float* array)			//ƽ��ֵ
{
	float ave=0;
	for (int i = 0; i < arr_num; i++) {
		ave += array[i];
	}
	ave /= arr_num;
	return ave;
}

float Variance(unsigned int arr_num, float* array)			//����
{
	float var;
	const float ave = Average(arr_num, array);
	float sum_pow=0;
	for (int i = 0; i < arr_num; i++) {
		sum_pow += pow(array[i] - ave, 2);
	}
	var = sum_pow / arr_num;
	return var;
}

float StdDev(unsigned int arr_num, float* array)			//������
{
	float std;
	std = sqrt(Variance(arr_num, array));
	return std;
}