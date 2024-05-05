//p186 4.3.3.1取字符串的子串
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *substring(const char *str, int m, int n);

int main() {
	char str[] = "abcdefghi";
	int m = 2, n = 5;

	char *substr = substring(str, m, n);
	if (substr == NULL) {
		printf("Invalid range!\n");
		return 1;
	}

	printf("The substring is: %s\n", substr);

	free(substr);

	return 0;
}

char *substring(const char *str, int m, int n) {
	int len = strlen(str);
	if (m < 1 || m > n || n > len) {
		return NULL;
	}
	char *substr = malloc(sizeof(char) * (n - m + 2));
	strncpy(substr, str + m - 1, n - m + 1);
	substr[n - m + 1] = '\0';

	return substr;
}
