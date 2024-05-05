//寻找所有的水仙花数
#include <stdio.h>

int main() {
	int a, b, c;
	for (a = 1; a <= 9; a++) {
		for (b = 0; b <= 9; b++) {
			for (c = 0; c <= 9; c++) {
				if (a * a * a + b * b * b + c * c * c == 100 * a + 10 * b + c)
					printf("%-4d", 100 * a + 10 * b + c);
			}
		}
	}
	return 0;
}