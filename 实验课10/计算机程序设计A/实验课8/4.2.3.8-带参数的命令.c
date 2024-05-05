//p179 4.2.3.8-带参数的命令
#include <stdio.h>

int main(int argc, char *argv[]) {
	char a;
	sscanf(argv[1], "-l%c", &a);
	int i;
	for (i = 2; i < argc - 1; i++) {
		if (a == 'b') {
			printf("%s", argv[i]);
			printf(" ");
		} else {
			printf("%s", argv[i]);
			printf("%c", a);
		}
	}
	printf("%s", argv[argc - 1]);
	return 0;
}