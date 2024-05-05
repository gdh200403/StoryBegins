#include <stdio.h>

struct Time {
	int hours;
	int minutes;
	int seconds;
};

int main() {
	int hour, minute, second, add;
	struct Time time;
loop:
	printf("请输入时,分,秒:");
	scanf("%d,%d,%d", &time.hours, &time.minutes, &time.seconds); //逗号分隔的数据输入
	if (time.hours > 23 || time.hours < 0 ||
	        time.minutes > 59 || time.minutes < 0 ||
	        time.seconds > 59 || time.seconds < 0)
		goto loop;
	for (;;) {
		hour = time.hours;
		minute = time.minutes;
		second = time.seconds;
		printf("请输入调整时间的秒数：");
		scanf("%d", &add);
		if (add == 0)
			break;
		printf("%d-%d-%d调整%d秒后为：", time.hours, time.minutes, time.seconds, add);
		second += add; //总秒数
		if (second > 0)
			minute += second / 60;
		else
			minute += second / 60 - 1; //总分钟数
		if (minute > 0)
			hour += minute / 60;
		else
			hour += minute / 60 - 1; //总小时数
		if (second > 0)
			second %= 60;
		else
			second = second % 60 + 60; //秒
		if (minute > 0)
			minute %= 60;
		else
			minute = minute % 60 + 60; //分
		if (hour > 0)
			hour %= 24;
		else
			hour = hour % 24 + 24; //时
		printf("%d-%d-%d\n", hour, minute, second);
	}
	return 0;
}