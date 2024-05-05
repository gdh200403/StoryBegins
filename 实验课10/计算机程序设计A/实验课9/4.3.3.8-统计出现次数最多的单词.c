//p192 4.3.3.8-统计出现次数最多的单词
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 100  // 定义单词最大数量
#define MAX_WORD_LENGTH 100  // 定义单词最大长度

// 结构体，用于存储单词及其出现次数
struct WordCounter {
	char word[MAX_WORD_LENGTH];  // 单词
	int count;  // 单词出现次数
};

// 定义比较函数，用于按照出现次数从多到少排序
int compare_by_count(const void *a, const void *b) {
	struct WordCounter *wa = (struct WordCounter *)a;
	struct WordCounter *wb = (struct WordCounter *)b;
	return wb->count - wa->count;
}

int main() {
	char line[MAX_WORDS * MAX_WORD_LENGTH] = {0};  // 用于存储输入的文本
	struct WordCounter words[MAX_WORDS] = {0};  // 用于存储单词及其出现次数
	int num_words = 0;  // 用于存储单词数量

	// 打开文件
	FILE *fp = fopen("text.txt", "r");
	if (fp == NULL) {
		printf("文件打开失败！\n");
		return 1;
	}

	// 读取文本
	while (fgets(line, sizeof(line), fp) != NULL) {
		// 处理文本，提取单词
		char *p = strtok(line, " ,.!?\n");  // 使用分隔符提取单词
		while (p != NULL) {
			int found = 0;
			// 忽略单词的大小写
			for (int i = 0; i < strlen(p); i++) {
				p[i] = tolower(p[i]);
			}
// 统计单词出现次数
			for (int i = 0; i < num_words; i++) {

				if (strcmp(words[i].word, p) == 0) {
					// 如果单词已经存在，则将其出现次数加 1
					words[i].count++;
					found = 1;
					break;
				}
			}

			if (!found) {
				// 如果单词不存在，则将其添加到单词数组中
				strcpy(words[num_words].word, p);
				words[num_words].count = 1;
				num_words++;
			}

// 提取下一个单词
			p = strtok(NULL, " ,.!?");
		}
	}

// 对单词数组进行排序
	qsort(words, num_words, sizeof(struct WordCounter), compare_by_count);

// 输出出现次数最多的前十个单词及其出现次数
	printf("出现次数最多的单词：\n");
	for (int i = 0; i < 10 && i < num_words; i++) {
		printf("%s %d\n", words[i].word, words[i].count);
	}

// 关闭文件
	fclose(fp);

	return 0;
}
