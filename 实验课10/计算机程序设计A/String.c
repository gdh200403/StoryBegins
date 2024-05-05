#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define      N  100

//��ʾ�˵�
void printMenu(void) {
	printf("************************************\n");
	printf("        �� �� �� �� �� ��   \n");
	printf("************************************\n");
	printf("0  �˳�����\n");
	printf("1  �����ַ���\n");
	printf("2  ����ַ���\n");
	printf("3  �ַ�������\n");
	printf("4  �����ַ���\n");
	printf("5  �Ƚ��ַ���\n");
	printf("6  �ַ�������\n");
	printf("7  �����ַ���\n");
	printf("8  ȡ�Ӵ�\n");
	printf("9  �ִ�����\n");
	printf("10 �Ӵ��滻\n");
	printf("************************************\n");
}


//�����ַ���
void StrGet(char *s) {
	printf("�������ַ���");
	scanf("%s", s);
}

//��ʾ�ַ���
void StrPut(char *s) {
	printf("�ַ������£�\n%s\n", s);
}

//���ַ�������
int StrLen(char *s) {
	int number = 0;
	char *temp_s3 = s;
	while (*temp_s3 != '\0') {
		number++;
		temp_s3++;
	}
	return number;
}

//�ַ�������
void StrCat(char *s, char *t) {
	int length, i;
	length = strlen(s);
	for (i = 0; * (t + i) != '\0'; i++) {
		*(s + length + i) = *(t + i);
	}
}

//�ַ����Ƚ�
int StrCmp(char *str1, char *str2) {
	int ret = 0;
	while (!(ret = *(unsigned char *)str1 - * (unsigned char *)str2) && *str1) {
		str1++;
		str2++;
	}


	if (ret < 0) {
		return -1;
	} else if (ret > 0) {
		return 1;
	}
	return 0;
}


//�ַ�������
void StrCpy(char *s, char *t) {
	if (t == NULL) {
		printf("�ַ���Ϊ��\n");
	}
	int len = strlen(t);
	int i = 0;
	while (i != (len - 1)) {
		s[i] = t[i];
		i++;
	}
	s[len] = '\0';

}

//�ַ�������
char StrIns(char *s, int pos, char *t) {
	int len1 = 0, len2 = 0, i = 0;
	len1 = strlen(s);
	len2 = strlen(t);
	for (i = len1 - 1; i >= pos - 1; i--) {
		s[i + len2] = s[i];
	}
	for (i = pos - 1; i < pos - 1 + len2; i++) {
		s[i] = t[i - pos + 1];
	}
	len1 += len2;
	s[len1] = '\0';
}

//���Ӵ�
void StrSub(char *s, int pos, int n, char *t) {
	int p = 0;
	if (pos > (strlen(s) - 1) || (pos + n) > strlen(s)) {
		printf("Error.\n");
	} else {
		while (p < n) {
			t[p] = s[pos + p];
			p++;
		}
		t[n] = '\0';
	}
}

//�Ӵ�����
int StrStr(char *s, char *t) {
	int i, j, k;
	int flag = 0;
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0'; k++, j++) {
			if (t[k] != s[j]) {
				break;
			}
		}
		if (t[k] == '\0') {
			printf("%d", i);
			printf("\n");
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		printf("error\n");
		return -1;
	}
	return i;
}

int StrReplace(char *s, char *v, char *t) {
	int sLen, vLen, tLen, pos;
	char *ts = s, *tv = v, *tt = t;
	vLen = strlen(v);
	sLen = strlen(s);
	vLen = strlen(v);
	tLen = strlen(t);
	pos = StrStr(s, v);
	int delta = tLen - vLen;
	if (pos >= 0) {
		if (delta > 0) {
			for (int i = sLen; i >= pos + vLen; i--) {
				ts[i + delta] = ts[i];
			}
			ts += pos;
			for (int i = pos + vLen; i < tLen; i++) {
				ts[i] = tt[i];
			}
		} else if (delta < 0) {
			for (int i = pos + vLen; i <= sLen; i++) {
				ts[i] = ts[i + delta];
			}
			ts += pos;
			for (int i = 0; i < tLen; i++) {
				ts[i] = tt[i];
			}
		} else {
			ts += pos;
			for (int i = 0; i < tLen; i++) {
				ts[i] = tt[i];
			}
		}
	} else {
		printf("�滻ʧ�ܣ�ԭ�ַ���������Ӧ�ַ�����\n");
		return -1;
	}
	StrPut(s);
	return 0;
}

int main() {
	char s[N] = {'\0'};
	int ch;
	while (1) {

		printMenu();
		printf("������ѡ����ִ�й���");
		scanf("%d", &ch);
		if (ch == 0)
			return 0;
		system("cls");
		switch (ch) {
			case 1:
				StrGet(s);
				break;
			case 2:
				StrPut(s);
				break;
			case 3:
				printf("�ַ�������Ϊ%d.\n", StrLen(s));
				break;
			case 4: {
				char t4[N] = "";
				printf("����������Ҫ���ӵ��Ӵ�");
				scanf("%s", t4);
				StrCat(s, t4);
				printf("�µ��ַ�����%s.\n", s);
				break;
			}
			case 5: {
				char t5[N] = "";
				printf("��������Ҫ�����Ƚϵ��ַ�����\n");
				scanf("%s", t5);
				if (StrCmp(s, t5) == 0) {
					printf("�ַ���һ��\n");
				} else if (StrCmp(s, t5) == 1) {
					printf("����ֵΪ1��\n");
				} else if (StrCmp(s, t5) == -1) {
					printf("����ֵ-1��\n");
				}
				break;
			}
			case 6: {
				char t6[N] = "";
				printf("��������Ҫ�������Ƶ��ַ�����");
				scanf("%s", t6);
				StrCpy(s, t6);
				printf("���ַ�����%s.\n", s);
				break;
			}
			case 7: {
				char t7[N] = "";
				printf("��������Ҫ����������ַ�����");
				scanf("%s", t7);
				printf("��������ԭ�ַ����в����λ��");
				int pos7;
				scanf("%d", &pos7);
				StrIns(s, pos7, t7);
				printf("���ַ�����%s.\n", s);
				break;
			}
			case 8: {
				char t8[N] = "";
				int n8;
				int pos8;
				printf("��������Ҫ���ҵ��ַ�������");
				scanf("%d", &n8);
				printf("�������Ӵ���ͷλ��:");
				scanf("%d", &pos8);
				StrSub(s, pos8, n8, t8);
				printf("�Ӵ���%s.\n", t8);
				break;
			}
			case 9: {
				char t9[N] = "";
				printf("������������ҵ��ַ���");
				scanf("%s", t9);
				int flag = StrStr(s, t9);

				break;
			}
			case 10: {
				char v[N] = "";
				printf("������������ҵ��ַ���");
				scanf("%s", v);
				char t[N] = "";
				printf("�����������滻���ַ���");
				scanf("%s", t);
				StrReplace(s, v, t);
				break;
			}

		}
		system("pause");
		system("cls");
	}
}