#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include "main.h"
#define MAX_SIZE 100

void ShowMenu(void) //0��ʾ�˵�
{
	printf("***��ӭʹ������������!***\n");
	printf("����ϵͳ����\t\t1\n");
	printf("��ʾ����\t\t2\n");
	printf("������������\t\t3\n");
	printf("ɾ������\t\t4\n");
	printf("������Ԫ��\t\t5\n");
	printf("ͳ��\t\t\t6\n");
	printf("����\t\t\t7\n");
	printf("�ж�\t\t\t8\n");
	printf("��������Ԫ��\t\t9\n");
	printf("�˳�����\t\t0\n");
	printf("*************************\n");
	printf("�����Ӧ������ִ����Ӧ���ܣ�\n");
	return;
}

void Config(PARA* para) //1����ϵͳ����
{
	printf("����������������������\n1.������������Ԫ�ظ�����1~%d��:\n", MAX_SIZE);
	scanf("%d", &para->arr_num); fflush(stdin);
	para->arr_num %= MAX_SIZE;//���ݲ��Ϸ�ʱĬ�϶�MAX_SIZE����
	printf("2.���ʱÿ����ʾԪ�ظ�����\n");
	scanf("%d", &para->num_per_row); fflush(stdin);
	printf("3.���ʱÿ��Ԫ�صı���С����λ����\n");
	scanf("%d", &para->deci); fflush(stdin);
	printf("ϵͳ������ʼ����ϣ���ǰ�������������ݣ�");
	return;
}

void PrintArray(PARA* para, float* array)		//2��ʾ����
{
	int i;
	char format[6] = "%8.3f";
	if (!(para->arr_num && para->deci && para->num_per_row)) {
		printf("��������ϵͳ������\n");
		return;
	}
	format[3] = '0' + para->deci;
	printf("�����������£�\n");
	for (i = 0; i < para->arr_num; i++) {
		printf(format, array[i]);
		if ((i+1) % para->num_per_row == 0)
			printf("\n");
	}
	if (i % para->num_per_row !=0)
		printf("\n");
	return;
}

void FillArray(PARA* para, float* array)		//3������������
{
	int option;
	unsigned int n = para->arr_num;
	ShowMenu3();
	scanf("%d", &option);fflush(stdin);
	switch (option) {
		case 0:
			return;
		case 1:
		{
			float min, max;
			system("cls");
			printf("��������������ɵ��������Ҷ˵�:\n");
			int count = scanf("%f%f", &min, &max);fflush(stdin);
			if (count != 2 || min >= max)
				return;
			FillRandom(n, array, min, max);
			printf("���������������[%f,%f]��������ϣ�\n", min, max);
			break;
		}
		case 2:
			system("cls");
			FillKeyboard(n, array);
			break;
		case 3:
		{
			float val;
			system("cls");
			printf("��������Ҫ�����������ĳ�ֵ��\n");
			scanf("%f", &val); fflush(stdin);
			FillSameVal(n, array, val);
			printf("����������ݳ�ֵ%fȫ�������ϣ�\n", val);
			break;
		}
		case 4:
		{
			float a0, d;
			system("cls");
			printf("�������������\n");
			scanf("%f", &a0); fflush(stdin);
			printf("���������鹫�\n");
			scanf("%f", &d); fflush(stdin);
			FillArithSeq(n,array, a0, d);
			printf("���������������%.3f,����%.3fȫ�������ϣ�\n",a0,d);
			break;
		}
		default:
			return;
		}
	return;
}

void Delete(PARA* para, float* array)			//4ɾ��
{
	int option;
	unsigned int n = para->arr_num;
	if (!(para->arr_num && para->deci && para->num_per_row)) {
		printf("��������ϵͳ������\n");
		return;
	}
	ShowMenu4();
	scanf("%d", &option); fflush(stdin);
	switch (option) {
	case 0:
		return;
	case 1:
	{
		system("cls");
		unsigned int index;
		printf("��������Ҫɾ��Ԫ�ص��±꣺\n");
		scanf("%d", &index); fflush(stdin);
		if (!DeleteIndex(para, array, index))
			printf("ɾ���ɹ���\n");
		else
			printf("ɾ��ʧ�ܣ�δ�ҵ����±�Ԫ��\n");
		break;
	}
	case 2:
	{
		system("cls");
		float val;
		printf("��������Ҫɾ��Ԫ�ص�ֵ��\n");
		scanf("%f", &val); fflush(stdin);
		printf("ɾ����%d��Ԫ�أ�", DeleteValue(para, array, val));
		break;
	}
	case 3:
	{
		system("cls");
		int left, right;
		printf("��������Ҫɾ���������±����Ҷ˵�:\n");
		int count = scanf("%d%d", &left, &right); fflush(stdin);
		if (count != 2 || left >= right)
			return;
		DeleteRange(para, array, left, right);
		printf("ɾ���ɹ���\n");
		break;
	}
	default:
		break;
	}
	return;
}

