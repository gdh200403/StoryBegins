#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include "main.h"
#define MAX_SIZE 100

void ShowMenu(void) //0显示菜单
{
	printf("***欢迎使用数组运算器!***\n");
	printf("配置系统参数\t\t1\n");
	printf("显示数组\t\t2\n");
	printf("生成样本数据\t\t3\n");
	printf("删除数据\t\t4\n");
	printf("插入新元素\t\t5\n");
	printf("统计\t\t\t6\n");
	printf("查找\t\t\t7\n");
	printf("判断\t\t\t8\n");
	printf("排列数组元素\t\t9\n");
	printf("退出程序\t\t0\n");
	printf("*************************\n");
	printf("输入对应数字以执行相应功能：\n");
	return;
}

void Config(PARA* para) //1配置系统参数
{
	printf("请依次输入以下三个参数\n1.您期望的数组元素个数（1~%d）:\n", MAX_SIZE);
	scanf("%d", &para->arr_num); fflush(stdin);
	para->arr_num %= MAX_SIZE;//数据不合法时默认对MAX_SIZE求余
	printf("2.输出时每行显示元素个数：\n");
	scanf("%d", &para->num_per_row); fflush(stdin);
	printf("3.输出时每个元素的保留小数点位数：\n");
	scanf("%d", &para->deci); fflush(stdin);
	printf("系统参数初始化完毕！请前往生成样本数据！");
	return;
}

void PrintArray(PARA* para, float* array)		//2显示数组
{
	int i;
	char format[6] = "%8.3f";
	if (!(para->arr_num && para->deci && para->num_per_row)) {
		printf("请先配置系统参数！\n");
		return;
	}
	format[3] = '0' + para->deci;
	printf("您的数组如下：\n");
	for (i = 0; i < para->arr_num; i++) {
		printf(format, array[i]);
		if ((i+1) % para->num_per_row == 0)
			printf("\n");
	}
	if (i % para->num_per_row !=0)
		printf("\n");
	return;
}

void FillArray(PARA* para, float* array)		//3生成样本数据
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
			printf("请输入随机数生成的区间左右端点:\n");
			int count = scanf("%f%f", &min, &max);fflush(stdin);
			if (count != 2 || min >= max)
				return;
			FillRandom(n, array, min, max);
			printf("您的数组根据区间[%f,%f]随机填充完毕！\n", min, max);
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
			printf("请输入您要用来填充数组的常值：\n");
			scanf("%f", &val); fflush(stdin);
			FillSameVal(n, array, val);
			printf("您的数组根据常值%f全部填充完毕！\n", val);
			break;
		}
		case 4:
		{
			float a0, d;
			system("cls");
			printf("请输入数组首项：\n");
			scanf("%f", &a0); fflush(stdin);
			printf("请输入数组公差：\n");
			scanf("%f", &d); fflush(stdin);
			FillArithSeq(n,array, a0, d);
			printf("您的数组根据首项%.3f,公差%.3f全部填充完毕！\n",a0,d);
			break;
		}
		default:
			return;
		}
	return;
}

void Delete(PARA* para, float* array)			//4删除
{
	int option;
	unsigned int n = para->arr_num;
	if (!(para->arr_num && para->deci && para->num_per_row)) {
		printf("请先配置系统参数！\n");
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
		printf("请输入您要删除元素的下标：\n");
		scanf("%d", &index); fflush(stdin);
		if (!DeleteIndex(para, array, index))
			printf("删除成功！\n");
		else
			printf("删除失败！未找到该下标元素\n");
		break;
	}
	case 2:
	{
		system("cls");
		float val;
		printf("请输入您要删除元素的值：\n");
		scanf("%f", &val); fflush(stdin);
		printf("删除了%d个元素！", DeleteValue(para, array, val));
		break;
	}
	case 3:
	{
		system("cls");
		int left, right;
		printf("请输入您要删除的数据下标左右端点:\n");
		int count = scanf("%d%d", &left, &right); fflush(stdin);
		if (count != 2 || left >= right)
			return;
		DeleteRange(para, array, left, right);
		printf("删除成功！\n");
		break;
	}
	default:
		break;
	}
	return;
}

