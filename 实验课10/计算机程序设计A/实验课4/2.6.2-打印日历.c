#include <stdio.h>

int main() {
	int days_mons[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	},
	leap = 0;
	int year, day, i, j;//年份，1月1日星期几，循环变量
	printf("输入：输入一年的年份和1月1日是星期几（1~7）：");
	scanf("%d%d", &year, &day);//输入
	printf("输出：\n");
	leap = ((year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0);//判断闰年
	if (leap) {//闰年
		for (i = 0; i < 12; i++) {
			printf("%d年%d月\n", year, i + 1);
			printf("星期一 星期二 星期三 星期四 星期五 星期六 星期日\n");//每月表头
			for (j = 1; j < day; j++)
				printf("       ");//首日对齐
			for (j = 1; j <= days_mons[1][i]; j++) {
				printf("  %2d   ", j);//日期数字“居中”对齐
				if ((j + day - 1) % 7 == 0 )
					printf("\n");//周日数字后换行
			}
			if ((day + days_mons[1][i] - 1) % 7 == 0)
				printf("\n");
			else
				printf("\n\n");//月末为周日时的修正，最终效果为每个月之间空一行
			day = (days_mons[1][i] + day) % 7;//计算下个月的1号是星期几
		}
	} else { //平年
		for (i = 0; i < 12; i++) {
			printf("%d年%d月\n", year, i + 1);
			printf("星期一 星期二 星期三 星期四 星期五 星期六 星期日\n");
			for (j = 1; j < day; j++)
				printf("       ");
			for (j = 1; j <= days_mons[0][i]; j++) {
				printf("  %2d   ", j);
				if ((j + day - 1) % 7 == 0 )
					printf("\n");
			}
			if ((day + days_mons[0][i] - 1) % 7 == 0)
				printf("\n");
			else
				printf("\n\n");
			day = (days_mons[1][i] + day) % 7;
		}
	}
}