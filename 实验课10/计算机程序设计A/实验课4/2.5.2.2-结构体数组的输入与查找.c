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
	printf("�м�λͬѧ��");
	scanf("%d", &n);
	printf("����%dλͬѧ����Ϣ:���  ����  �Ա�  �ɼ�\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d%s", &stu[i].gid, stu[i].name);
		getchar();
		scanf("%c%f", &stu[i].gender, &stu[i].score);
	}
	printf("������ҷ�ʽ��0-��ţ�1-������2-�Ա�3-�ɼ�����");
	scanf("%d", &so);
	switch (so) {
		case 0:
			printf("����ѧ���ı�ţ�");
			scanf("%d", &gid);
			for (i = 0; i < n; i++)
				if (stu[i].gid == gid)
					printf("%d %s %c %f\n", stu[i].gid, stu[i].name, stu[i].gender, stu[i].score);
			break;
		case 1:
			printf("����ѧ����������");
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
			getchar();//�Ե�֮ǰ�Ļ��У�why��
			printf("����ѧ�����Ա�");
			scanf("%c", &gender);
			for (i = 0; i < n; i++)
				if (stu[i].gender == gender)
					printf("%d %s %c %f\n", stu[i].gid, stu[i].name, stu[i].gender, stu[i].score);
			break;
		case 3:
			printf("����ѧ���ĳɼ���");
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