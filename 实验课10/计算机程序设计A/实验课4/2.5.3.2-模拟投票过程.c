#include <stdio.h>
#include <string.h>

struct candidate {
	int id;//编号
	char name[30];//姓名
	char gender;//性别
	unsigned votes;//得票数
};

int main() {
	int n, i, mode, id;
	char name[30];
	printf("有几位候选人：");
	scanf("%d", &n);
	struct candidate can[n];
	printf("输入%d位候选人信息(编号,姓名,性别)：\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d%s", &can[i].id, can[i].name);
		getchar();
		can[i].gender = getchar();
		can[i].votes = 0;
	}
	printf("开始投票：\n");
	for (;;) {
		printf("投票（0编号，1姓名，10结束）：\n");
		scanf("%d", &mode);
		switch (mode) {
			case 0:
				scanf("%d", &id);
				for (i = 0; i < n; i++) {
					if (id == can[i].id) {//教训
						can[i].votes++;
						break;
					}

				}
				break;
			case 1:
				scanf("%s", name);
				for (i = 0; i < n; i++) {
					if (strcmp(name, can[i].name) == 0) {
						can[i].votes++;
						break;
					}
				}
				break;
			case 10:
				goto result;
		}
	}
result:
	printf("投票结果：\n");
	for (i = 0; i < n; i++) {
		printf("%d,%s,%c:%d票\n", can[i].id, can[i].name, can[i].gender, can[i].votes);
	}
	return 0;
}
