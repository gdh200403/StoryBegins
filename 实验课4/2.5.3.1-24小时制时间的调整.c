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
	printf("������ʱ,��,��:");
	scanf("%d,%d,%d", &time.hours, &time.minutes, &time.seconds); //���ŷָ�����������
	if (time.hours > 23 || time.hours < 0 ||
	        time.minutes > 59 || time.minutes < 0 ||
	        time.seconds > 59 || time.seconds < 0)
		goto loop;
	for (;;) {
		hour = time.hours;
		minute = time.minutes;
		second = time.seconds;
		printf("���������ʱ���������");
		scanf("%d", &add);
		if (add == 0)
			break;
		printf("%d-%d-%d����%d���Ϊ��", time.hours, time.minutes, time.seconds, add);
		second += add; //������
		if (second > 0)
			minute += second / 60;
		else
			minute += second / 60 - 1; //�ܷ�����
		if (minute > 0)
			hour += minute / 60;
		else
			hour += minute / 60 - 1; //��Сʱ��
		if (second > 0)
			second %= 60;
		else
			second = second % 60 + 60; //��
		if (minute > 0)
			minute %= 60;
		else
			minute = minute % 60 + 60; //��
		if (hour > 0)
			hour %= 24;
		else
			hour = hour % 24 + 24; //ʱ
		printf("%d-%d-%d\n", hour, minute, second);
	}
	return 0;
}