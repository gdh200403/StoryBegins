#include <stdio.h>
#include <math.h>

struct complex {
	int real;
	int imag;
};

struct complex complexMul(struct complex c1, struct complex c2) {
	struct complex c3;
	c3.real = c1.real * c2.real - c1.imag * c2.imag;
	c3.imag = c1.real * c2.imag + c1.imag * c2.imag;
	return c3;
}

int main() {
	printf("������\n");
	struct complex c1, c2, c3;
	while (1) {
		printf("�������һ��������ʵ�����鲿��");
		scanf("%d%d", &c1.real, &c1.imag);
		printf("���������������ʵ�����鲿��");
		scanf("%d%d", &c2.real, &c2.imag);
		c3 = complexMul(c1, c2);
		if (c3.imag < 0)
			printf("%d%di\n", c3.real, c3.imag);
		else if (c3.imag > 0)
			printf("%d+%di\n", c3.real, c3.imag);
		else
			printf("%d", c3.real);
	}
}