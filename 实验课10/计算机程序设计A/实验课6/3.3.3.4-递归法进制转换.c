//p140 3.3.3.4-�ݹ鷨����ת��
#include <stdio.h>
#include <math.h>

void dec2sn(int decimal, int systemNumber);//�ݹ鷨����ת������ԭ������

int main() {
	int decimal, systemNumber;
	scanf("%d%d", &decimal, &systemNumber);//����ʮ���������ת������
	dec2sn(decimal, systemNumber);
	return 0;
}

/*
*���ܣ��ݹ鷨����ת��
*������decimal:ʮ��������systemNumber:��ת������
*����ֵ���ޣ��ں�������������
*/
void dec2sn(int decimal, int systemNumber) {
	int rest;//��
	switch (systemNumber) {
		case 2:
		case 8:
			if (decimal < systemNumber)
				printf("%d", decimal);//�ݹ���õ��յ㣺��һ�ִ����������̶Խ����������������Ϊ0�������һ������
			else {
				rest = decimal / systemNumber;//ʮ���������Խ������������������
				dec2sn(rest, systemNumber);//���ִ����������̼����Խ��������������
				printf("%d", decimal % systemNumber);//�ڵݹ���ú�����������ִ�����������������Ա�֤�����Ӻ���ǰ���
			}
			break;
		case 16:
			if (decimal < systemNumber)
				switch (decimal) {
					case 0:
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:
					case 7:
					case 8:
					case 9:
						printf("%d", decimal);
						break;
					case 10:
						printf("A");
						break;
					case 11:
						printf("B");
						break;
					case 12:
						printf("C");
						break;
					case 13:
						printf("D");
						break;
					case 14:
						printf("E");
						break;
					case 15:
						printf("F");
						break;
				} else {
				rest = decimal / systemNumber;
				dec2sn(rest, systemNumber);
				switch (decimal % systemNumber) {
					case 0:
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:
					case 7:
					case 8:
					case 9:
						printf("%d", decimal);
						break;
					case 10:
						printf("A");
						break;
					case 11:
						printf("B");
						break;
					case 12:
						printf("C");
						break;
					case 13:
						printf("D");
						break;
					case 14:
						printf("E");
						break;
					case 15:
						printf("F");
						break;
				}

			}
			break;
		default:
			printf("ERROR!");
			break;
	}

}
