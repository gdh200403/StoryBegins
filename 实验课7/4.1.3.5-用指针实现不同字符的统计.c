//p172 4.1.3.5-��ָ��ʵ�ֲ�ͬ�ַ���ͳ��
#include <stdio.h>

int main() {
	char a[100];
	int result[6] = {0};
	int i;
	for (i = 0; i < 100; i++) {
		a[i] = getchar();
		if (a[i] == '\n')
			break;
	}
	for (i = 0; i < 100; i++) {
		if (65 <= a[i] && a[i] <= 90 || 97 <= a[i] && a[i] <= 122)
			result[1]++;
		else if (48 <= a[i] && a[i] <= 57)
			result[2]++;
		else if (a[i] == 32)
			result[3]++;
		else if (a[i] == '\0')
			break;
		else
			result[5]++;

	}
	printf("Ӣ����ĸ��%d\n", result[1]);
	printf("���֣�%d\n", result[2]);
	printf("�ո�%d\n", result[3]);
	printf("������%d\n", result[5]);
	return 0;
}