void Insert(PARA* para, float* array)			//5������Ԫ��
{
	if (!(para->arr_num && para->deci && para->num_per_row)) {
		printf("���ȳ�ʼ�����飡\n");
		return;
	}
	if (para->arr_num == MAX_SIZE) {
		printf("������������ɾ������Ԫ�غ�����ӣ�\n");
		return;
	}
	int option;
	ShowMenu5();
	scanf("%d", &option); fflush(stdin);
	switch (option) {
	case 0:
		return;
	case 1:
	{
		system("cls");
		int index;
		float val;
		printf("��������Ҫ�������Ԫ�ص��±꣺\n");
		scanf("%d", &index); fflush(stdin);
		if (index > para->arr_num) {
			printf("�±곬�����鷶Χ��\n");
			return;
		}
		printf("��������Ҫ�������Ԫ�ص�ֵ��\n");
		scanf("%f", &val); fflush(stdin);
		InsertIndex(para, array, index, val);
		printf("�ѳɹ��������±�Ϊ%d����������%f��\n", index, val);
		break;
	}
	case 2:
	{
		system("cls");
		if (IsAsc(para->arr_num, array) == 0 && IsDesc(para->arr_num, array) == 0) {
			printf("�������鲻���������飡��Ҫʹ�ô˹��ܣ���������\n");
			return;
		}
		else {
			float val;
			unsigned int index;
			printf("��������Ҫ�������Ԫ�ص�ֵ��\n");
			scanf("%f", &val); fflush(stdin);
			index=InsertOrder(para, array, val);
			printf("�ɹ�����������������±�Ϊ%d����������%f��\n", index, val);
			break;
		}
	}
	default:
		break;
	}
	return;
}

void Statistics(PARA* para, float* array)		//6ͳ��
{
	int option;
	unsigned int n = para->arr_num;
	ShowMenu6();
	scanf("%d", &option); fflush(stdin);
	switch (option) {
	case 0:
		return;
	case 1:
		system("cls");
		printf("���ֵ��%f\n", Max(n, array));
		PrintArray(para, array);
		break;
	case 2:
		system("cls");
		printf("��Сֵ��%f\n", Min(n, array));
		PrintArray(para, array);
		break;
	case 3:
		system("cls");
		printf("ƽ��ֵ��%f\n", Average(n, array));
		PrintArray(para, array);
		break;
	case 4:
		system("cls");
		printf("���%f\n", Variance(n, array));
		PrintArray(para, array);
		break;
	case 5:
		system("cls");
		printf("�����%f\n", StdDev(n, array));
		PrintArray(para, array);
		break;
	default:
		break;
	}
	return;
}

void Search(PARA* para, float* array)			//7����
{
	int option;
	unsigned int n = para->arr_num;
	ShowMenu7();
	scanf("%d", &option); fflush(stdin);
	float val;
	printf("��������Ҫ���ҵ�Ԫ�ص�ֵ��\n");
	scanf("%f", &val); fflush(stdin);
	switch (option) {
	case 0:
		return;
	case 1: {
		unsigned int index = SeqSearch(n, array, val);
		if (index == -1) {
			printf("δ�ҵ���Ԫ�أ�\n");
		}
		else {
			printf("�����ҵ�Ԫ���±�Ϊ%d\n", index);
		}
		break;
	}
	case 2:
	{
		unsigned int index = BiSearch(n, array, val);
		if (index == -1)
			printf("δ�ҵ���Ԫ�أ�\n");
		else if(index==-2)
			printf("�����ϸ��������飡�޷�ʹ�ö��ֲ��ң�\n");
			
		else
			printf("�����ҵ�Ԫ���±�Ϊ%d\n", index);
		break;
	}
	default:
		break;
	}
	return;
}

void Judge(PARA* para, float* array)			//8�ж�
{
	int option;
	unsigned int n = para->arr_num;
	int flag;
	ShowMenu8();
	scanf("%d", &option); fflush(stdin);
	switch (option) {
	case 0:
		return;
	case 1:{
		flag = IsAsc(n, array);
		if (flag)
			printf("��\n");
		else
			printf("��\n");
		break;
	}
	case 2: {
		flag = IsDesc(n, array);
		if (flag)
			printf("��\n");
		else
			printf("��\n");
		break;
	}
	case 3: {
		flag = IsAllEqual(n, array);
		if (flag)
			printf("��\n");
		else
			printf("��\n");
		break;
	}
	default:
		break;
	}
	return;
}

void Arrange(PARA* para, float* array)		//9��������Ԫ��
{
	int option;
	unsigned int n = para->arr_num;
	ShowMenu9();
	scanf("%d", &option); fflush(stdin);
	switch (option) {
	case 0:
		break;
	case 1: {
		system("cls");
		Sort(n, array);
		break;
	}
	case 2: {
		system("cls");
		Reverse(n, array);
		PrintArray(para, array);
		break;
	}
	case 3: {
		system("cls");
		unsigned int delta;
		printf("����������ƫ������\n");
		scanf("%d", &delta);
		RotateLeft(n, array,delta);
		printf("�����ɹ���\n");
		PrintArray(para, array);
		break;
	}
	case 4: {
		system("cls");
		unsigned int delta;
		printf("����������ƫ������\n");
		scanf("%d", &delta);
		RotateRight(n, array,delta);
		printf("�����ɹ���\n");
		PrintArray(para, array);
		break;
	}
	default:
		break;
	}
	return;
}