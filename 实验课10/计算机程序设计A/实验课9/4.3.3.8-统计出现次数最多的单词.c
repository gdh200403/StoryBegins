//p192 4.3.3.8-ͳ�Ƴ��ִ������ĵ���
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 100  // ���嵥���������
#define MAX_WORD_LENGTH 100  // ���嵥����󳤶�

// �ṹ�壬���ڴ洢���ʼ�����ִ���
struct WordCounter {
	char word[MAX_WORD_LENGTH];  // ����
	int count;  // ���ʳ��ִ���
};

// ����ȽϺ��������ڰ��ճ��ִ����Ӷൽ������
int compare_by_count(const void *a, const void *b) {
	struct WordCounter *wa = (struct WordCounter *)a;
	struct WordCounter *wb = (struct WordCounter *)b;
	return wb->count - wa->count;
}

int main() {
	char line[MAX_WORDS * MAX_WORD_LENGTH] = {0};  // ���ڴ洢������ı�
	struct WordCounter words[MAX_WORDS] = {0};  // ���ڴ洢���ʼ�����ִ���
	int num_words = 0;  // ���ڴ洢��������

	// ���ļ�
	FILE *fp = fopen("text.txt", "r");
	if (fp == NULL) {
		printf("�ļ���ʧ�ܣ�\n");
		return 1;
	}

	// ��ȡ�ı�
	while (fgets(line, sizeof(line), fp) != NULL) {
		// �����ı�����ȡ����
		char *p = strtok(line, " ,.!?\n");  // ʹ�÷ָ�����ȡ����
		while (p != NULL) {
			int found = 0;
			// ���Ե��ʵĴ�Сд
			for (int i = 0; i < strlen(p); i++) {
				p[i] = tolower(p[i]);
			}
// ͳ�Ƶ��ʳ��ִ���
			for (int i = 0; i < num_words; i++) {

				if (strcmp(words[i].word, p) == 0) {
					// ��������Ѿ����ڣ�������ִ����� 1
					words[i].count++;
					found = 1;
					break;
				}
			}

			if (!found) {
				// ������ʲ����ڣ�������ӵ�����������
				strcpy(words[num_words].word, p);
				words[num_words].count = 1;
				num_words++;
			}

// ��ȡ��һ������
			p = strtok(NULL, " ,.!?");
		}
	}

// �Ե��������������
	qsort(words, num_words, sizeof(struct WordCounter), compare_by_count);

// ������ִ�������ǰʮ�����ʼ�����ִ���
	printf("���ִ������ĵ��ʣ�\n");
	for (int i = 0; i < 10 && i < num_words; i++) {
		printf("%s %d\n", words[i].word, words[i].count);
	}

// �ر��ļ�
	fclose(fp);

	return 0;
}
