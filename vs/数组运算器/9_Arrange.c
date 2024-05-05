#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "main.h"
#define MAX_SIZE 100
extern void ShowMenu9_1();

void ShowMenu9(void) {
	printf("返回上级菜单\t\t0\n");
	printf("排序\t\t\t1\n");
	printf("逆置\t\t\t2\n");
	printf("左旋\t\t\t3\n");
	printf("右旋\t\t\t4\n");
	return;
}

void Sort(unsigned int arr_num, float* array)				//排序
{
	system("cls");
	int option;
	ShowMenu9_1();
	printf("ps:默认升序排列\n");
	scanf("%d", &option);
	switch (option) {
	case 0:
		return;
	case 1:
		BubbleSort(arr_num, array);
		printf("使用冒泡排序对您的数组排序成功！\n");
		break;
	case 2:
		SelectSort(arr_num, array);
		printf("使用选择排序对您的数组排序成功！\n");
		break;
	case 3:
		InsertSort(arr_num, array);
		printf("使用插入排序对您的数组排序成功！\n");
		break;
	case 4:
		ExchangeSort(arr_num, array);
		printf("使用交换排序对您的数组排序成功！\n");
		break;
	default:
		break;
	}
	return;
}

void ShowMenu9_1(void) {
	printf("返回上级菜单\t\t0\n");
	printf("冒泡排序\t\t1\n");
	printf("选择排序\t\t2\n");
	printf("插入排序\t\t3\n");
	printf("交换排序\t\t4\n");
	return;
}

void BubbleSort(unsigned int arr_num, float* array)			//冒泡排序
{
	int i, j;
	float temp;
	for (i = arr_num-1; i >0; i--) {
		for (j = 0; j < i; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	return;
}

void SelectSort(unsigned int arr_num, float* array)			//选择排序
{
	int min;
	int i, j;
	float temp;
	for (i = 0; i < arr_num; i++) {
		min = i;
		for (j = i; j < arr_num; j++) {
			if (array[min] > array[j])
				min = j;
		}
		if(min!=i){
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
	return;
}

void InsertSort(unsigned int arr_num, float* array)			//插入排序
{
	int i, j;
	float temp;
	for (i = 0; i < arr_num - 1; i++) {
		for (j = i; j >= 0; j--) {
			if (array[i + 1] > array[j]) {
				temp = array[i+1];
				array[i+1] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	return;
}

void ExchangeSort(unsigned int arr_num, float* array)			//交换排序
{
	for (int i = 0; i < arr_num - 1; i++) {
		for (int j = i + 1; j < arr_num; j++) {
			if (array[j] < array[i]) {
				float temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
	return;
}

void Reverse(unsigned int arr_num, float* array)			//逆置
{
	float mirror[MAX_SIZE];
	for (int i = 0; i < arr_num; i++)
		mirror[i] = array[i];
	for (int i = 0; i < arr_num; i++)
		array[i] = mirror[arr_num - i - 1];
	return;
}

void RotateLeft(unsigned int arr_num, float* array, unsigned int delta)			//左旋
{
	float mirror[MAX_SIZE];
	for (int i = 0; i < arr_num; i++)
		mirror[i] = array[i];
	for (int i = 0; i < arr_num; i++)
		array[i] = mirror[(i+delta)%arr_num];
	return;
}

void RotateRight(unsigned int arr_num, float* array, unsigned int delta)		//右旋
{
	float mirror[MAX_SIZE];
	for (int i = 0; i < arr_num; i++)
		mirror[i] = array[i];
	for (int i = 0; i < arr_num; i++)
		array[i] = mirror[((i - delta) % arr_num + arr_num)% arr_num];
	return;
}