#include <stdio.h>
#include <string.h>
int n;

void getString(char s[]) {
	scanf("%s", s);
	int i;
	for (i = 0;; i++) {
		if (s[i] == '\0') {
			n = i + 1;
			break;
		}
	}
}

void strCopy(char t[], char s[], int pos, int len) {
	int i;
	for (i = pos; i <= len; i++) {
		t[i - pos] = s[i - 1];
	}
}

int main() {
	char s[100], t[100];
	int pos, len;
	printf("�������ַ�����\n");
	getString(s);
	printf("������������ַ�����ԭ�ַ����е���ʼλ�ú���ֹλ�ã������Ƶ�ĩβ����ֹλ������0����\n");
	scanf("%d%d", &pos, &len);
	if (pos >= len || pos >= n || len >= n || pos <= 0 || len <= 0) {
		if (len == 0) {
			strCopy(t, s, pos, n - 1);
			printf("�����Ƶ������ǣ�\n%s", t);
		} else
			printf("���ݲ��Ϸ���");
	} else {
		strCopy(t, s, pos, len);
		printf("�����Ƶ������ǣ�\n%s", t);
	}
	return 0;
}