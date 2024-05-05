//p192 4.3.3.7-比较两个文本文件是否相同
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc < 3) {
		// 如果参数不够，打印用法信息并退出
		printf("Usage: %s file1 file2\n", argv[0]);
		return 1;
	}

	// 打开两个文件
	FILE *file1 = fopen(argv[1], "r");
	FILE *file2 = fopen(argv[2], "r");
	if (file1 == NULL || file2 == NULL) {
		// 如果有文件打开失败，打印错误信息并退出
		printf("Failed to open file(s)!\n");
		return 1;
	}

	int pos = 0; // 记录当前比较到了第几个字符
	int c1, c2; // 记录两个文件当前读取的字符
	while ((c1 = fgetc(file1)) != EOF && (c2 = fgetc(file2)) != EOF) {
// 计算比较到了第几个字符
		pos++;
// 如果比较结果不同，输出第一个不同字符的字节位置并退出
		if (c1 != c2) {
			printf("Different at position %d!\n", pos);
			break;
		}
	}

// 如果两个文件内容完全相同，输出 "相同"
	if (c1 == EOF && c2 == EOF) {
		printf("相同\n");
	}

// 关闭文件
	fclose(file1);
	fclose(file2);
	return 0;
}
