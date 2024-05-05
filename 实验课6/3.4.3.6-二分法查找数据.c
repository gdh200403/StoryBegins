//p148 3.4.3.6-���ַ���������
#include <stdio.h>
#define N 10

/*
*���ܣ����ַ���������
*������a[]:����С�����˳�����кõ������飬n:����a[]Ԫ�ظ�����x:���ͣ�����������
*����ֵ��-1���Ҳ������������ҵ�������a[]�е�λ��
*/
int findByHalf(int a[], int n, int x) {
	int low = 0;
	int high = n - 1;
	int middle;
	while (low <= high) {
		middle = (low + high) / 2;
		if (x == a[middle])
			return middle;
		else if (x > a[middle])
			low = middle + 1;//���x���м�ֵ�����������ұ�һ��
		else if (x < a[middle])
			high = middle - 1;//���x���м�ֵС�������������һ��
	}
	return -1;//����ѭ����˵��û�ҵ�
}

int main() {
	int a[N];
	int i;
	int x, flag;
	for (i = 0; i < N; i++) {
		a[i] = 2 * i + 1;
	}//����ĿҪ��������
	printf("��������������\n");
	scanf("%d", &x);
	flag = findByHalf(a, N, x);//���ú�������ȡ����ֵ
	if (flag == -1) {
		printf("ɾ����Ľ��Ϊ��\nδ�ҵ���ɾ�����֣�");
	} else {
		for (i = flag; i < N; i++) {
			a[i] = a[i + 1];
		}//ɾ���������ݲ�����������ǰ��һλ
		printf("ɾ�����Ϊ��\n");
		for (i = 0; i < N - 1; i++)
			printf("%d ", a[i]);//���
	}
	return 0;
}