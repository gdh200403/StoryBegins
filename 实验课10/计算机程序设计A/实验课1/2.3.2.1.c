#include <stdio.h>

int main() { //��ϰ3���󦰵Ľ���ֵ
	unsigned int i, n = 100;
	unsigned int t = 1;
	float f_pi = 2.0, f_i = 1.0; //��float���㣬6λС��
	double d_pi = 2.0, d_i = 1.0; //��double���㣬15λС��
	long double ld_pi = 2.0, ld_i = 1.0; //��long double���㣬18λС��
	printf("�������ĵ���������0~4294967295����");
	scanf("%u", & n);
	printf("ѡ���������ͣ�1-float,2- double,3=long double: ");
	scanf ("%u", &t); //��գ�����n��
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
			printf("����%u��,pi����Ϊ��%.8f\n", n, f_pi);
			break;
		case 2:
			printf("����%u��,pi����Ϊ:%.16f\n", n, d_pi);
			break;
		case 3:
			printf("����%u��,pi����Ϊ��%.20Lf\n", n, ld_pi);
			break;
	}
	return 0;
}