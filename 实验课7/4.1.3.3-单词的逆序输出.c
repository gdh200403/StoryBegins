//p172 4.1.3.3-µ¥´ÊµÄÄæĞòÊä³ö
#include <stdio.h>
#include <string.h>

int main() {
	char a[100];
	int space[50];
	int i, j = 1;
	int num;
	for (i = 0; i < 100; i++) {
		a[i] = getchar();
		if (a[i] == '\n')
			break;
	}
	space[0] = -1;
	for (i = 0; i < strlen(a); i++) {
		if (*(a + i) == ' ')
			space[j++] = i;
	}
	space[j] = i;
	num = j;
	for (i = num - 1; i >= 0; i--) {
		for (j = *(space + i) + 1; j < * (space + i + 1); j++) {
			if (a[j] == '\n');
			else
				printf("%c", *(a + j));
		}
		printf(" ");
	}
	return 0;
}