#include <stdio.h>

int main() {
	int a[100];
	int n, i, t, ti;
	printf("�м���������");
	scanf("%d", &n);
	printf("����%d��������", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}//����������
	t = a[0];
	for (i = 0; i < n ; i++) {
		if (a[i] < t)
			;
		else
			t = a[i];
	}//�õ����ֵt
	for (i = 0; i < n; i++) {
		if (t == a[i])
			break;
	}
	ti = i;//���ֵΪt�ĵ�һ�����������е�λ��
	for (i = 0; i < n - 1; i++) {
		if (i >= ti)
			a[i] = a[i + 1]	;
	}//���������ǰ��һλ
	a[n - 1] = t;//�����������һλ
	printf("�����λ�����");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}//���������
	return 0;


}