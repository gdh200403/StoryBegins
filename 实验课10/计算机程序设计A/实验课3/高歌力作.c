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
	printf("����bug������:");
	scanf("%d", &bugs);
	printf("������Ʒ��������");
	printf("�������ڵ�ʱ�����㣺");
	scanf("%d", &t);
	if (t < 0 || t > 24) {
		printf("��������!!!\n");
		printf("�����Ұ����ͷ����!!!\n");
		printf("�ٸ���һ�λ���\n");
		t = 0;
		printf("�������ڵ�ʱ�����㣺");
		scanf("%d", &t);
		if (t < 0 || t > 24)
			printf("���ͷ����ͱ�����");
	} else
		printf("�߸�Ҫ������!!!");
	return 0;
}
//��������������Ļ����������ֻ��һ�ڿΣ�����
//��