void Insert(PARA* para, float* array)			//5插入新元素
{
	if (!(para->arr_num && para->deci && para->num_per_row)) {
		printf("请先初始化数组！\n");
		return;
	}
	if (para->arr_num == MAX_SIZE) {
		printf("数组已满！请删除部分元素后再添加！\n");
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
		printf("请输入您要插入的新元素的下标：\n");
		scanf("%d", &index); fflush(stdin);
		if (index > para->arr_num) {
			printf("下标超出数组范围！\n");
			return;
		}
		printf("请输入您要插入的新元素的值：\n");
		scanf("%f", &val); fflush(stdin);
		InsertIndex(para, array, index, val);
		printf("已成功在数组下标为%d处插入数据%f！\n", index, val);
		break;
	}
	case 2:
	{
		system("cls");
		if (IsAsc(para->arr_num, array) == 0 && IsDesc(para->arr_num, array) == 0) {
			printf("您的数组不是有序数组！若要使用此功能，请先排序！\n");
			return;
		}
		else {
			float val;
			unsigned int index;
			printf("请输入您要插入的新元素的值：\n");
			scanf("%f", &val); fflush(stdin);
			index=InsertOrder(para, array, val);
			printf("成功在您的有序数组的下标为%d处插入数据%f！\n", index, val);
			break;
		}
	}
	default:
		break;
	}
	return;
}

void Statistics(PARA* para, float* array)		//6统计
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
		printf("最大值：%f\n", Max(n, array));
		PrintArray(para, array);
		break;
	case 2:
		system("cls");
		printf("最小值：%f\n", Min(n, array));
		PrintArray(para, array);
		break;
	case 3:
		system("cls");
		printf("平均值：%f\n", Average(n, array));
		PrintArray(para, array);
		break;
	case 4:
		system("cls");
		printf("方差：%f\n", Variance(n, array));
		PrintArray(para, array);
		break;
	case 5:
		system("cls");
		printf("均方差：%f\n", StdDev(n, array));
		PrintArray(para, array);
		break;
	default:
		break;
	}
	return;
}

void Search(PARA* para, float* array)			//7查找
{
	int option;
	unsigned int n = para->arr_num;
	ShowMenu7();
	scanf("%d", &option); fflush(stdin);
	float val;
	printf("请输入你要查找的元素的值：\n");
	scanf("%f", &val); fflush(stdin);
	switch (option) {
	case 0:
		return;
	case 1: {
		unsigned int index = SeqSearch(n, array, val);
		if (index == -1) {
			printf("未找到该元素！\n");
		}
		else {
			printf("您查找的元素下标为%d\n", index);
		}
		break;
	}
	case 2:
	{
		unsigned int index = BiSearch(n, array, val);
		if (index == -1)
			printf("未找到该元素！\n");
		else if(index==-2)
			printf("不是严格有序数组！无法使用二分查找！\n");
			
		else
			printf("您查找的元素下标为%d\n", index);
		break;
	}
	default:
		break;
	}
	return;
}

void Judge(PARA* para, float* array)			//8判断
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
			printf("是\n");
		else
			printf("否\n");
		break;
	}
	case 2: {
		flag = IsDesc(n, array);
		if (flag)
			printf("是\n");
		else
			printf("否\n");
		break;
	}
	case 3: {
		flag = IsAllEqual(n, array);
		if (flag)
			printf("是\n");
		else
			printf("否\n");
		break;
	}
	default:
		break;
	}
	return;
}

void Arrange(PARA* para, float* array)		//9排列数组元素
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
		printf("请输入左旋偏移量：\n");
		scanf("%d", &delta);
		RotateLeft(n, array,delta);
		printf("操作成功！\n");
		PrintArray(para, array);
		break;
	}
	case 4: {
		system("cls");
		unsigned int delta;
		printf("请输入右旋偏移量：\n");
		scanf("%d", &delta);
		RotateRight(n, array,delta);
		printf("操作成功！\n");
		PrintArray(para, array);
		break;
	}
	default:
		break;
	}
	return;
}