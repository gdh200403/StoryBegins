//p173 4.1.3.7-È¤Î¶ÊýÁÐ
#include <stdio.h>
#include <string.h>
char *quweishulie(int n);

int main() {
	int n;
	scanf("%d", &n);
	printf("%s", quweishulie(n));
	return 0;
}

char *quweishulie(int n) {
	if (n == 1)
		return "1";
	if (n > 1) {
		int i, count = 1, j = 0;
		char a[100];
		char *p = quweishulie(n - 1);
		for (i = 0; i < strlen(quweishulie(n - 1)); i++) {
			if (*(p + i) == *(p + i + 1))
				count++;
			else {
				a[j++] = count + 48;
				a[j++] = *(p + i);
				count = 1;
			}
		}
		a[j] = '\0';
		static char b[100];
		strcpy(b, a);
		return b;
	}
}