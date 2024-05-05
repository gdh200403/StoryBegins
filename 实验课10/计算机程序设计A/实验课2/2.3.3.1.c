//判断一个点是否位于一个正方形内
#include <stdio.h>

int main() {
	int x, y;
	scanf("%d%d", &x, &y);
	if (x <= 2 && x >= -2 && y <= 2 && y >= -2)
		printf("Yes");
	else
		printf("No");
	return 0;
}