//p180 4.3.2-ָ�������ڴ�����������
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define caldate(st) ((st).pdate.yyyy*10000+\(st).pdate.mm*100+(st).pdate.dd)//��б����ʲô������

typedef struct DATE {
	int yyyy;
	int mm;
	int dd;
} DATE;

typedef struct BOOK {
	char bn[40];
	char tittle[80];
	char author[40];
	char pub[60];
	DATE pdate;
} BOOK;

BOOK *input(int *n) {
	char buff[200] = {0};
	const char delimitor[2] = "#";
	char *token;
	FILE *fp;
	BOOK *books;
	int num;
	fp = fopen("booksinfodata.txt", "r");
	if (fp == NULL) {
		printf("file open failed.\n");
		exit(0);
	}
	fscanf(fp, "%s", buff);
	num = atoi(buff);
	if (num <= 0)
		return NULL;
	*n = num;
	books = (BOOK *)malloc(num * sizeof(BOOK));
	for (int i = 0; i < num; i++) {
		fgets(buff, 200, fp);
		token = strtok(buff, delimitor);
		for (int j = 0; j < 7 && token != NULL; j++) {
			switch (j) {
				case 0:
					strcpy(books[i].bn, token);
					break;
				case 1:
					strcpy(books[i].tittle, token);
					break;
				case 2:
					strcpy(books[i].author, token);
					break;
				case 3:
					strcpy(books[i].pub, token);
					break;
				case 4:
					books[i].pdate.yyyy = atoi(token);
					break;
				case 5:
					books[i].pdate.mm = atoi(token);
					break;
				case 6:
					books[i].pdate.dd = atoi(token);
					break;
			}
			token = strtok(NULL, delimitor); //???
		}
	}
	return books;
}

void putput(BOOK books[], int n) {
	for (int i = 0; i < n; i++) {
		printf("����ţ�%s\n", books[i].bn);
		printf("������%s\n", books[i].tittle);
		printf("���ߣ�%s\n", books[i].author);
		printf("�����磺%s\n", books[i].pub);
		printf("�������ڣ�%d��%d��%d��\n\n",
		       books[i].pdate.yyyy, books[i].pdate.mm, books[i].pdate.dd);
	}
}

void save(BOOK books[], int n, char *filename) {
	FILE *fp;
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("file %s open failed.\n", filename);
		exit(0);
	}
	for (int i = 0; i < n; i++) {
		fprintf(fp, "����ţ�%s\n", books[i].bn);
		fprintf(fp, "������%s\n", books[i].tittle);
		fprintf(fp, "���ߣ�%s\n", books[i].author);
		fprintf(fp, "�����磺%s\n", books[i].pub);
		fprintf(fp, "�������ڣ�%d��%d��%d��\n\n",
		        books[i].pdate.yyyy, books[i].pdate.mm, books[i].pdate.dd);
	}
}

int comp_date(const void *b1, const void *b2) {
	int date1, date2;
	date1 = caldate(*(BOOK *)b1);
	date2 = caldate(*(BOOK *)b2);
	return (date1 - date2);
}

int comp_pubname(const void *b1, const void *b2) {
	return (strcmp(((BOOK *)b1)->pub, ((BOOK *)b2)->pub));
}

int main() {
	BOOK *books;
	int booknum;
	books = input(&booknum);
	output(books, booknum);
	qsort(books, booknum, sizeof(bookks[0]), comp_date);
	printf("\n\n-------������ʱ���Ⱥ�˳��-------\n");
	output(books, booknum);
	save(books, booknum, "booksbydate.txt");
	qsort(books, booknum, sizeof(book[0]), comp_pubname);
	printf("\n\n-------������������˳��-------\n");
	save(books, booknum, "booksbypubname.txt");
	return 0;
}