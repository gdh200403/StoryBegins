#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include "main.h"
#define MAX_SIZE 100

int main()
{
	int option;
	PARA* para=(PARA*)malloc(sizeof(PARA));
	para->arr_num = para->deci = para->num_per_row = 0;
	float array[MAX_SIZE] = { 0 };
	for(;;)
	{
		ShowMenu();
		scanf("%d", &option); fflush(stdin);
			switch (option) {
			case 0:
				return 0;
			case 1:
				system("cls");
				Config(para);
				break;
			case 2:
				system("cls");
				PrintArray(para, array);
				break;
			case 3:
				system("cls");
				FillArray(para, array);
				break;
			case 4:
				system("cls");
				Delete(para, array);
				break;
			case 5:
				system("cls");
				Insert(para, array);
				break;
			case 6:
				system("cls");
				Statistics(para, array);
				break;
			case 7:
				system("cls");
				Search(para, array);
				break;
			case 8:
				system("cls");
				Judge(para, array);
				break;
			case 9:
				system("cls");
				Arrange(para, array);
				break;
			default:
				break;
			}
		system("pause");
		system("cls");
	}
	return 0;
}