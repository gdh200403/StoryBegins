//p142 3.3.3.7-标识符判别
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int panduan(char a[]);//判断标识符是否合法及是哪种违法情况的函数原型声明

int main() {
	char a[100];
	printf("请输入16字节以下字符串：\n");
	scanf("%s", a);
	if (panduan(a) == 1)
		printf("生成长度为%d的标识符%s", strlen(a), a);
	else if (panduan(a) == 2)
		printf("字符串过长！");
	else if (panduan(a) == 3)
		printf("您输入的第一个字符不是字母或下划线！");
	else if (panduan(a) == 0)
		printf("输入不合法！");
	return 0;
}

/*
*功能：判断标识符是否合法及是哪种违法情况
*参数：a[],待审核字符串
*返回值：1.合法；2.字符串过长；3.输入的第一个字符不是字母或下划线；0.其他不合法
*/
int panduan(char a[]) {
	int flag = 0, i;//循环变量，开关变量
	if (strlen(a) > 16)
		return 2;//先检查字符串长度，用<string.h>的strlen函数
	else {
		if (a[0] >= 'a' && a[0] <= 'z' || a[0] >= 'A' && a[0] <= 'Z' || a[0] == 95) {//检查首位是否为字母或下划线
			for (i = 1; i < strlen(a); i++) {
				if (isalnum(a[i]) == 0)//用<ctype.h>的isalnum()函数逐个检查字符是否为字母或数字（是则返回非零值，否则返回0）
					flag++;
			}
			if (flag == 0)
				return 1;
			else
				return 0;
		} else
			return 3;
	}
}