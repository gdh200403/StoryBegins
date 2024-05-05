#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct student {
	int stunum;
	char name[20];
	float examscore;
	float labscore;
	double totalmark;
};

int main() {
	FILE *fp;
	struct student st[20];
	int i = 0, j, num = 0, a[5] = {0};
	double b[5] = {0}, c[5], num1;
	struct student temp;
	fp = fopen("students.txt", "r");
	while ( feof(fp) != 0 ) {

		fscanf(fp, "%d ", &st[num].stunum);
		fscanf(fp, "%s ", st[num].name);
		fscanf(fp, "%f ", &st[num].examscore);
		fscanf(fp, "%f\n", &st[num].labscore);

		num++;
	}
	for (j = 0; j < num; j++)
		st[j].totalmark = st[j].examscore * 0.6 + st[j].labscore * 0.4;
	for (i = 0; i < num - 1; i++)
		for (j = i + 1; j < num; j++)
			if (st[i].totalmark < st[j].totalmark)
				temp = st[i], st[i] = st[j], st[j] = temp;
	for (i = 0; i < num; i++) {
		if (90 <= st[i].totalmark && st[i].totalmark <= 100)
			a[0]++, b[0] += st[i].totalmark;
		if (85 <= st[i].totalmark && st[i].totalmark < 90)
			a[1]++, b[1] += st[i].totalmark;
		if (75 <= st[i].totalmark && st[i].totalmark < 85)
			a[2]++, b[2] += st[i].totalmark;
		if (60 <= st[i].totalmark && st[i].totalmark < 75)
			a[3]++, b[3] += st[i].totalmark;
		if (0 <= st[i].totalmark && st[i].totalmark < 60)
			a[4]++, b[4] += st[i].totalmark;
	}
	for (i = 0; i < num; i++) {
		if (a[i] != 0)
			c[i] = b[i] / a[i];
		else
			c[i] = 0;
	}
	num1 = num * 1.0;
	for (i = 0; i < num; i++)
		printf("%d %s %f %f %f\n", st[i].stunum, st[i].name, st[i].examscore, st[i].labscore, st[i].totalmark);
	printf("90-100分数段:%d人,%f,平均分%f\n", a[0], a[0] / num1, c[0]);
	for (i = 0; i < num; i++) {
		if (90 <= st[i].totalmark && st[i].totalmark <= 100)
			printf("%d %s\n", st[i].stunum, st[i].name);
	}
	printf("85-90分数段:%d人,%f,平均分%f\n", a[1], a[1] / num1, c[1]);
	for (i = 0; i < num; i++) {
		if (85 <= st[i].totalmark && st[i].totalmark < 90)
			printf("%d %s\n", st[i].stunum, st[i].name);
	}
	printf("75-85分数段:%d人,%f,平均分%f\n", a[2], a[2] / num1, c[2]);
	for (i = 0; i < num; i++) {
		if (75 <= st[i].totalmark && st[i].totalmark < 85)
			printf("%d %s\n", st[i].stunum, st[i].name);
	}
	printf("60-75分数段:%d人,%f,平均分%f\n", a[3], a[3] / num1, c[3]);
	for (i = 0; i < num; i++) {
		if (60 <= st[i].totalmark && st[i].totalmark < 75)
			printf("%d %s\n", st[i].stunum, st[i].name);
	}
	printf("0-60分数段:%d人,%f,平均分%f\n", a[4], a[4] / num1, c[4]);
	for (i = 0; i < num; i++) {
		if (0 <= st[i].totalmark && st[i].totalmark < 60)
			printf("%d %s\n", st[i].stunum, st[i].name);
	}
	fclose(fp);
	return 0;
}
