#include <stdio.h>

int main() {
	int days_mons[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	},
	leap = 0;
	int year, day, i, j;//��ݣ�1��1�����ڼ���ѭ������
	printf("���룺����һ�����ݺ�1��1�������ڼ���1~7����");
	scanf("%d%d", &year, &day);//����
	printf("�����\n");
	leap = ((year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0);//�ж�����
	if (leap) {//����
		for (i = 0; i < 12; i++) {
			printf("%d��%d��\n", year, i + 1);
			printf("����һ ���ڶ� ������ ������ ������ ������ ������\n");//ÿ�±�ͷ
			for (j = 1; j < day; j++)
				printf("       ");//���ն���
			for (j = 1; j <= days_mons[1][i]; j++) {
				printf("  %2d   ", j);//�������֡����С�����
				if ((j + day - 1) % 7 == 0 )
					printf("\n");//�������ֺ���
			}
			if ((day + days_mons[1][i] - 1) % 7 == 0)
				printf("\n");
			else
				printf("\n\n");//��ĩΪ����ʱ������������Ч��Ϊÿ����֮���һ��
			day = (days_mons[1][i] + day) % 7;//�����¸��µ�1�������ڼ�
		}
	} else { //ƽ��
		for (i = 0; i < 12; i++) {
			printf("%d��%d��\n", year, i + 1);
			printf("����һ ���ڶ� ������ ������ ������ ������ ������\n");
			for (j = 1; j < day; j++)
				printf("       ");
			for (j = 1; j <= days_mons[0][i]; j++) {
				printf("  %2d   ", j);
				if ((j + day - 1) % 7 == 0 )
					printf("\n");
			}
			if ((day + days_mons[0][i] - 1) % 7 == 0)
				printf("\n");
			else
				printf("\n\n");
			day = (days_mons[1][i] + day) % 7;
		}
	}
}