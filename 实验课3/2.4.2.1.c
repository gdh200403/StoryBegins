#include <stdio.h>

int main() {
	int a[10];
	int i;
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]); //��ʱ�Ӽ��̿�һ������10���ո�ָ���������ֳɶ������룬ֱ������10������
	for (i = 9; i >= 0; i--)
		printf("%d ", a[i]);
	return 0;
}