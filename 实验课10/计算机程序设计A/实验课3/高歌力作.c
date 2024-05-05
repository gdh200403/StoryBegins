#include <stdio.h>

void paixu(int n, float a[]) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = i; j > 0; j--) {
			if (a[j] > a[j - 1])
				;
			else {
				a[j] = a[j] + a[j - 1];
				a[j - 1] = a[j] - a[j - 1];
				a[j] = a[j] - a[j - 1];
			}
		}
	}
	return;
}

int main() {
	struct bugs {

	};
	int t, bugs;
	printf("输入bug的数量:");
	scanf("%d", &bugs);
	printf("输入物品的数量：");
	printf("输入现在的时间整点：");
	scanf("%d", &t);
	if (t < 0 || t > 24) {
		printf("你在乱输!!!\n");
		printf("当心我把你的头打歪!!!\n");
		printf("再给你一次机会\n");
		t = 0;
		printf("输入现在的时间整点：");
		scanf("%d", &t);
		if (t < 0 || t > 24)
			printf("你的头今晚就被打歪");
	} else
		printf("高歌要饿死啦!!!");
	return 0;
}
//明天如果他不来的话，我明天就只有一节课！！！
//哈