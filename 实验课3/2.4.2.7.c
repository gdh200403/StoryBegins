#include <stdio.h>
#include <time.h>

int main() {
	FILE *fpi, *fpo; //定义两个指针变量用于读取数据和保存结果
	time_t seconds;//从1970年1月1日到现在的秒数
	char days_mons[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}},
	leap  = 0;
	int year, month, day, hour, minute, second;
	int a[100];
	int n;
	int i, j, t;
	printf("有几个数（1~100）：");
	scanf("%d", &n);
	fpi = fopen("data.txt", "r");
	if (fpi == NULL) {
		fpi = fopen("data.txt", "w+"); //可读写方式打开，不存在就新建，存在就清空文件内容
		printf("输入%d个数：", n);
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			fprintf(fpi, "%d ", a[i]);
		}
		rewind(fpi);//调整到文件开头，以便后续程序从头开始读取文件中的数据
	}
	//
	fpo = fopen("result.txt", "a"); //以追加的方式打开当前文件夹中的文本文件，不存在就新建，存在就在文件结尾添加数据
	for (i = 0; i < n; i++)
		fscanf(fpi, "%d", &a[i]);
	fclose(fpi);//读取数据结束
	/*对从文件读取的数据处理部分忽略，这里仅获取当前系统的时间，与读取的数据一起写入“result.txt”文件中*/
	seconds = time(NULL) + 8 * 60 * 60; //获取系统从1970年1月1日到现在的秒数，加上时间区的秒数
	second = seconds % 60;
	seconds /= 60;
	minute = seconds % 60;
	seconds /= 60;
	hour = seconds % 24;
	seconds /= 24;
	year = 1970;
	leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	while (seconds > 365) {
		if (leap)
			seconds -= 366;
		else
			seconds -= 365;
		year++;
		leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	}
	month == 1;
	for (i = 0; seconds >= days_mons[leap][i]; i++, month++)
		seconds -= days_mons[leap][i];
	day = seconds + 1;
	fprintf(fpo, "%d-%02d-%02d,%02d:%02d:%02d\n", year, month, day, hour, minute, second); //写时间戳到文件
	for (i = 0; i < n; i++)
		fprintf(fpo, "%d ", a[i]); //将数组中的数据写入文件
	fprintf(fpo, "\n"); //最后写一个换行到文件
	fclose(fpo);
	return 0;


}