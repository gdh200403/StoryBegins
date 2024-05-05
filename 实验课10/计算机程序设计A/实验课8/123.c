#include <stdio.h>

int main() {
	char a1[5], a2[5], a3[5], a4[5], b[5];
	scanf("%s%s", a1, a2);
	gets(a3);
	gets(a4);
	b[0] = 'c';
	puts(a1);
	puts(a2);
	puts(a3);
	puts(a4);
	printf("%d", sizeof(a1));
	return 0;
}