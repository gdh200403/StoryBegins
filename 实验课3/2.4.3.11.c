#include <stdio.h>

int main() {
	int i, j, k;//循环变量
	int bg;//背包容量
	int n;//物品数量
	float x;//已用容量
	float value;//总价值
	float weight_;//第三个问题中的重量小尾巴
	float value_;//第三个问题中的价值小尾巴
	struct objct { //定义结构体，这里在不使用模块化程序设计的情况下，其实和定义多个数组没有区别
		int no;//编号
		float wt;//重量
		float vl;//价值
		float vlp;//单位重量价值
	};
	printf("输入背包的容量：");
	scanf("%d", &bg);
	printf("输入物品的数量(3~10)：");
	scanf("%d", &n);
	struct objct objct[n];//定义n个物体
	printf("输入%d个物品的编号：", n);
	for (i = 0; i < n; i++)
		scanf("%d", &objct[i].no);
	printf("输入%d个物品的重量：", n);
	for (i = 0; i < n; i++)
		scanf("%f", &objct[i].wt);
	printf("输入%d个物品的价值：", n);
	for (i = 0; i < n; i++)
		scanf("%f", &objct[i].vl);
	for (i = 0; i < n; i++)
		objct[i].vlp = objct[i].vl / objct[i].wt;
//存储各项信息到结构体
	printf("0-1背包问题的按价值贪心法求解：\n");
	for (i = 0; i < n; i++) {
		for (j = i; j > 0; j--) {
			if (objct[j].vl > objct[j - 1].vl)
				;
			else {
				objct[j].vl += objct[j - 1].vl;
				objct[j - 1].vl = objct[j].vl - objct[j - 1].vl;
				objct[j].vl = objct[j].vl - objct[j - 1].vl;
				objct[j].no += objct[j - 1].no;
				objct[j - 1].no = objct[j].no - objct[j - 1].no;
				objct[j].no = objct[j].no - objct[j - 1].no;
				objct[j].wt += objct[j - 1].wt;
				objct[j - 1].wt = objct[j].wt - objct[j - 1].wt;
				objct[j].wt = objct[j].wt - objct[j - 1].wt;
				objct[j].vlp += objct[j - 1].vlp;
				objct[j - 1].vlp = objct[j].vlp - objct[j - 1].vlp;
				objct[j].vlp = objct[j].vlp - objct[j - 1].vlp;
			}
		}
	}//根据价值从小到大对各个物体排序
	for (i = n - 1, x = 0; i >= 0; i--) {
		if (bg - x >= objct[i].wt) {
			x += objct[i].wt, value += objct[i].vl;
			printf("%d号物品 重量：%.6f 价值：%.6f 装入背包\n",
			       objct[i].no, objct[i].wt, objct[i].vl);
		}
	}
	printf("装入背包的物品总价值为%.6f\n", value);
//0-1背包问题的按价值贪心法求解
	printf("0-1背包问题的按单位价值贪心法求解：\n");
	for (i = 0; i < n; i++) {
		for (j = i; j > 0; j--) {
			if (objct[j].vlp > objct[j - 1].vlp)
				;
			else {
				objct[j].vl += objct[j - 1].vl;
				objct[j - 1].vl = objct[j].vl - objct[j - 1].vl;
				objct[j].vl = objct[j].vl - objct[j - 1].vl;
				objct[j].no += objct[j - 1].no;
				objct[j - 1].no = objct[j].no - objct[j - 1].no;
				objct[j].no = objct[j].no - objct[j - 1].no;
				objct[j].wt += objct[j - 1].wt;
				objct[j - 1].wt = objct[j].wt - objct[j - 1].wt;
				objct[j].wt = objct[j].wt - objct[j - 1].wt;
				objct[j].vlp += objct[j - 1].vlp;
				objct[j - 1].vlp = objct[j].vlp - objct[j - 1].vlp;
				objct[j].vlp = objct[j].vlp - objct[j - 1].vlp;
			}
		}
	}//根据单位价值从小到大对各个物体排序
	for (i = n - 1, x = 0, value = 0; i >= 0; i--) {
		if (bg - x >= objct[i].wt) {
			x += objct[i].wt, value += objct[i].vl;
			printf("%d号物品 重量：%.6f 价值：%.6f,单位价值：%.6f,装入背包\n",
			       objct[i].no, objct[i].wt, objct[i].vl, objct[i].vlp);
		}
	}
	printf("装入背包的物品总价值为%.6f\n", value);
//0-1背包问题的按单位价值贪心法求解
	printf("部分背包问题的按单位价值贪心法求解：\n");
	for (i = n - 1, x = 0, value = 0; i >= 0; i--) {
		if (bg - x > 0) {
			if (bg - x >= objct[i].wt) {
				x += objct[i].wt, value += objct[i].vl;
				printf("%d号物品 重量：%.6f 价值：%.6f,单位价值：%.6f,装入背包\n",
				       objct[i].no, objct[i].vl, objct[i].vlp);
			} else {
				weight_ = bg - x;
				x = bg;
				value_ = weight_ * objct[i].vlp;
				value += value_;
				printf("%d号物品 重量：%.2f 价值：%.2f,单位价值：%.2f,其中%.2f重价值%.2f装入背包\n",
				       objct[i].no, objct[i].wt, objct[i].vl, objct[i].vlp, weight_, value_);
			}
		}
	}
	printf("装入背包的物品总价值为%.6f\n", value);
//部分背包问题的按单位价值贪心法求解
	return 0;
}