//p142 3.3.3.7-��ʶ���б�
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int panduan(char a[]);//�жϱ�ʶ���Ƿ�Ϸ���������Υ������ĺ���ԭ������

int main() {
	char a[100];
	printf("������16�ֽ������ַ�����\n");
	scanf("%s", a);
	if (panduan(a) == 1)
		printf("���ɳ���Ϊ%d�ı�ʶ��%s", strlen(a), a);
	else if (panduan(a) == 2)
		printf("�ַ���������");
	else if (panduan(a) == 3)
		printf("������ĵ�һ���ַ�������ĸ���»��ߣ�");
	else if (panduan(a) == 0)
		printf("���벻�Ϸ���");
	return 0;
}

/*
*���ܣ��жϱ�ʶ���Ƿ�Ϸ���������Υ�����
*������a[],������ַ���
*����ֵ��1.�Ϸ���2.�ַ���������3.����ĵ�һ���ַ�������ĸ���»��ߣ�0.�������Ϸ�
*/
int panduan(char a[]) {
	int flag = 0, i;//ѭ�����������ر���
	if (strlen(a) > 16)
		return 2;//�ȼ���ַ������ȣ���<string.h>��strlen����
	else {
		if (a[0] >= 'a' && a[0] <= 'z' || a[0] >= 'A' && a[0] <= 'Z' || a[0] == 95) {//�����λ�Ƿ�Ϊ��ĸ���»���
			for (i = 1; i < strlen(a); i++) {
				if (isalnum(a[i]) == 0)//��<ctype.h>��isalnum()�����������ַ��Ƿ�Ϊ��ĸ�����֣����򷵻ط���ֵ�����򷵻�0��
					flag++;
			}
			if (flag == 0)
				return 1;
			else
				return 0;
		} else
			return 3;
	}
}