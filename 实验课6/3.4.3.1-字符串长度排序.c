//p145 3.4.3.1-�ַ�����������
#include <stdio.h>
#define StrLen 100//�����ַ�����󳤶�
void udf_getString(char[], int strlength);//�ַ������뺯��
int udf_strlen(char s[]);//�ַ�������
void udf_sort(char s[][StrLen], int strNum);//�Ը������������͵��ַ�����������
void udf_print(char s[][StrLen], int strNum);//�Ը����������ַ������

int main() {
	char s[100][StrLen];
	int strNum = 0;//�ַ����������ַ����ܸ���
	int i = 0;
	do {
		printf("�������ַ���%d(����Ctrl+Z+Enter+Enter��������)��\n", i + 1);
		udf_getString(s[i], StrLen);
		i++;
	} while (udf_strlen(s[i - 1]) != 0);//��do-while����������һ���ַ���
	strNum = i - 1;//����������������������������������ʵ�����������Ҫ-1������Ӧ��i
	udf_sort(s, strNum);//���飨�����ַ�������ʵ��ʱ���β����м���������ʵ���������д����������
	udf_print(s, strNum);
	return 0;
}

/*
*���ܣ��ַ�������
*������a[]:������Ŀ��ַ�����strlength:�ַ�����󳤶�
*����ֵ����
*/
void udf_getString(char a[], int strlength) {
	int i;
loop:
	scanf("%s", a);
	getchar();//�ַ�������
	if (udf_strlen(a) >= strlength) {
		printf("����������������:\n");//�ַ�����������
		for (i = 0; i < strlength; i++) {
			a[i] = '\0';
		}//��ճ����ַ�������ʵ������գ�����������'\0'������֤����ַ������ٸ�ֵ����Ա���ȷ���
		goto loop;//��������
	}
	return;
}

/*
*���ܣ���ȡ�ַ�������
*������s[]������ȡ�����ַ���
*����ֵ���ַ�������
*/
int udf_strlen(char s[]) {
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}

/*
*���ܣ��Ը������������͵��ַ�����������
*������s[][StrLen]:�������ַ������飻strNum:�������ַ����������ַ���������
*����ֵ���ޣ�ֱ�Ӷ�������в���
*/
void udf_sort(char s[][StrLen], int strNum) {
	char a[StrLen];
	int i, j, k;
	for (i = 0; i < strNum; i++) {
		for (j = i; j > 0; j--) {
			if (udf_strlen(s[j]) < udf_strlen(s[j - 1])) {
				for (k = 0; k < StrLen; k++) {
					a[k] = s[j][k];
					s[j][k] = s[j - 1][k];
					s[j - 1][k] = a[k];
				}
			}
		}
	}//���ַ������Ƚ��в�������
	return;
}

/*
*���ܣ�����ַ���
*�������ϻ�
*����ֵ���ϻ�
*/
void udf_print(char s[][StrLen], int strNum) {
	int i;
	printf("��������\n");
	for (i = 0; i < strNum; i++) {
		printf("%s\n", s[i]);
	}//���
	return;
}