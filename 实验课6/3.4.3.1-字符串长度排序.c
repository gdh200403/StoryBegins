//p145 3.4.3.1-字符串长度排序
#include <stdio.h>
#define StrLen 100//定义字符串最大长度
void udf_getString(char[], int strlength);//字符串输入函数
int udf_strlen(char s[]);//字符串长度
void udf_sort(char s[][StrLen], int strNum);//对给定数量和类型的字符串数组排序
void udf_print(char s[][StrLen], int strNum);//对给定数量的字符串输出

int main() {
	char s[100][StrLen];
	int strNum = 0;//字符串数组中字符串总个数
	int i = 0;
	do {
		printf("请输入字符串%d(输入Ctrl+Z+Enter+Enter结束输入)：\n", i + 1);
		udf_getString(s[i], StrLen);
		i++;
	} while (udf_strlen(s[i - 1]) != 0);//用do-while输输入至少一个字符串
	strNum = i - 1;//！！！！！！！！！！！！！！不懂，实测正常输出需要-1，理论应是i
	udf_sort(s, strNum);//数组（包括字符串）作实参时，形参中有几个中括号实参数组就少写几个中括号
	udf_print(s, strNum);
	return 0;
}

/*
*功能：字符串输入
*参数：a[]:待输入的空字符串，strlength:字符串最大长度
*返回值：无
*/
void udf_getString(char a[], int strlength) {
	int i;
loop:
	scanf("%s", a);
	getchar();//字符串输入
	if (udf_strlen(a) >= strlength) {
		printf("超长！请重新输入:\n");//字符串超长处理
		for (i = 0; i < strlength; i++) {
			a[i] = '\0';
		}//清空超长字符串（其实不是清空，反而填满了'\0'，但保证这个字符串被再赋值后可以被正确输出
		goto loop;//重新输入
	}
	return;
}

/*
*功能：获取字符串长度
*参数：s[]：待获取长度字符串
*返回值：字符串长度
*/
int udf_strlen(char s[]) {
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}

/*
*功能：对给定数量和类型的字符串数组排序
*参数：s[][StrLen]:待排序字符串数组；strNum:待排序字符串数组中字符串的数量
*返回值：无，直接对数组进行操作
*/
void udf_sort(char s[][StrLen], int strNum) {
	char a[StrLen];
	int i, j, k;
	for (i = 0; i < strNum; i++) {
		for (j = i; j > 0; j--) {
			if (udf_strlen(s[j]) < udf_strlen(s[j - 1])) {
				for (k = 0; k < StrLen; k++) {
					a[k] = s[j][k];
					s[j][k] = s[j - 1][k];
					s[j - 1][k] = a[k];
				}
			}
		}
	}//按字符串长度进行插入排序
	return;
}

/*
*功能：输出字符串
*参数：废话
*返回值：废话
*/
void udf_print(char s[][StrLen], int strNum) {
	int i;
	printf("排序结果：\n");
	for (i = 0; i < strNum; i++) {
		printf("%s\n", s[i]);
	}//输出
	return;
}