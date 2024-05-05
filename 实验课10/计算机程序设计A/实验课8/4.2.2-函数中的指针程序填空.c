//p175 4.2.2-函数中的指针程序填空
#include <stdio.h>
#define SIZE 10

void sort(int arr[], int size) {
	int i, j, t;
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (arr[j] < arr[i]) {
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
}

float getMedian(int *arr, int size) {
	if (size % 2 == 0) {
		return (arr[(size - 1) / 2] + arr[size / 2]) / 2.0;
	} else {
		return arr[size / 2];
	}
}

int main() {
	int i;
	int arr[SIZE];
	printf("请输入%d个整数：", SIZE);
	for (i = 0; i < SIZE; i++)
		scanf("%d", &arr[i]);
	sort(arr, SIZE);
	getMedian(arr, SIZE);
	return 0;
}