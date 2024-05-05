//p140 3.3.3.4-递归法进制转换
#include <stdio.h>
#include <math.h>

void dec2sn(int decimal, int systemNumber);//递归法进制转换函数原型声明

int main() {
	int decimal, systemNumber;
	scanf("%d%d", &decimal, &systemNumber);//输入十进制数与带转换进制
	dec2sn(decimal, systemNumber);
	return 0;
}

/*
*功能：递归法进制转换
*参数：decimal:十进制数，systemNumber:待转换进制
*返回值：无，在函数体中输出结果
*/
void dec2sn(int decimal, int systemNumber) {
	int rest;//商
	switch (systemNumber) {
		case 2:
		case 8:
			if (decimal < systemNumber)
				printf("%d", decimal);//递归调用的终点：上一轮带余除法求得商对进制数作带余除法商为0，输出上一轮余数
			else {
				rest = decimal / systemNumber;//十进制整数对进制数作带余除法求商
				dec2sn(rest, systemNumber);//本轮带余除法求得商继续对进制数作带余除法
				printf("%d", decimal % systemNumber);//在递归调用函数后输出本轮带余除法的余数，可以保证余数从后向前输出
			}
			break;
		case 16:
			if (decimal < systemNumber)
				switch (decimal) {
					case 0:
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:
					case 7:
					case 8:
					case 9:
						printf("%d", decimal);
						break;
					case 10:
						printf("A");
						break;
					case 11:
						printf("B");
						break;
					case 12:
						printf("C");
						break;
					case 13:
						printf("D");
						break;
					case 14:
						printf("E");
						break;
					case 15:
						printf("F");
						break;
				} else {
				rest = decimal / systemNumber;
				dec2sn(rest, systemNumber);
				switch (decimal % systemNumber) {
					case 0:
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:
					case 7:
					case 8:
					case 9:
						printf("%d", decimal);
						break;
					case 10:
						printf("A");
						break;
					case 11:
						printf("B");
						break;
					case 12:
						printf("C");
						break;
					case 13:
						printf("D");
						break;
					case 14:
						printf("E");
						break;
					case 15:
						printf("F");
						break;
				}

			}
			break;
		default:
			printf("ERROR!");
			break;
	}

}
