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
	printf("请输入字符串：\n");
	getString(s);
	printf("请输入待复制字符串在原字符串中的起始位置和终止位置（若复制到末尾，终止位置输入0）：\n");
	scanf("%d%d", &pos, &len);
	if (pos >= len || pos >= n || len >= n || pos <= 0 || len <= 0) {
		if (len == 0) {
			strCopy(t, s, pos, n - 1);
			printf("您复制的内容是：\n%s", t);
		} else
			printf("数据不合法！");
	} else {
		strCopy(t, s, pos, len);
		printf("您复制的内容是：\n%s", t);
	}
	return 0;
}