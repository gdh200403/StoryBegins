//p133 3.3.2.2-�ýṹ����������еġ��Զ����¡���Ʒ������ʵ���������������

/*
*�����ܣ����һ����Χ�ڵ����������������б�
*/
#include <stdio.h>
//ȫ�ֱ���������ͳ�����Ӹ���
int factorsNum = 0;
//����������Ӳ��ж��Ƿ�Ϊ�����ĺ���ԭ������
int isPerfectNumber(int num, int factorList[]);
//����������������б����������������ĺ���ԭ������
void print(int perfectNumber, int factorList[]);

int main() {
	int i, upperNumber, factorList[100] = {0};
	printf("�����뷶Χ���ޣ�");
	scanf("%d", &upperNumber);
	for (i = 1; i <= upperNumber; i++) {
		if (isPerfectNumber(i, factorList) == 1) {
			print(i, factorList);
			factorsNum = 0;
		}
	}
	return 0;
}

/*
*���ܣ�����������Ӳ��ж��Ƿ�Ϊ����
*������num�������������factorList����������������
*����ֵ������Ϊ����������1�����򷵻�0
*/
int isPerfectNumber(int num, int factorList[]) {
	int i, j = 0, sum = 0;
	for (i = 1; i < num; i++) {
		if (num % i == 0) {
			factorList[j] = i;
			j++;
			factorsNum++;
		}
	}
	for (i = 0; i < j; i++)
		sum += factorList[i];
	if (num == sum)
		return 1;
	return 0;
}

/*
*���ܣ�����������������б���������������
*����ֵ���ޣ��ں��������
*/
void print(int perfectNumber, int factorList[]) {
	int i;
	printf("%d:", perfectNumber);
	for (i = 0; i < factorsNum; i++) {
		if (factorList[i] != 0)
			printf("%d ", factorList[i]);
	}
	printf("\n");
}