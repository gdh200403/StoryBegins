#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "main.h"
#define MAX_SIZE 100

void ShowMenu3(void) {
	printf("�����ϼ��˵�\t\t0\n");
	printf("����������\t\t1\n");
	printf("�ֶ���������\t\t2\n");
	printf("�����������\t\t3\n");
	printf("�Ȳ��������\t\t4\n");
	return;
}

void FillRandom(unsigned int arr_num, float* array, float min, float max)						//������
{
	if (min > max)return;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < arr_num; i++) {
		array[i] = min + (max - min) * rand() / (float)RAND_MAX;
	}
	return;
}

void FillSameVal(unsigned int arr_num, float* array, float val)			//ֵͬ���
{
	for (int i = 0; i < arr_num; i++)
		array[i] = val;
	return;
}

void FillKeyboard(unsigned int arr_num, float* array)					//��������
{
	int flag = 0;
	printf("������%d�����ݣ�\n", arr_num);
	for (int i = 0; i < arr_num; i++) {
		printf("��%d����", i + 1);
		flag += scanf("%f", &array[i]);
	}
	if (flag == arr_num){
		printf("����ɹ���\n");
		return;
	}
	else {
		printf("����ʧ�ܣ�\n");
		return;
	}
}

void FillArithSeq(unsigned int arr_num, float* array, float a0, float d)	//�Ȳ����
{
	for (int i = 0; i < arr_num; i++) {
		array[i] = a0 + i * d;
	}
	return;
}