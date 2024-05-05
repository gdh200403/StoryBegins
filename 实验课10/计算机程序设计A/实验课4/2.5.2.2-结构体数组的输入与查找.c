#include <stdio.h>
#include <math.h>

struct student {
	int gid;
	char name[20];
	char gender;
	float score;
};

int main() {
	struct student stu[100];
	int i, j, k, n, so, gid;
	char name[20];
	char gender;
	float score;
	printf("有几位同学？");
	scanf("%d", &n);
	printf("输入%d位同学的信息:编号  姓名  性别  成绩\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d%s", &stu[i].gid, stu[i].name);
		getchar();
		scanf("%c%f", &stu[i].gender, &stu[i].score);
	}
	printf("输入查找方式（0-编号，1-姓名，2-性别，3-成绩）：");
	scanf("%d", &so);
	switch (so) {
		case 0:
			printf("输入学生的编号：");
			scanf("%d", &gid);
			for (i = 0; i < n; i++)
				if (stu[i].gid == gid)
					printf("%d %s %c %f\n", stu[i].gid, stu[i].name, stu[i].gender, stu[i].score);
			break;
		case 1:
			printf("输入学生的姓名：");
			scanf("%s", name);
			for (i = 0; i < n; i++) {
				j = 0, k = 0;
				while (name[j] != '\0') {
					if (name[j] != stu[i].name[j]) {
						k = 1;
						break;
					}
					j++;
				}
				if (k = 0)
					printf("%d %s %c %f\n", stu[i].gid, stu[i].name, stu[i].gender, stu[i].score);
			}
			break;
		case 2:
			getchar();//吃掉之前的换行，why？
			printf("输入学生的性别：");
			scanf("%c", &gender);
			for (i = 0; i < n; i++)
				if (stu[i].gender == gender)
					printf("%d %s %c %f\n", stu[i].gid, stu[i].name, stu[i].gender, stu[i].score);
			break;
		case 3:
			printf("输入学生的成绩：");
			scanf("%f", &score);
			for (i = 0; i < n; i++)
				if (fabs(stu[i].score - score) < 1e-6)
					printf("%d %s %c %f\n", stu[i].gid, stu[i].name, stu[i].gender, stu[i].score);
			break;
		default:
			break;
	}
	return 0;
}