#include <stdio.h>
#include <string.h>

int udf_strlen(char s[]) {
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}

int main() {
	char a[100][5];
	scanf("%s", a[0]);
	getchar();
	scanf("%s", a[1]);
	getchar();
	scanf("%s", a[2]);
	getchar();
	scanf("%s", a[3]);
	getchar();
	printf("%s\n", a[0]);
	printf("%s\n", a[1]);
	printf("%s\n", a[2]);
	printf("%s\n", a[3]);
	printf("%d\n", udf_strlen(a[3]));
	return 0;
}