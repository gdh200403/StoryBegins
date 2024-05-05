#include <stdio.h>
#include <string.h>

struct biaoji {
	int weizhi;
	int geshu;
};
struct biaoji bj[100];


void string_filter(char s[]) {
	int i, j, k, c;
	bj[0].weizhi = 0;
	bj[0].geshu = 0;
	for (i = 0, k = 1; s[i] != '\0'; ) {//扫描字符串
		c = 1;
		for (j = i; s[j + 1] == s[i]; j++) { //对每一个字符，扫描紧邻其之后的字符并标记和他相同的字符个数【在此“==”出错！】
			c++;//标记完成
		}
		if (c > 1) {
			bj[k].weizhi = i;//存储开始重复的字符在原字符串的位置
			bj[k].geshu = c;//存储该字符重复次数
			i += c; //【跳过重复字符，扫描之后的字符】
			k++;//将字符重复信息存入结构体数组（出循环时k会多加1）
		} else
			i++;
	}//扫描原字符串完成并将字符重复信息存入结构体数组
	for (i = 0; i < k - 1; i++) {//按重复字符的位置裁剪原字符串分段输出
		for (j = bj[i].weizhi + bj[i].geshu; j < bj[i + 1].weizhi; j++) {
			printf("%c", s[j]);//输出每个片段（不包含其之后的重复字符）
		}
		printf("%d", bj[i + 1].geshu);//输出该片段后的重复字符的重复次数
		printf("%c", s[bj[i + 1].weizhi]);//输出一个该片段后的重复字符
	}//输出至最后一处字符重复并完成对最后一处重复字符的处理
	for (i = bj[k - 1].weizhi + bj[k - 1].geshu; s[i] != '\0'; i++)
		printf("%c", s[i]);//输出最后一个片段
	return;
}

int main() {
	char a[100];
	printf("请输入字符串：\n");
	scanf("%s", a);
	printf("去除重复字符后且在重复字符前标明重复次数后的新字符串为：\n");
	string_filter(a);
	return 0;
}