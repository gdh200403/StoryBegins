#include <stdio.h>

int main() { //练习3：求Π的近似值
	unsigned int i, n = 100;
	unsigned int t = 1;
	float f_pi = 2.0, f_i = 1.0; //用float计算，6位小数
	double d_pi = 2.0, d_i = 1.0; //用double计算，15位小数
	long double ld_pi = 2.0, ld_i = 1.0; //用long double计算，18位小数
	printf("输入计算的迭代次数（0~4294967295）：");
	scanf("%u", & n);
	printf("选择数据类型：1-float,2- double,3=long double: ");
	scanf ("%u", &t); //填空：计算n次
	for (i = 0; i < n; i++) {
		switch (t) {
			case 1:
				f_pi *= 4.0 * f_i * f_i / (4 * f_i * f_i - 1); //float
				f_i += 1.0;
				break;
			case 2:
				d_pi *= 4.0 * d_i * d_i / (4 * d_i * d_i - 1); //double
				d_i += 1.0;
				break;
			case 3:
				ld_pi *= 4.0 * ld_i * ld_i / (4 * ld_i * ld_i - 1); //double
				ld_i += 1.0;
				break;
		}
	}
	switch (t) {
		case 1:
			printf("迭代%u次,pi近似为：%.8f\n", n, f_pi);
			break;
		case 2:
			printf("迭代%u次,pi近似为:%.16f\n", n, d_pi);
			break;
		case 3:
			printf("迭代%u次,pi近似为：%.20Lf\n", n, ld_pi);
			break;
	}
	return 0;
}