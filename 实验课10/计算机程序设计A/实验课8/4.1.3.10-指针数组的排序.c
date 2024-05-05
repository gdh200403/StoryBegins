//p174 4.1.3.10-指针数组的排序
#include <stdio.h>
#include <string.h>

int main() {
	char countries[10][40];
	char *p1[10], *p2[10];
	int i, j;
	for (i = 0; i < 10; i++) {
		gets(countries[i]);
	}
	for (i = 0; i < 10; i++) {
		p1[i] = countries[i];
		p2[i] = countries[i];
	}
	printf("\n");
	char *temp;
	for (i = 1; i < 10; i++) {
		for (j = i; j > 0; j--) {
			if (strlen(p1[j]) < strlen(p1[j - 1])) {
				temp = p1[j];
				p1[j] = p1[j - 1];
				p1[j - 1] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%s\n", p1[i]);
	}
	printf("\n");
	for (i = 1; i < 10; i++) {
		for (j = i; j > 0; j--) {
			if (*p2[j] < *p2[j - 1]) {
				temp = p2[j];
				p2[j] = p2[j - 1];
				p2[j - 1] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%s\n", p2[i]);
	}
	return 0;
}