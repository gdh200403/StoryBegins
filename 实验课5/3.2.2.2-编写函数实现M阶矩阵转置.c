#include <stdio.h>
#define ELE_NUM 3
void setMatrix(int arr[][ELE_NUM]);
void matrixTranspose(int arr[][ELE_NUM]);
void printMatrix(int arr[][ELE_NUM]);

int main(void) {
	int arr[ELE_NUM][ELE_NUM];
	printf("请输入矩阵元素：\n");
	setMatrix(arr[ELE_NUM][ELE_NUM]);
	matrixTranspose(arr[ELE_NUM][ELE_NUM]);
	printf("转置后的矩阵：\n");
	printMatrix(arr[ELE_NUM][ELE_NUM]);
	return 0;
}

void setMatrix(int arr[][ELE_NUM]) {
	int i, j;
	for (i = 0; i < ELE_NUM; i++) {
		for (j = 0; j < ELE_NUM; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
}

void matrixTranspose(int arr[][ELE_NUM]) {
	int i, j, temp;
	for (i = 0; i < ELE_NUM; i++) {
		for (j = i; j < ELE_NUM; j++) {
			temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
}

void printMatrix(int arr[][ELE_NUM]) {
	int i, j;
	for (i = 0; i < ELE_NUM; i++) {
		for (j = 0; j < ELE_NUM; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}