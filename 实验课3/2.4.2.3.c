#include <stdio.h>

int main() {
	int a[100];//�ϴ�����
	int n;//��������ʵ���ж��ٸ�Ԫ����ֵ
	int i, j, t; //ѭ����������ʱ����
	printf("�м�������1~100����");
	scanf("%d", &n);
	printf("����%d������", n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	//1.�������е�Ԫ��������
	for (i = 0; i < n / 2; i++) {
		t = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = t;
	}
	printf("����洢�������Ԫ������Ϊ��\n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	//2.����������������Ԫ�أ�ע�������޵ķ�Χ
	while (1) { //һֱѭ������Ҫͨ���ڲ�break������ѭ��
		printf("\n����Ҫ����������Ԫ��λ�ã�0~%d����", n);
		scanf("%d%d", &i, &j);
		if (0 <= i && i <= n - 1 && 0 <= j && j <= n - 1) {
			a[i] += a[j];
			a[j] = a[i] - a[j];
			a[i] = a[i] - a[j];
		} else
			break;
		for (i = 0; i < n; i++)
			printf("%d ", a[i]);
	}
	return 0;

}