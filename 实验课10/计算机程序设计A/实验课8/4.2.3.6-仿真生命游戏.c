//p178 4.2.3.6-仿真生命游戏
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void evolution(char lifeMatrix[][40], int n) {
	int i, j, k, p, t;
	int a[40][40] = {{0}};
	int count;
	for (t = 1; t < n; t++) {
		for (i = 0; i < 40; i++) {
			for (j = 0; j < 40; j++) {
				count = 0;
				for (k = i - 1; k <= i + 1 ; k++) {
					if (k >= 0 && k < 40) {
						for (p = j - 1; p <= j + 1 ; p++) {
							if (0 <= p && p < 40) {
								if (!(k == i && p == j)) {
									if (lifeMatrix[k][p] == '*')
										count++;
								}
							}
						}
					}
				}
				//printf("%d ", count);
				if (lifeMatrix[i][j] == '*') {
					if (count < 2 || count > 3)
						a[i][j] = 0;
					else
						a[i][j] = 1;
				} else {
					if (count == 3)
						a[i][j] = 1;
					else
						a[i][j] = 0;
				}
				//printf("%d  ", a[i][j]);
			}
		}
		for (i = 0; i < 40; i++) {
			for (j = 0; j < 40; j++)
				lifeMatrix[i][j] = a[i][j] ? '*' : '-';
		}
		/*for (i = 0; i < 40; i++) {
			printf("\n");
			for (j = 0; j < 40; j++)
				printf("%d", a[i][j]);
		}*/
	}
}

int main() {
	char lifeMatrix[40][40];
	int a[40][40] = {{0}};
	float p;
	int alive, n;
	int i, j, random;
	printf("请输入初代细胞生存比例:");
	scanf("%f", &p);
	if (p < 0 || p > 1) {
		printf("Input Error!\n");
		return 1;
	}
	alive = 1600 * p;
	srand((unsigned)time(NULL));
	for (i = 0; i < alive; i++) {
		random = rand();
		random %= 1600;
		if (a[random / 40][random % 40] == 1) {
			i--;
		} else
			a[random / 40][random % 40] = 1;
	}
	for (i = 0; i < 40; i++) {
		for (j = 0; j < 40; j++)
			lifeMatrix[i][j] = a[i][j] ? '*' : '-';
	}
	printf("初代细胞生存情况如下：\n");
	for (i = 0; i < 40; i++) {
		printf("\n");
		for (j = 0; j < 40; j++)
			printf("%c", lifeMatrix[i][j]);
	}
	printf("\n请输入进化至第几代：");
	scanf("%d", &n);
	evolution(lifeMatrix, n);
	printf("进化至第%d代，生存情况如下：", n);
	for (i = 0; i < 40; i++) {
		printf("\n");
		for (j = 0; j < 40; j++)
			printf("%c", lifeMatrix[i][j]);
	}
	printf("\n");
	/*int b;
	for (;;) {
		printf("下一代？1是0否\n");
		scanf("%d", &b);
		if (b) {
			evolution(lifeMatrix, 2);
			for (i = 0; i < 40; i++) {
				printf("\n");
				for (j = 0; j < 40; j++)
					printf("%c", lifeMatrix[i][j]);
			}
			printf("\n");
		} else
			return 0;
	}*/
	return 0;
}

