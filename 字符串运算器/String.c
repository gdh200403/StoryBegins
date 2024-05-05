#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define      N  100

//显示菜单
void printMenu(void) {
	printf("************************************\n");
	printf("        字 符 串 运 算 器   \n");
	printf("************************************\n");
	printf("0  退出程序\n");
	printf("1  输入字符串\n");
	printf("2  输出字符串\n");
	printf("3  字符串长度\n");
	printf("4  连接字符串\n");
	printf("5  比较字符串\n");
	printf("6  字符串复制\n");
	printf("7  插入字符串\n");
	printf("8  取子串\n");
	printf("9  字串查找\n");
	printf("10 子串替换\n");
	printf("************************************\n");
}


//输入字符串
void StrGet(char *s) {
	printf("请输入字符串");
	scanf("%s", s);
}

//显示字符串
void StrPut(char *s) {
	printf("字符串如下：\n%s\n", s);
}

//求字符串长度
int StrLen(char *s) {
	int number = 0;
	char *temp_s3 = s;
	while (*temp_s3 != '\0') {
		number++;
		temp_s3++;
	}
	return number;
}

//字符串连接
void StrCat(char *s, char *t) {
	int length, i;
	length = strlen(s);
	for (i = 0; * (t + i) != '\0'; i++) {
		*(s + length + i) = *(t + i);
	}
}

//字符串比较
int StrCmp(char *str1, char *str2) {
	int ret = 0;
	while (!(ret = *(unsigned char *)str1 - * (unsigned char *)str2) && *str1) {
		str1++;
		str2++;
	}


	if (ret < 0) {
		return -1;
	} else if (ret > 0) {
		return 1;
	}
	return 0;
}


//字符串复制
void StrCpy(char *s, char *t) {
	if (t == NULL) {
		printf("字符串为空\n");
	}
	int len = strlen(t);
	int i = 0;
	while (i != (len - 1)) {
		s[i] = t[i];
		i++;
	}
	s[len] = '\0';

}

//字符串插入
char StrIns(char *s, int pos, char *t) {
	int len1 = 0, len2 = 0, i = 0;
	len1 = strlen(s);
	len2 = strlen(t);
	for (i = len1 - 1; i >= pos - 1; i--) {
		s[i + len2] = s[i];
	}
	for (i = pos - 1; i < pos - 1 + len2; i++) {
		s[i] = t[i - pos + 1];
	}
	len1 += len2;
	s[len1] = '\0';
}

//求子串
void StrSub(char *s, int pos, int n, char *t) {
	int p = 0;
	if (pos > (strlen(s) - 1) || (pos + n) > strlen(s)) {
		printf("Error.\n");
	} else {
		while (p < n) {
			t[p] = s[pos + p];
			p++;
		}
		t[n] = '\0';
	}
}

//子串查找
int StrStr(char *s, char *t) {
	int i, j, k;
	int flag = 0;
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0'; k++, j++) {
			if (t[k] != s[j]) {
				break;
			}
		}
		if (t[k] == '\0') {
			printf("%d", i);
			printf("\n");
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		printf("error\n");
		return -1;
	}
	return i;
}

int StrReplace(char *s, char *v, char *t) {
	int sLen, vLen, tLen, pos;
	char *ts = s, *tv = v, *tt = t;
	vLen = strlen(v);
	sLen = strlen(s);
	vLen = strlen(v);
	tLen = strlen(t);
	pos = StrStr(s, v);
	int delta = tLen - vLen;
	if (pos >= 0) {
		if (delta > 0) {
			for (int i = sLen; i >= pos + vLen; i--) {
				ts[i + delta] = ts[i];
			}
			ts += pos;
			for (int i = pos + vLen; i < tLen; i++) {
				ts[i] = tt[i];
			}
		} else if (delta < 0) {
			for (int i = pos + vLen; i <= sLen; i++) {
				ts[i] = ts[i + delta];
			}
			ts += pos;
			for (int i = 0; i < tLen; i++) {
				ts[i] = tt[i];
			}
		} else {
			ts += pos;
			for (int i = 0; i < tLen; i++) {
				ts[i] = tt[i];
			}
		}
	} else {
		printf("替换失败！原字符串中无相应字符串！\n");
		return -1;
	}
	StrPut(s);
	return 0;
}

int main() {
	char s[N] = {'\0'};
	int ch;
	while (1) {

		printMenu();
		printf("请输入选项以执行功能");
		scanf("%d", &ch);
		if (ch == 0)
			return 0;
		system("cls");
		switch (ch) {
			case 1:
				StrGet(s);
				break;
			case 2:
				StrPut(s);
				break;
			case 3:
				printf("字符串长度为%d.\n", StrLen(s));
				break;
			case 4: {
				char t4[N] = "";
				printf("请输入你想要连接的子串");
				scanf("%s", t4);
				StrCat(s, t4);
				printf("新的字符串是%s.\n", s);
				break;
			}
			case 5: {
				char t5[N] = "";
				printf("请输入你要用来比较的字符串：\n");
				scanf("%s", t5);
				if (StrCmp(s, t5) == 0) {
					printf("字符串一致\n");
				} else if (StrCmp(s, t5) == 1) {
					printf("返回值为1！\n");
				} else if (StrCmp(s, t5) == -1) {
					printf("返回值-1！\n");
				}
				break;
			}
			case 6: {
				char t6[N] = "";
				printf("请输入你要用来复制的字符串：");
				scanf("%s", t6);
				StrCpy(s, t6);
				printf("新字符串是%s.\n", s);
				break;
			}
			case 7: {
				char t7[N] = "";
				printf("请输入你要用来插入的字符串：");
				scanf("%s", t7);
				printf("请输入在原字符串中插入的位次");
				int pos7;
				scanf("%d", &pos7);
				StrIns(s, pos7, t7);
				printf("新字符串是%s.\n", s);
				break;
			}
			case 8: {
				char t8[N] = "";
				int n8;
				int pos8;
				printf("请输入您要查找的字符串长度");
				scanf("%d", &n8);
				printf("请输入子串开头位次:");
				scanf("%d", &pos8);
				StrSub(s, pos8, n8, t8);
				printf("子串是%s.\n", t8);
				break;
			}
			case 9: {
				char t9[N] = "";
				printf("请输入你想查找的字符串");
				scanf("%s", t9);
				int flag = StrStr(s, t9);

				break;
			}
			case 10: {
				char v[N] = "";
				printf("请输入你想查找的字符串");
				scanf("%s", v);
				char t[N] = "";
				printf("请输入你想替换的字符串");
				scanf("%s", t);
				StrReplace(s, v, t);
				break;
			}

		}
		system("pause");
		system("cls");
	}
}