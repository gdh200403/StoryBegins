//p138 3.3.2.4-�õݹ麯��ʵ�����������ķ�ת���
/*
*���ܣ�������ת���
*/
#include <stdio.h>
#include <math.h>

/*
*���ܣ��ݹ麯�����ݹ����
*������decimal:������
*����ֵ���ޣ��ں�������������
*/
void decimalReverse(unsigned decimal) {
	if (decimal / 10 == 0) {
		printf("%d", decimal);
	} else {
		printf("%d", decimal % 10);
		decimalReverse(decimal / 10);
	}
}

int main() {
	int decimal;
	printf("Plwase enter a decimal:");
	scanf("%d", &decimal);
	printf("%d<->%c", decimal, decimal > 0 ? ' ' : '-');
	decimalReverse(fabs(decimal));
	return 0;
}